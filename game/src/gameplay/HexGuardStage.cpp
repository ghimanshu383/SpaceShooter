//
// Created by ghima on 20-07-2024.
//
#include "frameWork/TimerManager.h"

#include "gameplay/HexGuardStage.h"
#include "frameWork/World.h"
#include "Enemy/HexGuard.h"

namespace ly {
    HexGuardStage::HexGuardStage(ly::World *owningWorld) : GameStage(owningWorld), mGroups(4), mGroupGuardCount{3},
                                                           mCurrentGuardCount{0}, mOffset{20.f},
                                                           mCenterLoc({owningWorld->GetWindowSize().x / 2.f,
                                                                       -50.f}),
                                                           mRightLoc({mCenterLoc.x + 5 * mOffset,
                                                                      mCenterLoc.y - 5 * mOffset}),
                                                           mLeftLoc({mCenterLoc.x - 5 * mOffset,
                                                                     mCenterLoc.y - 5 * mOffset}),
                                                           mTimerId{0} {

    }

    void HexGuardStage::StartStage() {
        mTimerId = TimerManager::GetInstance()->SetTimer(GetWeakRef(), &HexGuardStage::SpawnHexGuard, 3.f, true);
    }

    void HexGuardStage::FinishStageHandler() {
        TimerManager::GetInstance()->CleanUpTimer(mTimerId);
    }

    void HexGuardStage::SpawnHexGuard() {
        if (mCurrentGuardCount >= mGroups * mGroupGuardCount) {
            EndState();
            return;
        }
        weak<HexGuard> One = GetWorld()->SpawnActor<HexGuard>();
        One.lock()->SetActorLocation(mCenterLoc);
        One.lock()->SetActorRotation(90.f);
        weak<HexGuard> two = GetWorld()->SpawnActor<HexGuard>();
        two.lock()->SetActorLocation(mRightLoc);
        two.lock()->SetActorRotation(90.f);
        weak<HexGuard> three = GetWorld()->SpawnActor<HexGuard>();
        three.lock()->SetActorLocation(mLeftLoc);
        three.lock()->SetActorRotation(90.f);

        mCurrentGuardCount += 3;
    }
}