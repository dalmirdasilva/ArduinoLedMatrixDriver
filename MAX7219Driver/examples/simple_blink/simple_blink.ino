#include <MAX7219Driver.h>

void setup() {

    Serial.begin(9600);
    Serial.println("Ready.");

    MAX7219Driver driver(A0, A1, A2);
    driver.setScanLimit(MAX7219Driver::DIGIT_UPTO_7);
    driver.setDecodeMode(MAX7219Driver::NO_DECODE);
    driver.setShutdown(MAX7219Driver::NORMAL_MODE);
    driver.setTestMode(MAX7219Driver::TEST_MODE_OFF);
    
    unsigned char i = 0;
    unsigned int package;

    while (true) {
        
        i++; 
        package = driver.createPackage(i % 8, MAX7219Driver::DIGIT0);
        driver.sendPackage(package);
        Serial.print('.');
        delay(1000);
    }
}

void loop() {
}