#include <MAX7219Driver.h>
#include <LedMatrixDriver.h>
#include <LedMatrixMAX7219Driver.h>

void blinkLed(LedMatrixMAX7219Driver *matrix, unsigned char row, unsigned char col) {
  matrix->setLed(row, col, 1);
  delay(5);
  matrix->setLed(row, col, 0);
  delay(5);
}

void turn(LedMatrixMAX7219Driver *matrix, unsigned char row, unsigned char col, unsigned char v) {
  matrix->setLed(row, col, v);
  delay(10);
}

void setup() {

    Serial.begin(9600);
    Serial.println("Ready.");

    MAX7219Driver driver(12, 11, 10);
    LedMatrixMAX7219Driver matrix(&driver, 8, 8);
    
   
    char i, k = 0;


    while (true) {
        k++;
        for (i = 0; i < 8; i++) {
            turn(&matrix, i, 0, k & 1);
        }
        for (i = 1; i < 8; i++) {
            turn(&matrix, 7, i, k & 1);
        }
        for (i = 6; i >= 0; i--) {
            turn(&matrix, i, 7, k & 1);
        }
        for (i = 6; i > 0; i--) {
            turn(&matrix, 0, i, k & 1);
        }
        
        
        for (i = 0; i < 8; i++) {
            blinkLed(&matrix, i, 0);
        }
        for (i = 1; i < 8; i++) {
            blinkLed(&matrix, 7, i);
        }
        for (i = 6; i >= 0; i--) {
            blinkLed(&matrix, i, 7);
        }
        for (i = 6; i > 0; i--) {
            blinkLed(&matrix, 0, i);
        }
    }
}

void loop() {
}