//
// Created by ghima on 20-07-2024.
//
#include "Enemy/EnemySpaceShip.h"

#ifndef LIGHTYEARS_HEXGUARD_H
#define LIGHTYEARS_HEXGUARD_H
namespace ly {
    class World;

    class HexGuard : public EnemySpaceShip {
    public:
        explicit HexGuard(World *owningWorld,
                          std::string texturePath = std::string{"SpaceShooterRedux/PNG/Enemies/enemyBlack4.png"},
                          sf::Vector2f velocity = {0.f, 1.f},
                          float speed = 200.f);

        virtual void Shoot() override;

        virtual void Tick(float deltaTime) override;

    private:
        shared<BulletShooter> mShooterOne;
        shared<BulletShooter> mShooterTwo;
        shared<BulletShooter> mShooterThree;
        shared<BulletShooter> mShooterFour;
        shared<BulletShooter> mShooterFive;
        shared<BulletShooter> mShooterSix;

        sf::Vector2f mVelocity;
        float mSpeed;
    };
}
#endif //LIGHTYEARS_HEXGUARD_H
