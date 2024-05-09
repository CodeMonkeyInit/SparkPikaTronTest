//
// Created by Денис Кулиев on 2024-05-08.
//

#include "snake.h"
namespace SnakeGame {
    bool playSnake = false;

    Snake snake;
    Fruit fruit(&snake);

    int snakeDirection = 0;

    void tooglePlayPause() {
        playSnake = !playSnake;
    }

    void loop(bool force) {
        if (!playSnake) return;
        if(yellowButton.isPressed()) snake = Snake();

        auto currentDirection = rightEncoder->read() / 4;
        auto direction = snake.getDirection();

        if(currentDirection > snakeDirection) {
            if(direction == UP) snake.turn(RIGHT);
            if(direction == RIGHT) snake.turn(DOWN);
            if(direction == DOWN) snake.turn(LEFT);
            if(direction == LEFT) snake.turn(UP);
        } if(currentDirection < snakeDirection) {
            if(direction == UP) snake.turn(LEFT);
            if(direction == RIGHT) snake.turn(UP);
            if(direction == DOWN) snake.turn(RIGHT);
            if(direction == LEFT) snake.turn(DOWN);
        }

        snakeDirection = currentDirection;

        if (whiteButton.isPressed()) snake.turn(UP);
        if (greenButton.isPressed()) snake.turn(DOWN);
        if (blueButton.isPressed()) snake.turn(LEFT);
        if (purpleButton.isPressed()) snake.turn(RIGHT);

        if(!Renderer::shouldRender()) return;

        bool resetFruit = false;
        if (snake.nextHeadPosition() == fruit.getPosition()) {
            snake.grow();
            resetFruit = true;
        }

        snake.advance();
        if (resetFruit) fruit.randomize(&snake);

        Renderer::startFrame();
        Renderer::renderBorder();
        Renderer::renderSnake(&snake);
        Renderer::renderFruit(&fruit);
        if (!snake.isAlive()) Renderer::renderGameOver(&snake);
        Renderer::endFrame();
    }

    bool isRunning() {
        return playSnake;
    }

}