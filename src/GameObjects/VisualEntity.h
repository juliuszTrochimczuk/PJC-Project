#ifndef PJC_PROJECT_VISUALENTITY_H
#define PJC_PROJECT_VISUALENTITY_H

#include "BasicEntity.h"

class VisualEntity : public BasicEntity {
private:
    sf::Vector2<unsigned int> spawnPosition;
protected:
    sf::Shape* shape;
    void setSpawnPosition(sf::Vector2<unsigned int> spawnPosition) { this->spawnPosition = spawnPosition; }
public:
    VisualEntity(int priority) : BasicEntity(priority) { }
    void start() override;
    sf::Shape* getShape();
};


#endif //PJC_PROJECT_VISUALENTITY_H
