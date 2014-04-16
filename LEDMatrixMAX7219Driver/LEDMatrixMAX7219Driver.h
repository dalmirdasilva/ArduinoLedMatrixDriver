/**
 * Arduino - LED Matrix MAX7219 driver
 *
 * LEDMatrixDriverMAX7219.h
 *
 * LED Matrix MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_MAX7219_H__
#define __ARDUINO_DRIVER_LED_MATRIX_MAX7219_H__ 1

#include <LEDMatrixDriver.h>
#include <MAX7219Driver.h>

#define MATRIX_WIDTH 8
#define MATRIX_HEIGHT 8

class LEDMatrixMAX7219Driver : public LEDMatrixDriver {

    MAX7219Driver *driver;

    unsigned char matrixData[MATRIX_WIDTH];
    static unsigned char registerMap[MATRIX_WIDTH];

public:

    ~LEDMatrixMAX7219Driver() {
    }

    LEDMatrixMAX7219Driver(MAX7219Driver *driver, unsigned char cols,
            unsigned char rows);

    /**
     *
     */
    virtual void setLed(unsigned char col, unsigned char row,
            unsigned char value);

    /**
     *
     */
    virtual void setRow(unsigned char row, unsigned char value);

    /**
     *
     */
    virtual void setCol(unsigned char col, unsigned char value);

    /**
     *
     */
    virtual void shiftLed(unsigned char col, unsigned char row,
            unsigned char direction);

    /**
     *
     */
    virtual void shiftRow(unsigned char row, unsigned char direction);

    /**
     *
     */
    virtual void switchLeds(unsigned char colFrom, unsigned char rowFrom,
            unsigned char colTo, unsigned char rowTo);

    /**
     *
     */
    virtual void switchCols(unsigned char colFrom, unsigned char colTo);

    /**
     *
     */
    virtual void switchRows(unsigned char rowFrom, unsigned char rowTo);

    /**
     *
     */
    virtual void invertLed(unsigned char col, unsigned char row);

    /**
     *
     */
    virtual void invertCols(unsigned char col);

    /**
     *
     */
    virtual void invertRows(unsigned char row);
};

#endif /* __ARDUINO_DRIVER_LED_MATRIX_MAX7219_H__ */
