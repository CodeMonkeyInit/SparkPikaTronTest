//
// Created by Денис Кулиев on 2024-05-08.
//

#include "rotationTest.h"

void rotationTestLoop(bool force) {
    const auto newRotation = centerEncoder->read();

    if (newRotation != rotation || force) {
        rotation = newRotation;
        display.clearDisplay();
        display.setCursor(10, 10);
        display.setTextSize(2);

        display.setTextColor(WHITE);
        display.println("Rotation ");
        display.print("    ");
        display.println(rotation);
        display.display();
    }
}

uint volume = 0;

const int youSpinMeLength = 2;

String youSpinMe[] = {
    "You spin me right 'round, baby, right 'round",
    "Like a record, baby, right 'round, 'round, 'round"
};

void youSpinMeLoop(bool force) {
    const auto newVolume = uint(rightEncoder->read() / 4);

    if (newVolume != volume || force) {
        display.clearDisplay();
        volume = newVolume;
        display.setCursor(0, 0);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.println(youSpinMe[newVolume % youSpinMeLength]);
        display.display();
        display.setTextSize(1);
    }

}