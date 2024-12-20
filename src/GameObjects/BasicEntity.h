#ifndef PJC_PROJECT_BASICENTITY_H
#define PJC_PROJECT_BASICENTITY_H

#include <SFML/Graphics.hpp>
#include <fmt/core.h>

class BasicEntity {
public:
    int priority;
    BasicEntity(int priority) : priority(priority) { }
    virtual ~BasicEntity() = default;
    virtual void start() { }
    virtual void update() { }
};

#endif //PJC_PROJECT_BASICENTITY_H