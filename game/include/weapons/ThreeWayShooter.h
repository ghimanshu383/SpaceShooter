//
// Created by ghima on 22-07-2024.
//
#include <string>
#include <SFML/Graphics.hpp>
#include "weapons/Shooter.h"
#include "weapons/BulletShooter.h"

#ifndef LIGHTYEARS_THREEWAYSHOOTER_H
#define LIGHTYEARS_THREEWAYSHOOTER_H
namespace ly {
    class Actor;

    class ThreeWayShooter : public Shooter {
    public:
        explicit ThreeWayShooter(Actor *owningActor, float coolDownTime = 1.0f,
                                 const std::string& bulletTexture = "SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
                                 const sf::Vector2f &locationOffset = {0.f, 0.f}, float rotationOffset = 0.f);

        virtual void ShootImpl() override;

    private:
        BulletShooter mShooterOne;
        BulletShooter mShooterTwo;
        BulletShooter mShooterThree;
    };
}
#endif //LIGHTYEARS_THREEWAYSHOOTER_H
