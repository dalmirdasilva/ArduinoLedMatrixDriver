/**
 * Arduino - LED Matrix MAX7219 driver
 *
 * LEDMatrixMAX7219Driver.cpp
 *
 * LED Matrix MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__
#define __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__ 1

#include "LEDMatrixMAX7219Driver.h"

LEDMatrixMAX7219Driver::LEDMatrixMAX7219Driver(MAX7219Driver *driver,
        unsigned char cols, unsigned char rows) :
        LEDMatrixDriver(cols, rows), driver(driver) {
    driver->setTestMode(MAX7219Driver::TEST_MODE_OFF);
    driver->setScanLimit(MAX7219Driver::DIGIT_UPTO_7);
    driver->setDisplayIntensity(0xff);
    driver->setDecodeMode(MAX7219Driver::NO_DECODE);
    driver->setShutdown(MAX7219Driver::NORMAL_MODE);
    driver->fill(0x00);
    for (unsigned char i = 0; i < MATRIX_WIDTH; i++) {
        matrixData[i] = 0x00;
    }
}

/**
 * Each row is a register
 */
void LEDMatrixMAX7219Driver::setLed(unsigned char col, unsigned char row,
        unsigned char value) {
    unsigned char entry, mask = 0;
    if (!isOutOfBounds(col, row)) {
        entry = matrixData[row];
        mask = 0x01 << col;
        if (value) {
            entry |= mask;
        } else {
            entry &= ~mask;
        }
        matrixData[row] = entry;
        driver->writeRegister(registerMap[row], entry);
    }
}

void LEDMatrixMAX7219Driver::setRow(unsigned char row, unsigned char value) {
    if (!isOutOfBounds(0, row)) {
        matrixData[row] = value;
        driver->writeRegister(1, 0xff);
        Serial.println(registerMap[row]);
        Serial.println(matrixData[row]);
    }

}

void LEDMatrixMAX7219Driver::setCol(unsigned char col, unsigned char value) {
    if (!isOutOfBounds(col, 0)) {
        for (unsigned char i = 0; i < rows; i++) {
            setLed(col, i, value);
        }
    }
}

void LEDMatrixMAX7219Driver::shiftLed(unsigned char col, unsigned char row,
        unsigned char direction) {

}

void LEDMatrixMAX7219Driver::shiftRow(unsigned char row,
        unsigned char direction) {

}

void LEDMatrixMAX7219Driver::switchLeds(unsigned char colFrom,
        unsigned char rowFrom, unsigned char colTo, unsigned char rowTo) {

}

void LEDMatrixMAX7219Driver::switchCols(unsigned char colFrom,
        unsigned char colTo) {

}

void LEDMatrixMAX7219Driver::switchRows(unsigned char rowFrom,
        unsigned char rowTo) {

}

void LEDMatrixMAX7219Driver::invertLed(unsigned char col, unsigned char row) {

}

void LEDMatrixMAX7219Driver::invertCols(unsigned char col) {

}

void LEDMatrixMAX7219Driver::invertRows(unsigned char row) {

}

unsigned char LEDMatrixMAX7219Driver::registerMap[] = {MAX7219Driver::DIGIT0,
        MAX7219Driver::DIGIT1, MAX7219Driver::DIGIT2, MAX7219Driver::DIGIT3,
        MAX7219Driver::DIGIT4, MAX7219Driver::DIGIT5, MAX7219Driver::DIGIT6,
        MAX7219Driver::DIGIT7};

#endif /* __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__ */
