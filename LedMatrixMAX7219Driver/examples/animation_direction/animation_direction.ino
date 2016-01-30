#include <MAX7219Driver.h>
#include <LedMatrixDriver.h>
#include <LedMatrixMAX7219Driver.h>

MAX7219Driver driver(10, 11, 12);
LedMatrixMAX7219Driver matrix(&driver, 8, 8);

unsigned int i = 0, j = 7;

void setup() {
    matrix.clear();
    matrix.setLed(0, 0, 1);
    matrix.setLed(1, 7, 1);
    matrix.setLed(2, 0, 1);
    matrix.setLed(3, 7, 1);
    matrix.setLed(4, 0, 1);
    matrix.setLed(5, 7, 1);
    matrix.setLed(6, 0, 1);
    matrix.setLed(7, 7, 1);
}

void loop() {
    matrix.shiftLed(0, i%8, LedMatrixMAX7219Driver::UP);
    matrix.shiftLed(1, j%8, LedMatrixMAX7219Driver::DOWN);
    matrix.shiftLed(2, i%8, LedMatrixMAX7219Driver::UP);
    matrix.shiftLed(3, j%8, LedMatrixMAX7219Driver::DOWN);
    matrix.shiftLed(4, i%8, LedMatrixMAX7219Driver::UP);
    matrix.shiftLed(5, j%8, LedMatrixMAX7219Driver::DOWN);
    matrix.shiftLed(6, i%8, LedMatrixMAX7219Driver::UP);
    matrix.shiftLed(7, j%8, LedMatrixMAX7219Driver::DOWN);
    i++;
    j--;
    delay(80);
}