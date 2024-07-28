//
// Created by ghima on 20-07-2024.
//
#include "Enemy/TwinBlade.h"
#include "weapons/BulletShooter.h"

namespace ly {
    TwinBlade::TwinBlade(ly::World *owningWorld, std::string texturePath, sf::Vector2f velocity, float speed)
            : EnemySpaceShip(owningWorld, texturePath),
              mVelocity(velocity),
              mSpeed(speed),
              mShooterOne(
                      new BulletShooter{this, .5f,
                                        "SpaceShooterRedux/PNG/Lasers/laserRed01.png", {-20.f, 50.f}}),
              mShooterTwo(new BulletShooter{this, .5f,
                                            "SpaceShooterRedux/PNG/Lasers/laserRed01.png", {20.f, 50.f}}) {
    }

    void TwinBlade::Shoot() {
        mShooterOne->ShootImpl();
        mShooterTwo->ShootImpl();
    }

    void TwinBlade::Tick(float deltaTime) {
        EnemySpaceShip::Tick(deltaTime);
        AddActorLocationOffset(mVelocity * deltaTime * mSpeed);
    }

}


