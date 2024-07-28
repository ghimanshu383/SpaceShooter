//
// Created by ghima on 27-07-2024.
//
#include "frameWork/BackGroundActors.h"

namespace ly {
    BackgroundObjects::BackgroundObjects(ly::World *owningWorld, std::string &texturePath, float moveSpeed) : Actor(
            owningWorld, texturePath), mMoveSpeed{moveSpeed} {}

    void BackgroundObjects::BeginPlay() {
        GetActorSprite().setColor(sf::Color{180, 180, 200, 255});

    }

    void BackgroundObjects::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(mVelocity * mMoveSpeed * deltaTime);
    }
}