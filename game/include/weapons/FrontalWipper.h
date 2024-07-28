//
// Created by ghima on 22-07-2024.
//
#include "weapons/BulletShooter.h"
#include "weapons/Shooter.h"

#ifndef LIGHTYEARS_FRONTALWIPPER_H
#define LIGHTYEARS_FRONTALWIPPER_H
namespace ly {
    class Actor;

    class FrontalWiper : public Shooter {
    public:
        FrontalWiper(Actor *owningActor, float coolDownTime = .1f,
                     const std::string &bulletTexture = "SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
                     const sf::Vector2f &locationOffset = {0.f, 0.f}, float rotationOffset = 0.f);

        virtual void ShootImpl() override;

    private:
        BulletShooter mShooterOne;
        BulletShooter mShooterTwo;
        BulletShooter mShooterThree;
        BulletShooter mShooterFour;
    };
}
#endif //LIGHTYEARS_FRONTALWIPPER_H
