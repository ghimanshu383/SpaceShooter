//
// Created by ghima on 22-07-2024.
//
#include <functional>
#include <frameWork/Actor.h>

#ifndef LIGHTYEARS_REWARDS_H
#define LIGHTYEARS_REWARDS_H
namespace ly {
    class PlayerSpaceShip;

    class World;

    using RewardCallback = void (*)(PlayerSpaceShip *);

    class Rewards : public Actor {
    public:
        Rewards(World *owningWorld, std::string texturePath, RewardCallback rewardCallback, float speed = 200.f);

        virtual void Tick(float deltaTime) override;

        virtual void BeginContact(Actor *otherActor) override;


    private:
        RewardCallback mRewardCallback;
        float mSpeed;
    };

    weak<Rewards> CreateHealthReward(World *owningWorld);

    void HealthReward(PlayerSpaceShip *player);

    weak<Rewards> CreateThreeWayShooterReward(World *owningWorld);

    void ThreeWayShooterReward(PlayerSpaceShip *player);

    weak<Rewards> CreateFrontalWiperReward(World *owningWorld);

    void FrontalWiperReward(PlayerSpaceShip *player);
}
#endif //LIGHTYEARS_REWARDS_H
