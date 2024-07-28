//
// Created by ghima on 25-07-2024.
//
#include <frameWork/TimerManager.h>
#include <frameWork/World.h>
#include <frameWork/MathUtil.h>

#include "gameplay/ChaosStage.h"
#include "Enemy/Vanguard.h"
#include "Enemy/TwinBlade.h"
#include "Enemy/HexGuard.h"
#include "Enemy/UFO.h"

namespace ly {
    ChaosStage::ChaosStage(ly::World *owningWorld) : GameStage(owningWorld), mSpawnInterval{1.f},
                                                     mMinSpawnInterval{.4f}, mSpawnIntervalDecFactor{.1f},
                                                     mSpawnIntervalDecFactorInterval{2.f}, mStageDuration{10.f},
                                                     mDifficultyTimer{0}, mSpawnTimer{0}, mTimerClock() {

    }

    void ChaosStage::StartStage() {
        mTimerClock.restart();
        mSpawnTimer = TimerManager::GetInstance()->SetTimer(GetWeakRef(), &ChaosStage::SpawnVanguard, mSpawnInterval,
                                                            false);
        mDifficultyTimer = TimerManager::GetInstance()->SetTimer(GetWeakRef(), &ChaosStage::IncreaseDifficulty,
                                                                 mSpawnIntervalDecFactorInterval, true);

    }

    void ChaosStage::SpawnVanguard() {
        if (mTimerClock.getElapsedTime().asSeconds() > mStageDuration) {
            EndState();
            return;
        }
        weak<Vanguard> vanguard = GetWorld()->SpawnActor<Vanguard>();
        vanguard.lock()->SetActorLocation(GetRandomLocationTop());
        vanguard.lock()->SetActorRotation(90.f);
        TimerManager::GetInstance()->SetTimer(GetWeakRef(), &ChaosStage::SpawnTwinBlade, mSpawnInterval, false);
    }

    void ChaosStage::SpawnTwinBlade() {
        weak<TwinBlade> twinBlade = GetWorld()->SpawnActor<TwinBlade>();
        twinBlade.lock()->SetActorLocation(GetRandomLocationTop());
        twinBlade.lock()->SetActorRotation(90.f);
        TimerManager::GetInstance()->SetTimer(GetWeakRef(), &ChaosStage::SpawnHexGuard, mSpawnInterval);
    }

    void ChaosStage::SpawnHexGuard() {
        weak<HexGuard> hexGuard = GetWorld()->SpawnActor<HexGuard>();
        hexGuard.lock()->SetActorLocation(GetRandomLocationTop());
        hexGuard.lock()->SetActorRotation(90.f);
        TimerManager::GetInstance()->SetTimer(GetWeakRef(), &ChaosStage::SpawnUFO, mSpawnInterval);
    }

    void ChaosStage::SpawnUFO() {

        weak<UFO> ufo = GetWorld()->SpawnActor<UFO>();
        sf::Vector2f randomLocation = GetRandomLocationSide();
        ufo.lock()->SetActorLocation(randomLocation);
        auto windowSize = GetWorld()->GetWindowSize();
        if (randomLocation.x > (float) windowSize.x - 100.f) {
            ufo.lock()->SetVelocity({-1, 0});
        }else {
            ufo.lock()->SetVelocity({1, 0});
        }

        ufo.lock()->SetActorRotation(90.f);
        mSpawnTimer = TimerManager::GetInstance()->SetTimer(GetWeakRef(), &ChaosStage::SpawnVanguard, mSpawnInterval,
                                                            false);
    }

    void ChaosStage::FinishStageHandler() {
        TimerManager::GetInstance()->CleanUpTimer(mSpawnTimer);
        TimerManager::GetInstance()->CleanUpTimer(mDifficultyTimer);
    }


    void ChaosStage::IncreaseDifficulty() {
        mSpawnInterval -= mSpawnIntervalDecFactor;
        if (mSpawnInterval < mMinSpawnInterval) {
            mSpawnInterval = mMinSpawnInterval;
        }
    }

    sf::Vector2f ChaosStage::GetRandomLocationTop() {
        auto windowSize = GetWorld()->GetWindowSize();
        float spawnX = RandomRange(100.f, (float) windowSize.x - 100.f);
        float spawnY = -100.f;

        return {spawnX, spawnY};
    }

    sf::Vector2f ChaosStage::GetRandomLocationSide() {
        float randomY = RandomRange(100.f, GetWorld()->GetWindowSize().y / 1.5f);
        float randomX = RandomRange(-1.f, 1.f);
        if (randomX >= 0) {
            return {(float) GetWorld()->GetWindowSize().x + 0.f, randomY};
        } else {
            return {0.f, randomY};
        }
    }

    void ChaosStage::SpawnEnemy() {
    }
}