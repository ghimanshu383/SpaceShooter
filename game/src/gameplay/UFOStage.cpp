//
// Created by ghima on 22-07-2024.
//
#include <frameWork/TimerManager.h>
#include <frameWork/World.h>
#include <frameWork/MathUtil.h>

#include "gameplay/UFOStage.h"
#include "Enemy/UFO.h"
#include "frameWork/Actor.h"


namespace ly {
    UFOStage::UFOStage(ly::World *owningWorld) : GameStage(owningWorld), mTimerId{0}, mUFOCount{10},
                                                 mUFOCurrentCount{0} {}

    void UFOStage::StartStage() {
        mTimerId = TimerManager::GetInstance()->SetTimer(GetWeakRef(), &UFOStage::SpawnUFO, 1.f, true);
    }

    void UFOStage::FinishStageHandler() {
        TimerManager::GetInstance()->CleanUpTimer(mTimerId);
    }

    void UFOStage::SpawnUFO() {
        if (mUFOCurrentCount >= mUFOCount) {
            EndState();
            return;
        }
        sf::Vector2f randomLoc = GetRandomLocation();
        weak<UFO> ufo = GetWorld()->SpawnActor<UFO>();

        if (randomLoc.x >= (float) GetWorld()->GetWindowSize().x - 100.f) {
            ufo.lock()->SetVelocity(sf::Vector2f{-1.f, .2f});
        } else if (randomLoc.x <= 0.f) {
            ufo.lock()->SetVelocity(sf::Vector2f{1.f, .2f});
        }
        ufo.lock()->SetActorLocation(randomLoc);
        mUFOCurrentCount++;
    }

    sf::Vector2f UFOStage::GetRandomLocation() {
        float randomY = RandomRange(100.f, (float) GetWorld()->GetWindowSize().y / 1.5f);
        float randomX = RandomRange(-1.f, 1.f);
        if (randomX >= 0) {
            return {(float) GetWorld()->GetWindowSize().x + 0.f, randomY};
        } else {
            return {0.f, randomY};
        }
    }
}