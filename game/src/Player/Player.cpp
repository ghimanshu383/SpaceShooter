//
// Created by ghima on 23-07-2024.
//
#include <frameWork/World.h>
#include "Player/Player.h"
#include "Player/PlayerSpaceShip.h"

namespace ly {
    Player *Player::instance = nullptr;

    Player::Player() : mLifeCount{3}, mCurrentLifeCount{0}, score{0}, mCurrentSpaceShip() {
    }

    Player *Player::GetInstance() {
        if (instance == nullptr) {
            instance = new Player();
        }
        return instance;
    }

    void Player::SpawnSpaceShip(ly::World *owningWorld) {
        if (mCurrentLifeCount < mLifeCount) {
            mCurrentSpaceShip = owningWorld->SpawnActor<PlayerSpaceShip>();
            mCurrentSpaceShip.lock()->SetActorLocation(
                    {(float) owningWorld->GetWindowSize().x / 2, owningWorld->GetWindowSize().y - 100.f});
            mCurrentSpaceShip.lock()->SetActorRotation(-90.f);
            mCurrentSpaceShip.lock()->id = 1;
            mCurrentLifeCount++;
        } else {
            EndGame();
        }
    }

    void Player::EndGame() {
        Log("the Game Ended All lives exhaused");
    }
}