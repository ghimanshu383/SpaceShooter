//
// Created by ghima on 19-07-2024.
//
#include "Enemy/EnemySpaceShip.h"

#ifndef LIGHTYEARS_VANGUARD_H
#define LIGHTYEARS_VANGUARD_H
namespace ly {
    class Vanguard : public EnemySpaceShip {
    public:
        explicit Vanguard(World *owningWorld,
                          std::string texturePath = std::string{"SpaceShooterRedux/PNG/Enemies/enemyBlack3.png"},
                          sf::Vector2f velocity = {0.f, 1.f},
                          float speed = 200.f);

        virtual void Tick(float deltaTime) override;

    private:
        sf::Vector2f mVelocity;
        float mSpeed;
    };
}
#endif //LIGHTYEARS_VANGUARD_H
