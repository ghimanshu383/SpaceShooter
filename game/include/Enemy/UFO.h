//
// Created by ghima on 21-07-2024.
//
#include "Enemy/EnemySpaceShip.h"

#ifndef LIGHTYEARS_UFO_H
#define LIGHTYEARS_UFO_H
namespace ly {
    class UFO : public EnemySpaceShip {
    public:
        UFO(World *owningWorld,
            std::string texturePath = std::string{"SpaceShooterRedux/PNG/ufoRed.png"},
            sf::Vector2f velocity = {0.f, 1.f},
            float speed = 200.f);

        virtual void Shoot() override;

        virtual void Tick(float deltaTime) override;

        void SetVelocity(const sf::Vector2f &newVelocity) {
            mVelocity = newVelocity;
        }

        void SetSpeed(const float newSpeed) {
            mSpeed = newSpeed;
        }

    private:
        shared<BulletShooter> mShooterOne;
        shared<BulletShooter> mShooterTwo;
        shared<BulletShooter> mShooterThree;

        sf::Vector2f mVelocity;
        float mSpeed;
    };
}
#endif //LIGHTYEARS_UFO_H
