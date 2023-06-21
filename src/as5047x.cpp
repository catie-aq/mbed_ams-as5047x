/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "as5047x/as5047x.h"

namespace sixtron {

AS5047x::AS5047x(SPI *sensor_spi, PinName sensor_spi_select):
        _spi(sensor_spi), _spi_cs(sensor_spi_select)
{

    // configure SPI
    _spi->format(8, 1);
    _spi->frequency(1000000);

    // configure GPIO SPI selection
    _spi_cs.write(1);
}

uint16_t AS5047x::getValue()
{
    _spi_cs.write(0);
    uint8_t receivedDataH = (0x3F & _spi->write(0xFF)); // Get the first part (8bits)
    uint8_t receivedDataL = _spi->write(0xFF); // Get the second part (8bits)
    _spi_cs.write(1);
    return (uint16_t)((receivedDataH << 8)
            | (receivedDataL & 0xff)); // Combine the two parts to get a 16bitz
}

} // namespace sixtron
