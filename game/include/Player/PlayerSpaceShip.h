//
// Created by ghima on 17-07-2024.
//
#include "frameWork/Delegate.h"

#include "SpaceShip/SpaceShip.h"

#ifndef LIGHTYEARS_PLAYERSPACESHIP_H
#define LIGHTYEARS_PLAYERSPACESHIP_H

namespace ly {
    class BulletShooter;

    class Shooter;

    class ThreeWayShooter;

    class HealthComponent;

    class PlayerSpaceShip : public SpaceShip {
    public:
        explicit PlayerSpaceShip(World *owningWorld,
                                 std::string texturePath = "SpaceShooterRedux/PNG/playerShip1_blue.png");

        virtual void Tick(float deltaTime) override;

        virtual void HandleInput();

        virtual void ConsumeInput();

        void ClampInputOnEdge();

        virtual void Shoot() override;

        virtual void OnTakeDamage(float amt) override;

        virtual void Blow() override;

        float getMSpeed() const;

        void setMSpeed(float mSpeed);

        void SetShooter(Shooter *shooter) {
            mBulletShooter = shooter;
        }

    private:
        sf::Vector2f moveInput;
        float mSpeed;
        sf::Vector2u mWindowSize;
        Shooter *mBulletShooter;
    };
}

#endif
