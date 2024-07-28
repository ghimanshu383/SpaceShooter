//
// Created by ghima on 21-07-2024.
//
#include "Enemy/UFO.h"
#include "weapons/BulletShooter.h"
#include <frameWork/MathUtil.h>

namespace ly {
    UFO::UFO(ly::World *owningWorld, std::string texturePath, sf::Vector2f velocity, float speed) : EnemySpaceShip(
            owningWorld, texturePath), mVelocity(velocity),mSpeed {speed},
                                                                                                    mShooterOne{
                                                                                                            new BulletShooter{
                                                                                                                    this,
                                                                                                                    .5f,
                                                                                                                    "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                                                                                                                    {},
                                                                                                                    60}},
                                                                                                    mShooterTwo{
                                                                                                            new BulletShooter{
                                                                                                                    this,
                                                                                                                    .5f,
                                                                                                                    "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                                                                                                                    {},
                                                                                                                    -60}},
                                                                                                    mShooterThree{
                                                                                                            new BulletShooter{
                                                                                                                    this,
                                                                                                                    .5f,
                                                                                                                    "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                                                                                                                    {},
                                                                                                                    180}} {

    }

    void UFO::Shoot() {

        mShooterOne->ShootImpl();
        mShooterTwo->ShootImpl();
        mShooterThree->ShootImpl();
    }

    void UFO::Tick(float deltaTime) {
        EnemySpaceShip::Tick(deltaTime);
        Actor::AddActorRotationOffset(DegreeToRadians(15) * deltaTime * 200.f);
        AddActorLocationOffset(mVelocity * deltaTime * mSpeed);
    }
}