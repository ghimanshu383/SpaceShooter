//
// Created by ghima on 20-07-2024.
//
#include "gameplay/VanguardStage.h"
#include <frameWork/World.h>
#include <frameWork/TimerManager.h>

#include "Enemy/Vanguard.h"
#include "Enemy/HexGuard.h"

namespace ly {
    VanguardStage::VanguardStage(ly::World *world) : GameStage(world),
                                                     mSpawnInterval{1.5f},
                                                     mRowSwitchInterval{1.f},
                                                     mSpawnDistanceToEdge{100.f},
                                                     mSpawnLoc{0.0f, 0.0f},
                                                     mRightLoc(),
                                                     mLeftLoc(),
                                                     mRowsToSpawn{3},
                                                     mRowCount{0},
                                                     mVanGuardPerRow{5},
                                                     mCurrentRowVanGuardCount{0},
                                                     mSpawnTimerId{0} {}

    void VanguardStage::SpawnVanguard() {
        if (mVanGuardPerRow == mCurrentRowVanGuardCount) {
            TimerManager::GetInstance()->CleanUpTimer(mSpawnTimerId);
            mCurrentRowVanGuardCount = 0;
            TimerManager::GetInstance()->SetTimer(GetWeakRef(), &VanguardStage::SwitchRow,
                                                  mSpawnInterval, false);
            //  SwitchRow();

        } else {
            weak <Vanguard> vanguard = GetWorld()->SpawnActor<Vanguard>();
            vanguard.lock()->SetActorLocation(mSpawnLoc);
            vanguard.lock()->SetActorRotation(90.f);
            mCurrentRowVanGuardCount++;
        }
    }

    void VanguardStage::SwitchRow() {
        if (mRowsToSpawn == mRowCount) {
            EndState();
            return;
        }

        if (mSpawnLoc == mLeftLoc) {
            mSpawnLoc = mRightLoc;
        } else {
            mSpawnLoc = mLeftLoc;
        }
        mSpawnTimerId = TimerManager::GetInstance()->SetTimer(GetWeakRef(),
                                                              &VanguardStage::SpawnVanguard,
                                                              mSpawnInterval,
                                                              true);
        ++mRowCount;

    }

    void VanguardStage::FinishStageHandler() {
        TimerManager::GetInstance()->CleanUpTimer(mSpawnTimerId);
    }

    void VanguardStage::StartStage() {
        auto windowSize = GetWorld()->GetWindowSize();
        mLeftLoc = sf::Vector2f{mSpawnDistanceToEdge, -100.f};
        mRightLoc = sf::Vector2f{windowSize.x - mSpawnDistanceToEdge, -100.f};

        mSpawnLoc = mLeftLoc;

        SwitchRow();
    }
}