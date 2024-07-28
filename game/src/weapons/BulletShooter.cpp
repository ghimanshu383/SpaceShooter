//
// Created by ghima on 17-07-2024.
//
#include <frameWork/Actor.h>

#include <utility>
#include "weapons/BulletShooter.h"

namespace ly {
    BulletShooter::BulletShooter(Actor *owningActor, float cooldownTime, std::string bulletTexture,
                                 const sf::Vector2f &locationOffset, float rotationOffset) : Shooter(
            owningActor), mCoolDownClock(),
                                                                                             mCoolDownInterval{
                                                                                                     cooldownTime},
                                                                                             mOwningActor{
                                                                                                     owningActor},
                                                                                             mBulletTexture{
                                                                                                     std::move(
                                                                                                             bulletTexture)},
                                                                                             mLocalOffset(
                                                                                                     locationOffset),
                                                                                             mRotationOffset{
                                                                                                     rotationOffset} {
    }

    void BulletShooter::ShootImpl() {
        if (CanShoot() && !IsOnCoolDown()) {
            weak<Bullet> bullet = mOwningActor->GetOwningWorld()->SpawnActor<Bullet, Actor *, std::string>(mOwningActor,
                                                                                                           mBulletTexture);
            bullet.lock()->AddActorLocationOffset(mLocalOffset);
          //  bullet.lock()->SetActorRotation(mRotationOffset);
            bullet.lock()->SetRotateOffset(mRotationOffset);
            mCoolDownClock.restart();
        }
    }

    bool BulletShooter::CanShoot() {
        return true;
    }

    bool BulletShooter::IsOnCoolDown() {
        if (mCoolDownClock.getElapsedTime().asSeconds() < mCoolDownInterval) {
            return true;
        }
        return false;
    }
}