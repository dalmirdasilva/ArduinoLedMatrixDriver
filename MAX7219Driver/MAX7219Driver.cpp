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
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(loadPin, OUTPUT);
    digitalWrite(loadPin, HIGH);
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
    Serial.print("Sending: ");
    Serial.println(package, HEX);

    digitalWrite(loadPin, HIGH);
    shiftOut2(dataPin, clockPin, MSBFIRST, (unsigned char)((package >> 8) & 0xff));
    shiftOut2(dataPin, clockPin, MSBFIRST, (unsigned char)(package & 0xff));
    digitalWrite(loadPin, LOW);
}

unsigned int MAX7219Driver::createPackage(unsigned char data,
        unsigned char reg) {
    unsigned int package;
    package = (0x000f & reg);
    package <<= 8;
    package |= (0x00ff & data);
    return package;
}

void MAX7219Driver::shiftOut2(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
    uint8_t i;

    Serial.print(val, HEX);
    Serial.print(": [");
    for (i = 0; i < 8; i++)  {
        char v = 0;
        if (bitOrder == LSBFIRST)
            v = !!(val & (1 << i));
        else
            v = !!(val & (1 << (7 - i)));

        Serial.print(v, DEC);
        digitalWrite(dataPin, v);
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);

    }
    Serial.println(']');
}

#endif /* __ARDUINO_DRIVER_MAX7219_CPP__ */



/*/*
 *    LedControl.cpp - A library for controling Leds with a MAX7219/MAX7221
 *    Copyright (c) 2007 Eberhard Fahle
 *
 *    Permission is hereby granted, free of charge, to any person
 *    obtaining a copy of this software and associated documentation
 *    files (the "Software"), to deal in the Software without
 *    restriction, including without limitation the rights to use,
 *    copy, modify, merge, publish, distribute, sublicense, and/or sell
 *    copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following
 *    conditions:
 *
 *    This permission notice shall be included in all copies or
 *    substantial portions of the Software.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *    OTHER DEALINGS IN THE SOFTWARE.
 */


#include "LedControl.h"

//the opcodes for the MAX7221 and MAX7219
#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

LedControl::LedControl(int dataPin, int clkPin, int csPin, int numDevices) {
    SPI_MOSI=dataPin;
    SPI_CLK=clkPin;
    SPI_CS=csPin;
    if(numDevices<=0 || numDevices>8 )
    numDevices=8;
    maxDevices=numDevices;
    pinMode(SPI_MOSI,OUTPUT);
    pinMode(SPI_CLK,OUTPUT);
    pinMode(SPI_CS,OUTPUT);
    digitalWrite(SPI_CS,HIGH);
    SPI_MOSI=dataPin;
    for(int i=0;i<64;i++)
    status[i]=0x00;
    for(int i=0;i<maxDevices;i++) {
    spiTransfer(i,OP_DISPLAYTEST,0);
    //scanlimit is set to max on startup
    setScanLimit(i,7);
    //decode is done in source
    spiTransfer(i,OP_DECODEMODE,0);
    clearDisplay(i);
    //we go into shutdown-mode on startup
    shutdown(i,true);
    }
}

int LedControl::getDeviceCount() {
    return maxDevices;
}

void LedControl::shutdown(int addr, bool b) {
    if(addr<0 || addr>=maxDevices)
    return;
    if(b)
    spiTransfer(addr, OP_SHUTDOWN,0);
    else
    spiTransfer(addr, OP_SHUTDOWN,1);
}

void LedControl::setScanLimit(int addr, int limit) {
    if(addr<0 || addr>=maxDevices)
    return;
    if(limit>=0 || limit<8)
        spiTransfer(addr, OP_SCANLIMIT,limit);
}

void LedControl::setIntensity(int addr, int intensity) {
    if(addr<0 || addr>=maxDevices)
    return;
    if(intensity>=0 || intensity<16)
    spiTransfer(addr, OP_INTENSITY,intensity);

}

