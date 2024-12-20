#ifndef PJC_PROJECT_VISUALENTITY_H
#define PJC_PROJECT_VISUALENTITY_H

#include "BasicEntity.h"

class VisualEntity : public BasicEntity {
private:
    sf::Texture texture;
protected:
    sf::Shape* shape;
    sf::Vector2<unsigned int> spawnPosition;
public:
    VisualEntity(int priority) : BasicEntity(priority) { };
    void start() override;
    sf::Shape* getShape() const;
};


#endif //PJC_PROJECT_VISUALENTITY_H
