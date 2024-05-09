//
// Created by Денис Кулиев on 2024-05-08.
//

#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>
#include <map>
#include "../devicesConstants.h"


extern std::map<int, String> leds;

extern std::map<String, int> colorToPin;
extern std::map<String, bool> ledStats;

void setupLeds();

void writeLedsLoop();

#endif //LEDS_H
