/**
 * Arduino - MAX7219 driver
 *
 * MAX7219Driver.cpp
 *
 * MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_MAX7219_CPP__
#define __ARDUINO_DRIVER_MAX7219_CPP__ 1

#include "MAX7219Driver.h"

MAX7219Driver::MAX7219Driver(unsigned char dataPin, unsigned char clockPin,
        unsigned char loadPin) {
    this->dataPin = dataPin;
    this->clockPin = clockPin;
    this->loadPin = loadPin;
    pinMode(this->dataPin, OUTPUT);
    pinMode(this->clockPin, OUTPUT);
    pinMode(this->loadPin, OUTPUT);
    digitalWrite(this->loadPin, HIGH);
}

void MAX7219Driver::setShutdown(unsigned char value) {
    unsigned int package = createPackage(value, SHUTDOWN);
    sendPackage(package);
}

void MAX7219Driver::setDecodeMode(unsigned char mode) {
    unsigned int package = createPackage(mode, DECODE_MODE);
    sendPackage(package);
}

void MAX7219Driver::setDisplayIntensity(unsigned char intensity) {
    unsigned int package = createPackage(intensity, INTENSITY);
    sendPackage(package);
}

void MAX7219Driver::setScanLimit(unsigned char scanLimit) {
    unsigned int package = createPackage(scanLimit, SCAN_LIMIT);
    sendPackage(package);
}

void MAX7219Driver::setTestMode(unsigned char test) {
    unsigned int package = createPackage(test, DISPLAY_TEST);
    sendPackage(package);
}

void MAX7219Driver::sendPackage(unsigned int package) {
    digitalWrite(this->loadPin, LOW);
    shiftOut(this->dataPin, this->clockPin, MSBFIRST, package & 0xffff);
    digitalWrite(this->loadPin, HIGH);
}

unsigned int MAX7219Driver::createPackage(unsigned char data,
        unsigned char reg) {
    unsigned int package;
    package = (0x000f & reg);
    package <<= 8;
    package |= (0x00ff & data);
    return package;
}

#endif /* __ARDUINO_DRIVER_MAX7219_CPP__ */
