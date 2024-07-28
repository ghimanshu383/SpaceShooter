//
// Created by ghima on 20-07-2024.
//
#include "frameWork/GameStage.h"
#include "frameWork/World.h"
#include "frameWork/TimerManager.h"

namespace ly {
    GameStage::GameStage(ly::World *world, float waitTime) : mWorld{world}, mIsStageFinished{false}, mWaitTimeId{0},
                                                             mWaitTime{waitTime} {};

    void GameStage::StartStage() {
        // For default adding the wait time;
        TimerManager::GetInstance()->SetTimer(GetWeakRef(), &GameStage::EndState, mWaitTime, false);

    }

    void GameStage::TickStage(float deltaTime) {
    }

    void GameStage::EndState() {
        mIsStageFinished = true;
        FinishStageHandler();           // This function can be overwritten by the child class to make extra clean up or other stuff.
        finishStageDelegate.Invoke();
    }

    World *GameStage::GetWorld() const {
        return mWorld;
    }

    void GameStage::FinishStageHandler() {
        TimerManager::GetInstance()->CleanUpTimer(mWaitTimeId);
    }

    bool GameStage::IsFinished() const {
        return mIsStageFinished;
    }
}