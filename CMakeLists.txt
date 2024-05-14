cmake_minimum_required(VERSION 3.27)
project(PJC_Project)
project(TestScript)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
)
FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(SFML)
add_executable(PJC_Project src/main.cpp
        src/GameObjects/Characters/Player/Player.h
        src/GameObjects/Characters/Player/Player.cpp
        src/GameObjects/Characters/Character.h
        src/GameObjects/Characters/Character.cpp
        src/GameControllers/MathMethods.h
        src/GameControllers/MathMethods.cpp
        src/GameControllers/GameController.h
        src/GameControllers/GameController.cpp
        src/GameObjects/BasicEntity.h
        src/GameControllers/TimeController.h
        src/GameControllers/TimeController.cpp
        src/GameObjects/VisualEntity.cpp
        src/GameObjects/VisualEntity.h
        src/GameObjects/Map/Map.cpp
        src/GameObjects/Map/Map.h
        src/GameControllers/AISpawner.h
        src/GameControllers/AISpawner.cpp
        src/GameObjects/Characters/AI/BaseEnemyEntity.cpp
        src/GameObjects/Characters/AI/BaseEnemyEntity.h
        src/GameObjects/Bullets/EnemyBullet.cpp
        src/GameObjects/Bullets/EnemyBullet.h
        src/GameObjects/Bullets/Bullet.cpp
        src/GameObjects/Bullets/Bullet.h
        src/GameObjects/Characters/AI/Melee/CircleMeleeAI.cpp
        src/GameObjects/Characters/AI/Melee/CircleMeleeAI.h
        src/GameObjects/Characters/AI/Range/ShootingAI.cpp
        src/GameObjects/Characters/AI/Range/ShootingAI.h
)

add_executable(TestScript testFile.cpp)

target_link_libraries(PJC_Project fmt sfml-graphics)
target_link_libraries(TestScript fmt)
