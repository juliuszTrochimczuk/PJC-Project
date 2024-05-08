#include "TimeController.h"
#include <fmt/core.h>

void TimeController::update() {
    appRunTime += deltaTime;
}

void TimeController::setFrameRateForTimer(int frameRate) {
    deltaTime = 1.0f / (float)frameRate;
}


