/**
 * Arduino - LED Matrix driver
 * 
 * LedMatrixDriver.cpp
 * 
 * LED Matrix Driver.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_CPP__
#define __ARDUINO_DRIVER_LED_MATRIX_CPP__ 1

#include "LedMatrixDriver.h"

LedMatrixDriver::~LedMatrixDriver() {
}

LedMatrixDriver::LedMatrixDriver(unsigned char cols, unsigned char rows) {
  this->cols = cols;
  this->rows = rows;
}

unsigned char LedMatrixDriver::isOutOfBounds(unsigned char col,
    unsigned char row) {
  if (col >= this->cols || row >= this->rows) {
    return true;
  }
  return false;
}

#endif /* __ARDUINO_DRIVER_LED_MATRIX_CPP__ */