void LedControl::clearDisplay(int addr) {
    int offset;

    if(addr<0 || addr>=maxDevices)
    return;
    offset=addr*8;
    for(int i=0;i<8;i++) {
    status[offset+i]=0;
    spiTransfer(addr, i+1,status[offset+i]);
    }
}

void LedControl::setLed(int addr, int row, int column, boolean state) {
    int offset;
    byte val=0x00;

    if(addr<0 || addr>=maxDevices)
    return;
    if(row<0 || row>7 || column<0 || column>7)
    return;
    offset=addr*8;
    val=B10000000 >> column;
    if(state)
    status[offset+row]=status[offset+row]|val;
    else {
    val=~val;
    status[offset+row]=status[offset+row]&val;
    }
    spiTransfer(addr, row+1,status[offset+row]);
}

void LedControl::setRow(int addr, int row, byte value) {
    int offset;
    if(addr<0 || addr>=maxDevices)
    return;
    if(row<0 || row>7)
    return;
    offset=addr*8;
    status[offset+row]=value;
    spiTransfer(addr, row+1,status[offset+row]);
}

void LedControl::setColumn(int addr, int col, byte value) {
    byte val;

    if(addr<0 || addr>=maxDevices)
    return;
    if(col<0 || col>7)
    return;
    for(int row=0;row<8;row++) {
    val=value >> (7-row);
    val=val & 0x01;
    setLed(addr,row,col,val);
    }
}

void LedControl::setDigit(int addr, int digit, byte value, boolean dp) {
    int offset;
    byte v;

    if(addr<0 || addr>=maxDevices)
    return;
    if(digit<0 || digit>7 || value>15)
    return;
    offset=addr*8;
    v=charTable[value];
    if(dp)
    v|=B10000000;
    status[offset+digit]=v;
    spiTransfer(addr, digit+1,v);

}

void LedControl::setChar(int addr, int digit, char value, boolean dp) {
    int offset;
    byte index,v;

    if(addr<0 || addr>=maxDevices)
    return;
    if(digit<0 || digit>7)
    return;
    offset=addr*8;
    index=(byte)value;
    if(index >127) {
    //nothing define we use the space char
    value=32;
    }
    v=charTable[index];
    if(dp)
    v|=B10000000;
    status[offset+digit]=v;
    spiTransfer(addr, digit+1,v);
}

