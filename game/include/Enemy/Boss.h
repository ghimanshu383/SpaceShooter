//
// Created by ghima on 27-07-2024.
//
#include "EnemySpaceShip.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <frameWork/Delegate.h>

#ifndef LIGHTYEARS_BOSS_H
#define LIGHTYEARS_BOSS_H
namespace ly {
    class World;

    class Shooter;

    class Boss : public EnemySpaceShip {
    public:
        explicit Boss(World *owningWorld,
                      std::string texturePath = std::string{"SpaceShooterRedux/PNG/Enemies/boss.png"},
                      sf::Vector2f velocity = {0, 1},
                      float speed = 200.f);

        virtual void Shoot() override;

        virtual void Tick(float DeltaTime) override;

        virtual void Blow() override;

        Delegate<>& GetEndDelegate()  { return mEndStageDelegate; };
    private:
        sf::Vector2f mVelocity;
        float mSpeed;

        shared<Shooter> mShooterOne;
        Delegate<> mEndStageDelegate;
    };
}
#endif //LIGHTYEARS_BOSS_H
