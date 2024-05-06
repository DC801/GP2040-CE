#ifndef _TLA2528_H
#define _TLA2528_H

#include "peripheral_i2c.h"

// Debug Printing via UART:
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#define UART_ID uart1
#define BAUD_RATE 115200
#define UART_RX_PIN 21
#define UART_TX_PIN 24

class TLA2528 {
  protected:
	uint8_t address;
  public:
    // Constructor 
	TLA2528(PeripheralI2C *i2cController, uint8_t addr = 0x40);
    // Methods
    void debug_init();
    void send_test_message();

  private:	
	PeripheralI2C* i2c;
	unsigned char i2c_buffer[128];
};

#endif // _TLA2528_H
