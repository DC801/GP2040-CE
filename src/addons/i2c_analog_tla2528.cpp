#include "addons/i2c_analog_tla2528.h"

I2CAnalogTLA2528::I2CAnalogTLA2528(){

}

void I2CAnalogTLA2528::test(){
    PeripheralI2C* i2c = PeripheralManager::getInstance().getI2C(0);
    adc = new TLA2528(i2c, 0x10);
    adc->send_test_message();
}