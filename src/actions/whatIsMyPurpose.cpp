//
// Created by Денис Кулиев on 2024-05-08.
//

#include "whatIsMyPurpose.h"

void whatIsMyPurpose() {
    display.setTextColor(BLACK);
    display.setTextSize(1);
    display.clearDisplay();
    display.drawBitmap(0, 0, whatIsMyPurposeRobotBitmap, 128, 64, WHITE);
    display.setCursor(40, 10);
    display.println("What is my");
    display.setCursor(40, 20);

    display.println("purpose?");
    display.display();

    delay(2000);

    display.clearDisplay();
    display.drawBitmap(0, 0, rickBitmap, 128, 64, WHITE);
    display.setCursor(55, 10);
    display.println("You show");
    display.setCursor(55, 20);

    display.println("memes and");
    display.setCursor(55, 30);
    display.println("blink lights");

    display.display();


    delay(4000);

    display.clearDisplay();
    display.drawBitmap(0, 0, ohMyGodRobot, 128, 64, WHITE);
    display.setCursor(50, 10);
    display.println("OH MY GOD!");
    display.display();

    delay(2000);
}