//
// Created by ghima on 27-07-2024.
//
#include "BackGroundActors.h"
#include <string>

#ifndef LIGHTYEARS_BACKDROPACTOR_H
#define LIGHTYEARS_BACKDROPACTOR_H
namespace ly {
    class World;

    class BackDropActor : public BackgroundObjects {
    public:
        BackDropActor(World
                      *owningWorld,
                      std::string &texturePath, sf::Vector2f
                      velocity,
                      float moveSpeed = 200.f
        );

        virtual void BeginPlay() override;

        virtual void Tick(float deltaTime) override;

    private:
        sf::Vector2f mVelocity;

        float mLeftShift;
        float mTopShift;
        float mMoveSpeed;
    };
}
#endif //LIGHTYEARS_BACKDROPACTOR_H
