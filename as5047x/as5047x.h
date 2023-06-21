/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef CATIE_SIXTRON_AS5047X_H_
#define CATIE_SIXTRON_AS5047X_H_

#include "mbed.h"

namespace sixtron {

class AS5047x {
public:
    AS5047x(SPI *spiAS5047p, PinName sensor_spi_select);

    uint16_t getValue();

private:
    SPI *_spi;
    DigitalOut _spi_cs;
};

} // namespace sixtron

#endif // CATIE_SIXTRON_AS5047X_H_
