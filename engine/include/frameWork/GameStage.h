//
// Created by ghima on 20-07-2024.
//
#include "Object.h"
#include "frameWork/Delegate.h"

#ifndef LIGHTYEARS_GAMEPLAY_H
#define LIGHTYEARS_GAMEPLAY_H
namespace ly {
    class World;

    class GameStage : public Object {
    public:
        explicit GameStage(World *world, float waitTime = 2.f);

        World *GetWorld() const;

        virtual void StartStage();

        virtual void TickStage(float deltaTime);

        virtual void EndState();

        bool IsFinished() const;

        Delegate<> finishStageDelegate;

        virtual void FinishStageHandler();

    private:
        World *mWorld;
        bool mIsStageFinished;
        unsigned int mWaitTimeId;
        float mWaitTime;
    };
}
#endif //LIGHTYEARS_GAMEPLAY_H
