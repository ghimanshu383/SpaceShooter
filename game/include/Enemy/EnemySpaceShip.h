//
// Created by ghima on 19-07-2024.
//
#include "SpaceShip/SpaceShip.h"

#ifndef LIGHTYEARS_ENEMYSPACESHIP_H
#define LIGHTYEARS_ENEMYSPACESHIP_H
namespace ly {
    class Rewards;

    class World;

    class BulletShooter;

    class EnemySpaceShip : public SpaceShip {
    public:
        EnemySpaceShip(World *owningWorld, std::string &texturePath, float collisionDamage = 200.f);

        virtual void Shoot() override;

        virtual void Tick(float deltaTime) override;

        virtual void BeginContact(Actor *other);

        virtual void Blow() override;


    protected:
        float mCollisionDamage;
        shared<BulletShooter> bulletShooter;
        List<weak<Rewards> (*)(World *)> rewardCallbacks;
    };
}
#endif //LIGHTYEARS_ENEMYSPACESHIP_H
