#pragma once

#include "Arduino.h"
#include "snake.h"
#include "position.h"
#include "fruit.h"
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
