#ifndef PJC_PROJECT_BASICENTITY_H
#define PJC_PROJECT_BASICENTITY_H

#include <SFML/Graphics.hpp>
#include <fmt/core.h>

class BasicEntity {
private:
    bool didStart = false;
public:
    int priority;
    BasicEntity(int priority) {this->priority = priority; }
    bool canDoStart() { return !didStart; }
    virtual void start() {
        this->didStart = true;
    }
    virtual void update() { }
};

#endif //PJC_PROJECT_BASICENTITY_H