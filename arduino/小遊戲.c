#include <stdlib.h>

int buttonPin[] = {1, 2, 3, 4};
int ledPin[] = {5, 6, 7, 8};
int haha[10] = {0};
int buzzPin = 12;
int level = 4;
int ans[10] = {0};

void seed(int c) {
    int a = 0;
    int b;

    while (c > a) {
        b = rand() % 10;

        if (b != buttonPin[0] && b != buttonPin[1] && b != buttonPin[2] && b != buttonPin[3]) {
            haha[a] = b; 
            a++;
        }
    }
}

void outPut(int c) {
    for (int i = 0; i < c; i++) {
        digitalWrite(haha[i], HIGH);
        tone(buzzPin, haha[i] * 50);
        delay(1000 - (c * 10));
        digitalWrite(haha[i], LOW); 
    }
}

int input(int c) {
    int a = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < 4; j++) {
            if (digitalRead(buttonPin[j]) != LOW) {
                ans[i] = buttonPin[j];
            }
        }
    }

    for (int i = 0; i < c; i++) {
        if (haha[i] != ans[i]) {
            a++;
        }
    }
    return a;
}

void pass() {
    int a = 0;
    int b = 1;
    for (int i = 0; i < 3; i++) {
        while (a > -1 && a < 4) {
            digitalWrite(ledPin[a], HIGH);
            delay(40);
            a += b;
        }
        b = -b; 
    }
}

void noPass() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            digitalWrite(ledPin[i], HIGH);
        }
        delay(1000);
    }
}

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(buttonPin[i], INPUT);
        pinMode(ledPin[i], OUTPUT);
    }
    pinMode(buzzPin, OUTPUT);
}

void loop() {
    while (level < 14) {
        seed(level);
        outPut(level);
        if (input(level) > 0) {
            noPass();
            return; 
        } else {
            pass();
            level++;
        }
    }
}
