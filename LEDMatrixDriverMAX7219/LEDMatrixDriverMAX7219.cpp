/**
 * Arduino - LED Matrix MAX7219 driver
 *
 * LEDMatrixDriverMAX7219.cpp
 *
 * LED Matrix MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__
#define __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__ 1

#include "LEDMatrixDriverMAX7219.h"

LEDMatrixDriverMAX7219::LEDMatrixDriverMAX7219(unsigned char cols, unsigned char rows,
			unsigned char dataPin, unsigned char clockPin, unsigned char loadPin) :
			LEDMatrixDriver(8, 8) {
	this->dataPin = dataPin;
	this->clockPin = clockPin;
	this->loadPin = loadPin;
}

void LEDMatrixDriverMAX7219::setLed(unsigned char col, unsigned char row, unsigned char value) {

}

void LEDMatrixDriverMAX7219::setRow(unsigned char row, unsigned char value) {

}

void LEDMatrixDriverMAX7219::setCol(unsigned char col, unsigned char value) {

}

void LEDMatrixDriverMAX7219::shiftLed(unsigned char col, unsigned char row, unsigned char direction) {

}

void LEDMatrixDriverMAX7219::shiftRow(unsigned char row, unsigned char direction) {

}

void LEDMatrixDriverMAX7219::switchLeds(unsigned char colFrom, unsigned char rowFrom, unsigned char colTo, unsigned char rowTo) {

}

void LEDMatrixDriverMAX7219::switchCols(unsigned char colFrom, unsigned char colTo) {

}

void LEDMatrixDriverMAX7219::switchRows(unsigned char rowFrom, unsigned char rowTo) {

}

void LEDMatrixDriverMAX7219::invertLed(unsigned char col, unsigned char row) {

}

void LEDMatrixDriverMAX7219::invertCol(unsigned char col) {

}

void LEDMatrixDriverMAX7219::invertRows(unsigned char row) {

}

void LEDMatrixDriverMAX7219::sendPackage(unsigned int package) {
	// shift the package to the device
}

unsigned int LEDMatrixDriverMAX7219::createPackage(unsigned char data, unsigned char reg) {
	unsigned int package;
	package = (0x00ff & reg);
	package <<= 8;
	package |= (0x00ff & data);
	return package;
}

#endif /* __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__ */
