#include <MAX7219Driver.h>
#include <LEDMatrixDriver.h>
#include <LEDMatrixMAX7219Driver.h>

void setup() {

    Serial.begin(9600);
    Serial.println("Ready.");
    randomSeed(analogRead(0));
    
    MAX7219Driver driver(12, 11, 10);
    LEDMatrixMAX7219Driver matrix(&driver, 8, 8);
   
    char row, col;
    while (true) {
        row = random(0, 7);
        col = random(0, 7);
        matrix.setLed(row, col, 1);
        delay(100);
        matrix.setLed(row, col, 0);
        delay(100);
    }
}

void loop() {
}