//
// Created by Денис Кулиев on 2024-05-08.
//

#include "showImages.h"

uint currentImage = 0;

void showImage() {
    display.clearDisplay();
    display.drawBitmap(0, 0, bitmaps[(currentImage / 4) % imagesCount], 128, 60, WHITE);
    display.display();
}

void showImagesLoop() {
    const auto newImage = leftEncoder->read();
    if (newImage != currentImage) {
        currentImage = static_cast<uint>(newImage);
        showImage();
    }
}