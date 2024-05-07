#ifndef PJC_PROJECT_CHARACTER_H
#define PJC_PROJECT_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "BasicEntity.h"

class Character : public BasicEntity {
protected:
    int health{};
    float moveSpeed{};
};

#endif //PJC_PROJECT_CHARACTER_H