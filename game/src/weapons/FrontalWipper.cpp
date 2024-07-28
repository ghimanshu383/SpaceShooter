//
// Created by ghima on 22-07-2024.
//
#include "weapons/FrontalWipper.h"

namespace ly {
    FrontalWiper::FrontalWiper(ly::Actor *owningActor, float coolDownTime, const std::string &bulletTexture,
                               const sf::Vector2f &locationOffset, float rotationOffset) : Shooter(owningActor),
                                                                                           mShooterOne(owningActor,
                                                                                                       coolDownTime,
                                                                                                       bulletTexture,
                                                                                                       {-5.f, -50.f},
                                                                                                       rotationOffset),
                                                                                           mShooterTwo(owningActor,
                                                                                                       coolDownTime,
                                                                                                       bulletTexture,
                                                                                                       {5.f, -50.f},
                                                                                                       rotationOffset),
                                                                                           mShooterThree(owningActor,
                                                                                                         coolDownTime,
                                                                                                         "SpaceShooterRedux/PNG/Lasers/laserGreen11.png",
                                                                                                         {-20.f, -50.f},
                                                                                                         rotationOffset),
                                                                                           mShooterFour(owningActor,
                                                                                                        coolDownTime,
                                                                                                        "SpaceShooterRedux/PNG/Lasers/laserGreen11.png",
                                                                                                        {20.f, -50.f},
                                                                                                        rotationOffset) {}

    void FrontalWiper::ShootImpl() {
        mShooterOne.ShootImpl();
        mShooterTwo.ShootImpl();
        mShooterThree.ShootImpl();
        mShooterFour.ShootImpl();
    }
}