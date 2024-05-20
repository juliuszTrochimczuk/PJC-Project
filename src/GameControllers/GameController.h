#ifndef PJC_PROJECT_GAMECONTROLLER_H
#define PJC_PROJECT_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "TimeController.h"
#include "../GameObjects/Characters/Player/Player.h"
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Characters/AI/BaseEnemyEntity.h"

class GameController {
private:
    static GameController* instance;
    GameController() = default;

    std::vector<std::unique_ptr<BasicEntity>> basicEntities;
    std::vector<VisualEntity*> visualEntities;
    std::vector<BaseEnemyEntity*> enemyEntities;

    std::vector<std::unique_ptr<BasicEntity>> basicEntitiesHolder;
    std::vector<VisualEntity*> visualEntitiesHolder;
    std::vector<BaseEnemyEntity*> enemyEntitiesHolder;

    void refreshBasicEntities();
    void refreshVisualEntities();
    void refreshEnemyEntities();

    void removeFromBasicEntities();
    void removeFromVisualEntities();
    void removeFromEnemyEntities();

    void addFromBasicHolderToVector();
    void addFromVisualHolderToVector();
    void addFromEnemyHolderToVector();
public:
    static GameController* getInstance();
    sf::RenderWindow* gameWindow;
    TimeController* timeController;
    Map* map;
    Player* player;
    bool fruitOnLevel = false;

    void setGameWindow(sf::RenderWindow* gameWindow) { this->gameWindow = gameWindow;}
    void setTimeController(TimeController* timeController) { this->timeController = timeController; }
    void setPlayer(Player* player) { this->player = player; }
    void setMap(Map* map) { this->map = map; }
    void setGameFrameRate(int frameRate) const;

    std::vector<std::unique_ptr<BasicEntity>> const& getBasicEntities() const { return basicEntities; }
    std::vector<VisualEntity*> getVisualEntities() const { return visualEntities; }
    std::vector<BaseEnemyEntity*> getEnemyEntities() const { return enemyEntities; }

    void addBasicEntity(std::unique_ptr<BasicEntity> newEntity);
    void addVisualEntity(VisualEntity* newVisualEntity);
    void addEnemyEntity(BaseEnemyEntity* newEnemyEntity);

    void refreshVectorsWithEntities();

    void removeAllBasicEntities() { basicEntities.clear(); }
    void removeAllVisualEntities() { visualEntities.clear(); }
    void removeAllEnemyEntities() { enemyEntities.clear(); }
};


#endif //PJC_PROJECT_GAMECONTROLLER_H
