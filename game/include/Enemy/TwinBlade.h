//
// Created by ghima on 20-07-2024.
//
#include "Enemy/EnemySpaceShip.h"

#ifndef LIGHTYEARS_TWINBLADE_H
#define LIGHTYEARS_TWINBLADE_H
namespace ly {
    class TwinBlade : public EnemySpaceShip {
    public:
        explicit TwinBlade(World *owningWorld,
                           std::string texturePath = std::string{"SpaceShooterRedux/PNG/Enemies/enemyBlack1.png"},
                           sf::Vector2f velocity = {0.f, 1.f},
                           float speed = 200.f);

        virtual void Shoot() override;

        virtual void Tick(float deltaTime) override;

    private:
        shared<BulletShooter> mShooterOne;
        shared<BulletShooter> mShooterTwo;

        sf::Vector2f mVelocity;
        float mSpeed;
    };
}
#endif //LIGHTYEARS_TWINBLADE_H
