/**
 * Arduino - LED Matrix driver
 * 
 * LEDMatrixDriver.cpp
 * 
 * LED Matrix Driver.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_CPP__
#define __ARDUINO_DRIVER_LED_MATRIX_CPP__ 1

#include "LEDMatrixDriver.h"

LEDMatrixDriver::LEDMatrixDriver(unsigned char cols, unsigned char rows) {
	this->cols = cols;
	this->rows = rows;
};

unsigned char LEDMatrixDriver::isOutOfBounds(unsigned char col, unsigned char row) {
	if (col >= this->cols || row >= this->rows) {
		return false;
	}
	return true;
}

#endif /* __ARDUINO_DRIVER_LED_MATRIX_CPP__ */
