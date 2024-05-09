//
// Created by Денис Кулиев on 2024-05-08.
//

#ifndef CONTROLS_H

#define CONTROLS_H


#include "display/display.h"
#include <map>

#include <EasyButton.h>
#include "devicesConstants.h"
#include <actions/rotationTest.h>
#include <actions/snake.h>
#include <actions/whatIsMyPurpose.h>
#include "leds/leds.h"
#include <Encoder.h>


extern EasyButton whiteButton;
extern EasyButton yellowButton;
extern EasyButton redButton;
extern EasyButton blueButton;
extern EasyButton greenButton;
extern EasyButton purpleButton;
extern EasyButton leftEncoderButton;
extern EasyButton centerEncoderButton;
extern EasyButton rightEncoderButton;

extern int rotation;

extern Encoder *leftEncoder;
extern Encoder *centerEncoder;
extern Encoder *rightEncoder;

void setupControls();
void buttonLoop ();



#endif //CONTROLS_H
