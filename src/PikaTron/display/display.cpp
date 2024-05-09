//
// Created by Денис Кулиев on 2024-05-08.
//

#include "display.h"

const unsigned char *bitmaps[imagesCount] = {
    pikaBitMap, ohMyGodRobot, bitmap_firstboard, bitmap_myboard, whatIsMyPurposeRobotBitmap, bitmap_myboardAlt,
    rickBitmap,
};

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void displaySetup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.drawBitmap(0, 0, pikaBitMap, 128, 64, WHITE);

    display.setTextSize(1);

    display.setTextColor(BLACK);
    display.setCursor(45, 1);
    display.println("PLEASE");
    display.setCursor(10, 30);

    display.println("HELP           ME!");
    display.display();
}

