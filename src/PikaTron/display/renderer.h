#pragma once

#include "Arduino.h"
#include "../actions/arduino-snake-game/snake.h"
#include "../actions/arduino-snake-game/position.h"
#include "../actions/arduino-snake-game/fruit.h"
#include "display.h"

namespace Renderer {
  void initialize();
  void renderBorder();
  void renderSnake(Snake *snake);
  void renderFruit(Fruit *fruit);
  void renderGameOver(Snake *snake);
  void startFrame();
  void endFrame();
  bool shouldRender();
}
