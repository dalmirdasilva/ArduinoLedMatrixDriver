/**
 * Arduino - LED Matrix MAX7219 driver
 *
 * LedMatrixDriverMAX7219.h
 *
 * LED Matrix MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_MAX7219_H__
#define __ARDUINO_DRIVER_LED_MATRIX_MAX7219_H__ 1

#include <LedMatrixDriver.h>
#include <MAX7219Driver.h>

#define MAX7219_MATRIX_WIDTH 8
#define MAX7219_MATRIX_HEIGHT 8
#define MAX7219_MATRIX_INVERT_COLUMN_ORDER 0

class LedMatrixMAX7219Driver : public LedMatrixDriver {

    MAX7219Driver *driver;

    unsigned char matrixData[MAX7219_MATRIX_WIDTH];
    static unsigned char registerMap[MAX7219_MATRIX_WIDTH];

public:

    LedMatrixMAX7219Driver(MAX7219Driver *driver, unsigned char cols,
            unsigned char rows);

    ~LedMatrixMAX7219Driver() {
    }

    /**
     *
     */
    virtual void clear();

    /**
     *
     */
    virtual void fill();

    /**
     *
     */
    virtual unsigned char getLed(unsigned char col, unsigned char row);

    /**
     *
     */
    virtual void setLed(unsigned char col, unsigned char row,
            unsigned char value);

    /**
     * TODO: BUGGED
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
    virtual void shiftCol(unsigned char col, unsigned char direction);

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
