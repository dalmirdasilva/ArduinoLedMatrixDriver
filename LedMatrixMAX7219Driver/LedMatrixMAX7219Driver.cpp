/**
 * Arduino - LED Matrix MAX7219 driver
 *
 * LedMatrixMAX7219Driver.cpp
 *
 * LED Matrix MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__
#define __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__ 1

#include "LedMatrixMAX7219Driver.h"

LedMatrixMAX7219Driver::LedMatrixMAX7219Driver(MAX7219Driver *driver,
        unsigned char cols, unsigned char rows) :
        LedMatrixDriver(cols, rows), driver(driver) {
    driver->setTestMode(MAX7219Driver::TEST_MODE_OFF);
    driver->setScanLimit(MAX7219Driver::DIGIT_UPTO_7);
    driver->setDisplayIntensity(0xff);
    driver->setDecodeMode(MAX7219Driver::NO_DECODE);
    driver->setShutdown(MAX7219Driver::NORMAL_MODE);
    driver->fill(0x00);
    for (unsigned char i = 0; i < MAX7219_MATRIX_WIDTH; i++) {
        matrixData[i] = 0x00;
    }
}

void LedMatrixMAX7219Driver::clear() {
    driver->fill(0x00);
}

void LedMatrixMAX7219Driver::fill() {
    driver->fill(0xff);
}

unsigned char LedMatrixMAX7219Driver::getLed(unsigned char col,
        unsigned char row) {
    unsigned char entry, mask;
    entry = matrixData[col];
    mask = 0x01 << row;
    return (entry & mask) ? LedMatrixDriver::ON : LedMatrixDriver::OFF;
}

/**
 * Each row is a register
 */
void LedMatrixMAX7219Driver::setLed(unsigned char col, unsigned char row,
        unsigned char value) {
    unsigned char entry, mask = 0;
    if (!isOutOfBounds(col, row)) {
        entry = matrixData[col];
        mask = 0x01 << row;
        if (value) {
            entry |= mask;
        } else {
            entry &= ~mask;
        }
        matrixData[col] = entry;
        driver->writeRegister(registerMap[col], entry);
    }
}

void LedMatrixMAX7219Driver::setRow(unsigned char row, unsigned char value) {
    if (!isOutOfBounds(0, row)) {
        for (unsigned char i = 0; i < rows; i++) {
            setLed(row, i, value);
        }
    }
}

void LedMatrixMAX7219Driver::setCol(unsigned char col, unsigned char value) {
    if (!isOutOfBounds(col, 0)) {
        matrixData[col] = value;
        driver->writeRegister(registerMap[col], value);
    }
}

void LedMatrixMAX7219Driver::shiftLed(unsigned char col, unsigned char row,
        unsigned char direction) {
    unsigned char led;
    if (!isOutOfBounds(col, row)) {
        led = getLed(col, row);
        setLed(col, row, (led ? LedMatrixDriver::OFF : LedMatrixDriver::ON));
        if (direction == LEFT) {
            col--;
        } else if (direction == RIGHT) {
            col++;
        } else if (direction == UP) {
            row++;
        } else {
            row--;
        }
        setLed((col % cols), (row % rows), (
                led ? LedMatrixDriver::ON : LedMatrixDriver::OFF));
    }
}

void LedMatrixMAX7219Driver::shiftRow(unsigned char row,
        unsigned char direction) {
    if (!isOutOfBounds(0, row)) {
        for (unsigned char i = 0; i < cols; i++) {
            shiftLed(i, row, direction);
        }
    }
}

void LedMatrixMAX7219Driver::shiftCol(unsigned char col,
        unsigned char direction) {
    if (!isOutOfBounds(col, 0)) {
        unsigned char current = matrixData[col];
        matrixData[col] = ~current;
        driver->writeRegister(registerMap[col], matrixData[col]);
        if (direction == RIGHT) {
            col++;
        } else {
            col--;
        }
        col %= cols;
        matrixData[col] = current;
        driver->writeRegister(registerMap[col], matrixData[col]);
    }
}

void LedMatrixMAX7219Driver::switchLeds(unsigned char colFrom,
        unsigned char rowFrom, unsigned char colTo, unsigned char rowTo) {
    unsigned char led = getLed(colFrom, rowFrom);
    setLed(colFrom, rowFrom, getLed(colTo, rowTo));
    setLed(colTo, rowTo, led);
}

void LedMatrixMAX7219Driver::switchCols(unsigned char colFrom,
        unsigned char colTo) {

}

void LedMatrixMAX7219Driver::switchRows(unsigned char rowFrom,
        unsigned char rowTo) {

}

void LedMatrixMAX7219Driver::invertLed(unsigned char col, unsigned char row) {

}

void LedMatrixMAX7219Driver::invertCols(unsigned char col) {

}

void LedMatrixMAX7219Driver::invertRows(unsigned char row) {

}

#if MAX7219_MATRIX_INVERT_COLUMN_ORDER == 1
unsigned char LedMatrixMAX7219Driver::registerMap[] = {MAX7219Driver::DIGIT7,
        MAX7219Driver::DIGIT6, MAX7219Driver::DIGIT5, MAX7219Driver::DIGIT4,
        MAX7219Driver::DIGIT3, MAX7219Driver::DIGIT2, MAX7219Driver::DIGIT1,
        MAX7219Driver::DIGIT0};
#else
unsigned char LedMatrixMAX7219Driver::registerMap[] = {MAX7219Driver::DIGIT0,
    MAX7219Driver::DIGIT1, MAX7219Driver::DIGIT2, MAX7219Driver::DIGIT3,
    MAX7219Driver::DIGIT4, MAX7219Driver::DIGIT5, MAX7219Driver::DIGIT6,
    MAX7219Driver::DIGIT7};
#endif /* MATRIX_COL_ORDER */

#endif /* __ARDUINO_DRIVER_LED_MATRIX_MAX7219_CPP__ */
