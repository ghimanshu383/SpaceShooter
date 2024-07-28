//
// Created by ghima on 19-07-2024.
//
#include "Enemy/EnemySpaceShip.h"
#include "weapons/BulletShooter.h"
#include "gamePlay/Rewards.h"
#include "frameWork/MathUtil.h"

namespace ly {
    EnemySpaceShip::EnemySpaceShip(World *owningWorld, std::string &texturePath, float damage) : SpaceShip(owningWorld,
                                                                                                           texturePath),
                                                                                                 mCollisionDamage{
                                                                                                         damage},
                                                                                                 bulletShooter(
                                                                                                         new BulletShooter{
                                                                                                                 this,
                                                                                                                 .5f,
                                                                                                                 "SpaceShooterRedux/PNG/Lasers/laserRed01.png",
                                                                                                                 {0.f,
                                                                                                                  50.f}}),
                                                                                                 rewardCallbacks{
                                                                                                         CreateHealthReward,
                                                                                                         CreateThreeWayShooterReward,
                                                                                                         CreateFrontalWiperReward
                                                                                                 } {

    }

    void EnemySpaceShip::Tick(float deltaTime) {
        UpdateBlink(deltaTime);
        Shoot();
        if (IsOutOfBounds(GetActorGlobalBounds().height)) {
            SpaceShip::Destroy();
        }
    }

    void EnemySpaceShip::Shoot() {
        bulletShooter->ShootImpl();
    }

    void EnemySpaceShip::BeginContact(ly::Actor *other) {
        Actor::BeginContact(other);
        if (CheckOtherHostile(other)) {
            Blink();
            other->OnChangeHealth(-mCollisionDamage);
        }
    }

    void EnemySpaceShip::Blow() {
        int random = std::floor(RandomRange(0, rewardCallbacks.size() - .1f));
        weak<Rewards> reward = rewardCallbacks[random](mWorld);
        reward.lock()->SetActorLocation(Actor::GetActorLocation());
        SpaceShip::Blow();
    }
}


