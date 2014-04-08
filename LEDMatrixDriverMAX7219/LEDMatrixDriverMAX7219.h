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

class LEDMatrixDriverMAX7219 : public LEDMatrixDriver {

	unsigned char dataPin;
	unsigned char clockPin;
	unsigned char loadPin;

	unsigned char matrixData[8];

public:

	enum MAX7219Registers {

	};

	LEDMatrixDriverMAX7219(unsigned char cols, unsigned char rows,
			unsigned char dataPin, unsigned char clockPin, unsigned char loadPin);

	/**
	 *
	 */
	virtual void setLed(unsigned char col, unsigned char row, unsigned char value);

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
	virtual void shiftLed(unsigned char col, unsigned char row, unsigned char direction);

	/**
	 *
	 */
	virtual void shiftRow(unsigned char row, unsigned char direction);

	/**
	 *
	 */
	virtual void switchLeds(unsigned char colFrom, unsigned char rowFrom, unsigned char colTo, unsigned char rowTo);

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
	virtual void invertCol(unsigned char col);

	/**
	 *
	 */
	virtual void invertRows(unsigned char row);

private:

	void sendPackage(unsigned int package);

	unsigned int createPackage(unsigned char data, unsigned char reg);
};

#endif /* __ARDUINO_DRIVER_LED_MATRIX_MAX7219_H__ */
