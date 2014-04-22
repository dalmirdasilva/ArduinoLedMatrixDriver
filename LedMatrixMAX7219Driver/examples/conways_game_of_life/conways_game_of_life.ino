#include <MAX7219Driver.h>
#include <LedMatrixDriver.h>
#include <LedMatrixMAX7219Driver.h>

#define WIDTH 8
#define HEIGHT 8

MAX7219Driver driver(10, 11, 12);
LedMatrixMAX7219Driver matrix(&driver, WIDTH, HEIGHT);
unsigned char univ[WIDTH][HEIGHT];

void show() {
    unsigned char x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            matrix.setLed(x, y, univ[y][x] ? LedMatrixDriver::ON : LedMatrixDriver::OFF);
        }
    }
}

void evolve() {
    unsigned char new_univ[WIDTH][HEIGHT];
    unsigned char x, y, y1, x1;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int n = 0;
            for (y1 = y - 1; y1 <= y + 1; y1++) {
                for (x1 = x - 1; x1 <= x + 1; x1++) {
                    if (univ[(y1 + HEIGHT) % HEIGHT][(x1 + WIDTH) % WIDTH]) {
                        n++;
                    }
                }
            }
            if (univ[y][x]) {
                n--;
            }
            new_univ[y][x] = (n == 3 || (n == 2 && univ[y][x]));
        }
    }
    for (y = 0; y < HEIGHT; y++){
        for (x = 0; x < WIDTH; x++) {
            univ[y][x] = new_univ[y][x];
        }
    }
}

void setup() {
    unsigned char x, y;
    Serial.begin(9600);
    Serial.println("Conway's Game of Life");
    matrix.clear();
    pinMode(A0, INPUT);
    randomSeed(analogRead(A0));
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            univ[y][x] = random(0, RANDOM_MAX) < RANDOM_MAX / 6 ? 1 : 0;
        }
    }
}

void loop() {
    Serial.print('.');
    show();
    evolve();
    delay(500);
}
