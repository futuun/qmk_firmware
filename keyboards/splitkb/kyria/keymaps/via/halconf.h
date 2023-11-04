#pragma once

// To enable I2C, modify your board's `halconf.h` to enable I2C:
#define HAL_USE_I2C TRUE

// To enable bluetooth
#define HAL_USE_ADC TRUE

#include_next <halconf.h>
