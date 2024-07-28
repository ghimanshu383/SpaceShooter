//
// Created by ghima on 22-07-2024.
//
#include "weapons/ThreeWayShooter.h"

namespace ly {
    ThreeWayShooter::ThreeWayShooter(ly::Actor *owningActor, float coolDownTime, const std::string &bulletTexture,
                                     const sf::Vector2f &locationOffset, float rotationOffset) : Shooter(owningActor),
                                                                                                 mShooterOne(
                                                                                                         owningActor,
                                                                                                         .1f,
                                                                                                         bulletTexture,
                                                                                                         locationOffset,
                                                                                                         -30.f),
                                                                                                 mShooterTwo(
                                                                                                         owningActor,
                                                                                                         .1f,
                                                                                                         bulletTexture,
                                                                                                         locationOffset,
                                                                                                         0.f),
                                                                                                 mShooterThree(
                                                                                                         owningActor,
                                                                                                         .1f,
                                                                                                         bulletTexture,
                                                                                                         locationOffset,
                                                                                                         30.f) {}

    void ThreeWayShooter::ShootImpl() {
        mShooterOne.ShootImpl();
        mShooterTwo.ShootImpl();
        mShooterThree.ShootImpl();
    }
}