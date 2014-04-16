#include <IRremote.h>
#include <MAX7219Driver.h>
#include <LEDMatrixDriver.h>
#include <LEDMatrixMAX7219Driver.h>

#define IR_RECEIVER_PIN 9

IRrecv irReceiver(IR_RECEIVER_PIN);
MAX7219Driver driver(10, 11, 12);
LEDMatrixMAX7219Driver matrix(&driver, 8, 8);
decode_results decodedSignal;

void setup() {
    Serial.begin(9600);
    Serial.println("Ready.");
    irReceiver.enableIRIn();
    matrix.setLed(4, 4, 1);
}

void decodeSignal(unsigned long signal) {
    switch(signal) {
        case 16761405:
            matrix.setRow(1, 0xaa);
        break;
        
    }
} 

void loop() {
    if (irReceiver.decode(&decodedSignal)) {
        Serial.println(decodedSignal.value);
        decodeSignal(decodedSignal.value);
        irReceiver.resume();
    }
}
