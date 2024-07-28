//
// Created by ghima on 27-07-2024.
//
#include <SFMl/Graphics.hpp>
#include "Actor.h"

#ifndef LIGHTYEARS_BACKGROUNDACTORS_H
#define LIGHTYEARS_BACKGROUNDACTORS_H
namespace ly {
    class World;

    class BackgroundObjects : public Actor {
    public:
        BackgroundObjects(World *owningWorld, std::string &texturePath, float moveSpeed);

        virtual void Tick(float deltaTime) override;

        virtual void BeginPlay() override;

    private:
        sf::Vector2f mVelocity = {0, 1};
        float mMoveSpeed;
    };
}
#endif //LIGHTYEARS_BACKGROUNDACTORS_H
