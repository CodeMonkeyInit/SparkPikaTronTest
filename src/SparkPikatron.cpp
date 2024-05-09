//
// Created by Денис Кулиев on 2024-05-08.
//

#include "SparkPikatron.h"

namespace Pikatron {
    void setup() {
        displaySetup();

        setupLeds();

        setupControls();
    }

    void loop() {
        buttonLoop();

        showImagesLoop();
        rotationTestLoop();

        SnakeGame::loop();

        writeLedsLoop();
    }
}
