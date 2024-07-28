//
// Created by ghima on 27-07-2024.
//
#include <frameWork/World.h>

#include "Enemy/Boss.h"
#include "weapons/BulletShooter.h"

namespace ly {
    Boss::Boss(ly::World *owningWorld, std::string texturePath, sf::Vector2f velocity, float speed) : EnemySpaceShip(
            owningWorld, texturePath), mVelocity{velocity}, mSpeed{speed}, mShooterOne(
            new BulletShooter{this, 2.f, "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                              {0, 150}}) {}

    void Boss::Shoot() {
        mShooterOne->ShootImpl();
    }

    void Boss::Tick(float DeltaTime) {
        EnemySpaceShip::Tick(DeltaTime);
        if (GetActorLocation().y < 250.f) {
            AddActorLocationOffset(mVelocity * mSpeed * DeltaTime);
            return;
        }
        if (mVelocity.y > 0) {
            mVelocity = {1, 0};
        }
        auto windowSize = GetOwningWorld()->GetWindowSize();
        if (GetActorLocation().x > windowSize.x - 100.f) {
            mVelocity = {-1, 0};
        } else if (GetActorLocation().x <= 100.f) {
            mVelocity = {1, 0};
        }
        AddActorLocationOffset(mVelocity * mSpeed * DeltaTime);
    }

    void Boss::Blow() {
        mEndStageDelegate.Invoke();
        EnemySpaceShip::Blow();
    }
}