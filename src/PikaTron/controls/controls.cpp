//
// Created by Денис Кулиев on 2024-05-08.
//

#include "controls.h"


EasyButton whiteButton(whiteButtonPin);
EasyButton yellowButton(yellowButtonPin);
EasyButton redButton(redButtonPin);
EasyButton blueButton(blueButtonPin);
EasyButton greenButton(greenButtonPin);
EasyButton purpleButton(purpleButtonPin);
EasyButton leftEncoderButton(leftEncoderPinButton);
EasyButton centerEncoderButton(centerEncoderPinButton);
EasyButton rightEncoderButton(rightEncoderPinButton);

Encoder *leftEncoder;
Encoder *centerEncoder;
Encoder *rightEncoder;

std::map<EasyButton *, String> encoderButtons = {
    {&leftEncoderButton, "Left"},
    {&rightEncoderButton, "Right"},
    {&centerEncoderButton, "Center"}
};

std::map<EasyButton *, String> buttons = {
    {&whiteButton, "White"},
    {&yellowButton, "Yellow"},
    {&redButton, "Red"},
    {&blueButton, "Blue"},
    {&greenButton, "Green"},
    {&purpleButton, "Purple"}
};

int rotation = 0;

void setupEncoders() {
    leftEncoder = new Encoder(leftEncoderPinA, leftEncoderPinB);
    centerEncoder = new Encoder(centerEncoderPinA, centerEncoderPinB);
    rightEncoder = new Encoder(rightEncoderPinA, rightEncoderPinB);

    for (auto button: encoderButtons) {
        button.first->begin();
        button.first->onPressed([button]() -> void {
            if (button.second == "Center") {
                rotation = centerEncoder->readAndReset();
                rotationTestLoop(true);
                return;
            }

            if (button.second == "Left") {
                whatIsMyPurpose();
                return;
            }

            SnakeGame::tooglePlayPause();
        });
    }
}

void setupButtons() {
    for (const auto &button: buttons) {
        button.first->begin();
        button.first->onPressed([button]() -> void {
            if (SnakeGame::isRunning()) return;

            auto color = button.second;
            display.clearDisplay();
            display.drawBitmap(0, 0, cursedPika, 128, 64, WHITE);
            display.setCursor(10, 1);
            display.setTextColor(BLACK);
            display.setTextSize(1);
            display.println("It works! " + color);
            display.display();
            ledStats[color] = !ledStats[color];

            Serial.println(color + " set " + ledStats[color]);
        });
    }
}

void setupControls() {
    setupButtons();
    setupEncoders();
}

void buttonLoop() {
    for (const auto &button: buttons) {
        button.first->read();
    }

    for (auto button: encoderButtons) {
        button.first->read();
    }
}
