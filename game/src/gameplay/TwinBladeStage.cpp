//
// Created by ghima on 20-07-2024.
//
#include "gameplay/TwinBladeStage.h"
#include <frameWork/World.h>

#include "Enemy/TwinBlade.h"
#include <frameWork/TimerManager.h>

namespace ly {
    TwinBladeStage::TwinBladeStage(ly::World *owningWorld) : GameStage(owningWorld), mSpawnInterval{.5f},
                                                             mSpawnDistanceToCenter{100.f},
                                                             mRightLoc(owningWorld->GetWindowSize().x / 2 +
                                                                       mSpawnDistanceToCenter, -100.f),
                                                             mLeftLoc(owningWorld->GetWindowSize().x / 2 -
                                                                      mSpawnDistanceToCenter, -100.f),
                                                             mSpawnLoc(mLeftLoc), mSpawnAmt{5},
                                                             mCurrentSpawnCount{0}, mSpawnTimerId{0} {}

    void TwinBladeStage::StartStage() {
        mSpawnTimerId = TimerManager::GetInstance()->SetTimer(GetWeakRef(), &TwinBladeStage::SpawnTwinBlade, 1.f, true);
    }

    void TwinBladeStage::FinishStageHandler() {
        TimerManager::GetInstance()->CleanUpTimer(mSpawnTimerId);
    }

    void TwinBladeStage::SpawnTwinBlade() {
        if (mCurrentSpawnCount > mSpawnAmt) {
            EndState();
        }
        if (mSpawnLoc == mRightLoc) {
            mSpawnLoc = mLeftLoc;
        } else {
            mSpawnLoc = mRightLoc;
        }
        weak<TwinBlade> twinBlade = GetWorld()->SpawnActor<TwinBlade>();
        twinBlade.lock()->SetActorRotation(90.f);
        twinBlade.lock()->SetActorLocation(mSpawnLoc);
        ++mCurrentSpawnCount;
    }

}