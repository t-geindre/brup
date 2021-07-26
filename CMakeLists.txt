cmake_minimum_required(VERSION 3.7)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Engine/Game.cpp src/Engine/Game.h src/Brup/Scenes/Playing.cpp src/Brup/Scenes/Playing.h src/Engine/Update/Updatable.h src/Engine/Draw/Drawable.h src/Brup/Player/Ship.cpp src/Brup/Player/Ship.h src/Brup/Weapons/Weapon.cpp src/Brup/Weapons/Weapon.h src/Brup/Weapons/Projectiles/Projectile.cpp src/Brup/Weapons/Projectiles/Projectile.h src/Brup/Weapons/Projectiles/ShortRedLaser.cpp src/Brup/Weapons/Projectiles/ShortRedLaser.h src/Brup/Weapons/LaserMachineGun.cpp src/Brup/Weapons/LaserMachineGun.h src/Brup/Game.cpp src/Brup/Game.h src/Engine/Initable.h src/Engine/Draw/DrawPool.cpp src/Engine/Draw/DrawPool.h src/Engine/Update/UpdatePool.cpp src/Engine/Update/UpdatePool.h src/Brup/Backgrounds/Stars.cpp src/Brup/Backgrounds/Stars.h src/Brup/Enemies/Netflix.cpp src/Brup/Enemies/Netflix.h src/Engine/GameObject.cpp src/Engine/GameObject.h src/Engine/Collision/Collidable.cpp src/Engine/Collision/Collidable.h src/Engine/Collision/CollisionPool.cpp src/Engine/Collision/CollisionPool.h src/Brup/Scenes/StageTitle.cpp src/Brup/Scenes/StageTitle.h src/Brup/Effects/ParticleExplosion.cpp src/Brup/Effects/ParticleExplosion.h src/Brup/Enemies/Enemy.cpp src/Brup/Enemies/Enemy.h src/Engine/Debug/CollisionMasks.cpp src/Engine/Debug/CollisionMasks.h src/Engine/Debug/FramePerSecond.cpp src/Engine/Debug/FramePerSecond.h src/Engine/Event/EventDispatcher.cpp src/Engine/Event/EventDispatcher.h src/Engine/Event/Event.cpp src/Engine/Event/Event.h src/Brup/Effects/GlowingEdges.cpp src/Brup/Effects/GlowingEdges.h)
add_executable(Game ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
