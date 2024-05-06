#ifndef _I2C_ANALOG_TLA2528_H
#define _I2C_ANALOG_TLA2528_H

#include <TLA2528.h>
#include "peripheralmanager.h"


class I2CAnalogTLA2528 {
public:
    I2CAnalogTLA2528();
    void test();
private:
    TLA2528 * adc;
};

#endif // _I2C_ANALOG_TLA2528_H
