//
// Created by ghima on 22-07-2024.
//
#include <utility>

#include "gameplay/Rewards.h"
#include "Player/PlayerSpaceShip.h"
#include "frameWork/World.h"
#include "weapons/ThreeWayShooter.h"
#include "weapons/FrontalWipper.h"

namespace ly {
    Rewards::Rewards(ly::World *owningWorld, std::string texturePath, RewardCallback rewardCallback,
                     float speed) : Actor(owningWorld, texturePath), mRewardCallback(rewardCallback),
                                    mSpeed{speed} {}

    void Rewards::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        AddActorLocationOffset(sf::Vector2f{0, 1} * deltaTime * mSpeed);
    }

    void Rewards::BeginContact(ly::Actor *otherActor) {
        Actor::BeginContact(otherActor);
        PlayerSpaceShip *player = dynamic_cast<PlayerSpaceShip *>(otherActor);
        if (player == nullptr || player->isPendingDestroy()) return;
        mRewardCallback(player);
        Actor::RemovePhysicsBody();
        Actor::Destroy();
    }


    weak<Rewards> CreateHealthReward(World *owningWorld) {
        weak<Rewards> reward = owningWorld->SpawnActor<Rewards, std::string, RewardCallback>(
                std::string{"SpaceShooterRedux/PNG/pickups/pill_green.png"},
                HealthReward);
        reward.lock()->id = 1;
        return reward;
    }

    void HealthReward(PlayerSpaceShip *player) {
        player->OnChangeHealth(10.f);
    }

    weak<Rewards> CreateThreeWayShooterReward(World *owningWorld) {
        weak<Rewards> reward = owningWorld->SpawnActor<Rewards, std::string, RewardCallback>(
                std::string{"SpaceShooterRedux/PNG/pickups/three_shooter_pickup.png"},
                ThreeWayShooterReward);
        reward.lock()->id = 1;
        return reward;
    }

    void ThreeWayShooterReward(PlayerSpaceShip *player) {
        player->SetShooter(new ThreeWayShooter{player});
    }

    weak<Rewards> CreateFrontalWiperReward(World *owningWorld) {
        weak<Rewards> reward = owningWorld->SpawnActor<Rewards, std::string, RewardCallback>(
                std::string{"SpaceShooterRedux/PNG/pickups/front_row_shooter_pickup.png"},
                FrontalWiperReward);
        reward.lock()->id = 1;
        return reward;
    }

    void FrontalWiperReward(PlayerSpaceShip *player) {
        player->SetShooter(new FrontalWiper{player});
    }
}