//
// Created by ghima on 17-07-2024.
//
#include <SFML/System.hpp>
#include <frameWork/World.h>

#include "weapons/Shooter.h"
#include "weapons/Bullet.h"
#include <string>

#ifndef LIGHTYEARS_BULLETSHOOTER_H
#define LIGHTYEARS_BULLETSHOOTER_H
namespace ly {
    class BulletShooter : public Shooter {
    public:
        explicit BulletShooter(Actor *owningActor, float coolDownTime = 1.0f,
                               std::string bulletTexture = "SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
                               const sf::Vector2f &locationOffset = {0.f, 0.f}, float rotationOffset = 0.f);

        virtual void ShootImpl() override;

        virtual bool IsOnCoolDown() override;

        virtual bool CanShoot() override;

    private:
        sf::Clock mCoolDownClock;
        float mCoolDownInterval;
        Actor *mOwningActor;
        std::string mBulletTexture;
        sf::Vector2f mLocalOffset;
        float mRotationOffset;
    };
}
#endif //LIGHTYEARS_BULLETSHOOTER_H
