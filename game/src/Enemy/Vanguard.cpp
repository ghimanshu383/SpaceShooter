//
// Created by ghima on 19-07-2024.
//
#include "Enemy/Vanguard.h"

namespace ly {
    Vanguard::Vanguard(ly::World *owningWorld, std::string texturePath, sf::Vector2f velocity, float speed)
            : EnemySpaceShip(owningWorld, texturePath), mVelocity{velocity}, mSpeed{speed} {}

    void Vanguard::Tick(float deltaTime) {
        EnemySpaceShip::Tick(deltaTime);
        AddActorLocationOffset(mVelocity * deltaTime * mSpeed);
    }
}