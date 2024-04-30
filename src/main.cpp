/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2024 OpenStickCommunity (gp2040-ce.info)
 */

// Pi Pico includes
#include "pico/multicore.h"

// GP2040 includes
#include "gp2040.h"
#include "gp2040aux.h"

#include <cstdlib>

// // Debug Printing via UART:
// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "hardware/uart.h"

// #define UART_ID uart1
// #define BAUD_RATE 115200
// #define UART_TX_PIN 24
// #define UART_RX_PIN 21

// // Set up our UART with the required speed.
// uart_init(UART_ID, BAUD_RATE);
// // Set the TX and RX pins by using the function select on the GPIO
// // Set datasheet for more information on function select
// gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
// gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

// // Send out a string, with CR/LF conversions
// uart_puts(UART_ID, " UART Debug Enabled!\r\n");

// Custom implementation of __gnu_cxx::__verbose_terminate_handler() to reduce binary size
namespace __gnu_cxx {
void __verbose_terminate_handler()
{
	abort();
}
}

// Launch our second core with additional modules loaded in
void core1() {
	multicore_lockout_victim_init(); // block core 1

	// Create GP2040 w/ Additional Modules for Core 1
	GP2040Aux * gp2040Core1 = new GP2040Aux();
	gp2040Core1->setup();
	gp2040Core1->run();
}

int main() {
	// Create GP2040 Main Core (core0), Core1 is dependent on Core0
	GP2040 * gp2040 = new GP2040();
	gp2040->setup();

	// Create GP2040 Thread for Core1
	multicore_launch_core1(core1);

	// Start Core0 Loop
	gp2040->run();
	return 0;
}