void LedControl::spiTransfer(int addr, volatile byte opcode, volatile byte data) {
    //Create an array with the data to shift out
    int offset=addr*2;
    int maxbytes=maxDevices*2;

    for(int i=0;i<maxbytes;i++)
    spidata[i]=(byte)0;
    //put our device data into the array
    spidata[offset+1]=opcode;
    spidata[offset]=data;
    //enable the line
    digitalWrite(SPI_CS,LOW);
    //Now shift out the data
    for(int i=maxbytes;i>0;i--)
    shiftOut(SPI_MOSI,SPI_CLK,MSBFIRST,spidata[i-1]);
    //latch the data onto the display
    digitalWrite(SPI_CS,HIGH);
}


 * */

 //We always have to include the library
 #include "LedControl.h"

 /*
  Now we need a LedControl to work with.
  ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
  We have only a single MAX72XX.
  */
 LedControl lc=LedControl(12,11,10,1);

 /* we always wait a bit between updates of the display */
 unsigned long delaytime=100;

 void setup() {
   /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
    */
   lc.shutdown(0,false);
   /* Set the brightness to a medium values */
   lc.setIntensity(0,8);
   /* and clear the display */
   lc.clearDisplay(0);
 }

 /*
  This method will display the characters for the
  word "Arduino" one after the other on the matrix.
  (you need at least 5x7 leds to see the whole chars)
  */
 void writeArduinoOnMatrix() {
   /* here is the data for the characters */
   byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
   byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
   byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
   byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
   byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
   byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
   byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

   /* now display them one by one with a small delay */
   lc.setRow(0,0,a[0]);
   lc.setRow(0,1,a[1]);
   lc.setRow(0,2,a[2]);
   lc.setRow(0,3,a[3]);
   lc.setRow(0,4,a[4]);
   delay(delaytime);
   lc.setRow(0,0,r[0]);
   lc.setRow(0,1,r[1]);
   lc.setRow(0,2,r[2]);
   lc.setRow(0,3,r[3]);
   lc.setRow(0,4,r[4]);
   delay(delaytime);
   lc.setRow(0,0,d[0]);
   lc.setRow(0,1,d[1]);
   lc.setRow(0,2,d[2]);
   lc.setRow(0,3,d[3]);
   lc.setRow(0,4,d[4]);
   delay(delaytime);
   lc.setRow(0,0,u[0]);
   lc.setRow(0,1,u[1]);
   lc.setRow(0,2,u[2]);
   lc.setRow(0,3,u[3]);
   lc.setRow(0,4,u[4]);
   delay(delaytime);
   lc.setRow(0,0,i[0]);
   lc.setRow(0,1,i[1]);
   lc.setRow(0,2,i[2]);
   lc.setRow(0,3,i[3]);
   lc.setRow(0,4,i[4]);
   delay(delaytime);
   lc.setRow(0,0,n[0]);
   lc.setRow(0,1,n[1]);
   lc.setRow(0,2,n[2]);
   lc.setRow(0,3,n[3]);
   lc.setRow(0,4,n[4]);
   delay(delaytime);
   lc.setRow(0,0,o[0]);
   lc.setRow(0,1,o[1]);
   lc.setRow(0,2,o[2]);
   lc.setRow(0,3,o[3]);
   lc.setRow(0,4,o[4]);
   delay(delaytime);
   lc.setRow(0,0,0);
   lc.setRow(0,1,0);
   lc.setRow(0,2,0);
   lc.setRow(0,3,0);
   lc.setRow(0,4,0);
   delay(delaytime);
 }

 /*
   This function lights up a some Leds in a row.
  The pattern will be repeated on every row.
  The pattern will blink along with the row-number.
  row number 4 (index==3) will blink 4 times etc.
  */
 void rows() {
   for(int row=0;row<8;row++) {
     delay(delaytime);
     lc.setRow(0,row,B10100000);
     delay(delaytime);
     lc.setRow(0,row,(byte)0);
     for(int i=0;i<row;i++) {
       delay(delaytime);
       lc.setRow(0,row,B10100000);
       delay(delaytime);
       lc.setRow(0,row,(byte)0);
     }
   }
 }

 /*
   This function lights up a some Leds in a column.
  The pattern will be repeated on every column.
  The pattern will blink along with the column-number.
  column number 4 (index==3) will blink 4 times etc.
  */
 void columns() {
   for(int col=0;col<8;col++) {
     delay(delaytime);
     lc.setColumn(0,col,B10100000);
     delay(delaytime);
     lc.setColumn(0,col,(byte)0);
     for(int i=0;i<col;i++) {
       delay(delaytime);
       lc.setColumn(0,col,B10100000);
       delay(delaytime);
       lc.setColumn(0,col,(byte)0);
     }
   }
 }

 /*
  This function will light up every Led on the matrix.
  The led will blink along with the row-number.
  row number 4 (index==3) will blink 4 times etc.
  */
 void single() {
   for(int row=0;row<8;row++) {
     for(int col=0;col<8;col++) {
       delay(delaytime);
       lc.setLed(0,row,col,true);
       delay(delaytime);
       for(int i=0;i<col;i++) {
         lc.setLed(0,row,col,false);
         delay(delaytime);
         lc.setLed(0,row,col,true);
         delay(delaytime);
       }
     }
   }
 }

 void loop() {
   writeArduinoOnMatrix();
   rows();
   columns();
   single();
 }

 */
