/**
 * Arduino - LED Matrix driver
 * 
 * LEDMatrixDriver.h
 * 
 * LED Matrix Driver.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_LED_MATRIX_H__
#define __ARDUINO_DRIVER_LED_MATRIX_H__ 1

class LEDMatrixDriver {

protected:
	unsigned char cols;
	unsigned char rows;

public:

	enum LedValue {
		ON = 0x00,
		OFF = 0x01,
		RED = 0x02,
		GREEN = 0x04
	};

	enum RowShiftDirection {
		LEFT = 0x00,
		RIGHT = 0x01
	};

	enum ColShiftDirection {
		UP = 0x00,
		DOWN = 0x01
	};

    /**
     *
     */
    virtual ~LEDMatrixDriver();

	/**
	 *
	 */
	LEDMatrixDriver(unsigned char cols, unsigned char rows);

	/**
	 *
	 */
	virtual unsigned char isOutOfBounds(unsigned char col, unsigned char row);

	/**
	 *
	 */
	virtual void setLed(unsigned char col, unsigned char row, unsigned char value) = 0;

	/**
	 *
	 */
	virtual void setRow(unsigned char row, unsigned char value) = 0;

	/**
	 *
	 */
	virtual void setCol(unsigned char col, unsigned char value) = 0;

	/**
	 *
	 */
	virtual void shiftLed(unsigned char col, unsigned char row, unsigned char direction) = 0;

	/**
	 *
	 */
	virtual void shiftRow(unsigned char row, unsigned char direction) = 0;

	/**
	 *
	 */
	virtual void switchLeds(unsigned char colFrom, unsigned char rowFrom, unsigned char colTo, unsigned char rowTo) = 0;

	/**
	 *
	 */
	virtual void switchCols(unsigned char colFrom, unsigned char colTo) = 0;

	/**
	 *
	 */
	virtual void switchRows(unsigned char rowFrom, unsigned char rowTo) = 0;

	/**
	 *
	 */
	virtual void invertLed(unsigned char col, unsigned char row) = 0;

	/**
	 *
	 */
	virtual void invertCols(unsigned char col) = 0;

	/**
	 *
	 */
	virtual void invertRows(unsigned char row) = 0;
};

#endif /* __ARDUINO_DRIVER_LED_MATRIX_H__ */
