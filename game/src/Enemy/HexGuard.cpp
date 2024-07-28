//
// Created by ghima on 20-07-2024.
//
#include "Enemy/HexGuard.h"
#include "weapons/BulletShooter.h"

namespace ly {
    HexGuard::HexGuard(ly::World *owningWorld, std::string texturePath, sf::Vector2f velocity, float speed)
            : EnemySpaceShip(owningWorld, texturePath), mVelocity{velocity}, mSpeed{speed},
              mShooterOne{new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                                            {50, 20.f}, -30}},
              mShooterTwo{new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
                                            {-50, 20.f}, 30}},
              mShooterThree{new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserGreen11.png",
                                              {0, 50.f}, 0}},
              mShooterFour{new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
                                             {0, -50.f}, 180}},
              mShooterFive{new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserGreen11.png",
                                             {50, -20.f}, -120}},
              mShooterSix{new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                                            {-50, -20.f}, 120}} {}

    void HexGuard::Shoot() {
        mShooterOne->ShootImpl();
        mShooterTwo->ShootImpl();
        mShooterThree->ShootImpl();
        mShooterFour->ShootImpl();
        mShooterFive->ShootImpl();
        mShooterSix->ShootImpl();
    }

    void HexGuard::Tick(float deltaTime) {
        EnemySpaceShip::Tick(deltaTime);
        AddActorLocationOffset(mVelocity * deltaTime * mSpeed);
    }
}