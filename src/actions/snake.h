//
// Created by Денис Кулиев on 2024-05-08.
//

#ifndef SNAKE_H
#define SNAKE_H

#include <snake.h>
#include <fruit.h>
#include "display/renderer.h"
#include "controls/controls.h"

namespace SnakeGame {
    void tooglePlayPause();
    void loop(bool force = false);
    bool isRunning();
}



#endif //SNAKE_H
