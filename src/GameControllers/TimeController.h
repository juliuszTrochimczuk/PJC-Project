#ifndef PJC_PROJECT_TIMECONTROLLER_H
#define PJC_PROJECT_TIMECONTROLLER_H


#include "../GameObjects/BasicEntity.h"

class TimeController : public BasicEntity {
private:
    float deltaTime = 0;
    float appRunTime = 0;
public:
    TimeController(int priority) : BasicEntity(priority) { };
    void start() override { };
    void update() override;
    float getDeltaTime() const { return deltaTime; };
    float getApplicationRuntime() const { return appRunTime; }
    void setFrameRateForTimer(int frameRate);
};


#endif //PJC_PROJECT_TIMECONTROLLER_H
