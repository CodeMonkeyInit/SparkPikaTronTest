#include "renderer.h"

#define CELL_SIZE 8

namespace Renderer {

  void initialize() {
  }

  unsigned long time_total = 0;
  unsigned long time_last = 0;
  ulong lastRender = 0;
  float framerate() {
    time_last = time_total;
    time_total = micros();
    return 1.0 / ((time_total - time_last) / 1000000.0);
  }

  void renderBorder() {
    display.drawRect(0, 0, 128, 64, WHITE);
  }
  
  void renderSnake(Snake *snake) {
    const uint8_t **body = snake->getBody();
    for(int i = 0; i < Snake::BODY_WIDTH; i++) {
      for(int j = 0; j < Snake::BODY_HEIGHT; j++) {
        if(body[i][j] > 0) {
          display.drawRect(i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
        }
      }
    }
  }

  void renderFruit(Fruit * fruit) {
    Position position = fruit->getPosition();
    display.drawCircle(position.x * CELL_SIZE + 3, position.y * CELL_SIZE + 3, 2, WHITE);
  }

  void renderGameOver(Snake *snake) {
    display.fillRect(32, 20, 64, 22, WHITE);
    display.setCursor(34, 22);
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.print("Game Over!");
    display.setCursor(34, 32);
    display.print("Points: ");
    display.print(snake->getPoints());
  }

  void startFrame() {
    display.clearDisplay();
  }

  void endFrame() {
    display.display();
    lastRender = millis();
  }

  bool shouldRender() {
    if(millis() - lastRender < 300) return false;

    return true;
  }

}
