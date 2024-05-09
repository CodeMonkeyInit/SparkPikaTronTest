//
// Created by Денис Кулиев on 2024-05-08.
//

#ifndef SNAKE_H
#define SNAKE_H

#include "arduino-snake-game/snake.h"
#include "../actions/arduino-snake-game/fruit.h"
#include "../display/renderer.h"
#include "../controls/controls.h"

namespace SnakeGame {
    void tooglePlayPause();
    void loop(bool force = false);
    bool isRunning();
}



#endif //SNAKE_H
