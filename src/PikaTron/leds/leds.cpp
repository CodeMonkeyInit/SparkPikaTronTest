//
// Created by Денис Кулиев on 2024-05-08.
//

#include "leds.h"

std::map<int, String> leds = {
    {whiteLedPin, "White"},
    {yellowLedPin, "Yellow"},
    {redLedPin, "Red"},
    {blueLedPin, "Blue"},
    {greenLedPin, "Green"},
    {purpleLedPin, "Purple"}
};

std::map<String, int> colorToPin = {};
std::map<String, bool> ledStats = {};

ulong lastRender1 = 0;
void writeLedsLoop() {
    bool printLeds = false;
    if(millis() - lastRender1 > 2000) {
        lastRender1 = millis();
        printLeds = true;
    }

    for (const auto &ledPin: leds) {
        pinMode(ledPin.first, OUTPUT);
        digitalWrite(ledPin.first, ledStats[ledPin.second] ? HIGH : LOW);
        if (printLeds) {
            Serial.print(ledPin.second);
            Serial.print(" ");

            Serial.print(ledPin.first);
            Serial.print(" ");
            Serial.print(ledStats[ledPin.second]);
            Serial.print(" ");
        }

    }

    if(printLeds) Serial.println();
}

void setupLeds() {
    for (auto &led: leds)
        colorToPin[led.second] = led.first;

    for (auto &led: leds)
        ledStats[led.second] = false;

    writeLedsLoop();
}