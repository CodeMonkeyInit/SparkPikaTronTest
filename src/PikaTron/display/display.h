//
// Created by Денис Кулиев on 2024-05-08.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_SSD1306.h>
#include "../bitmaps/pika.h"
#include "../bitmaps/cursedPika.h"
#include "../bitmaps/myboard.h"
#include "../bitmaps/firstBoard.h"
#include "../bitmaps/myboard_alt.h"
#include "../bitmaps/whatIsMyPurpose.h"

extern Adafruit_SSD1306 display;

constexpr int imagesCount = 7;
extern const unsigned char *bitmaps[imagesCount];
void displaySetup();

#endif //DISPLAY_H
