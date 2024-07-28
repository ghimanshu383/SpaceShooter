//
// Created by ghima on 27-07-2024.
//
#include <frameWork/GameStage.h>

#ifndef LIGHTYEARS_BOSSSTAGE_H
#define LIGHTYEARS_BOSSSTAGE_H
namespace ly {
    class World;

    class BossStage : public GameStage {
    public:
        BossStage(World *owningWorld);

        virtual void StartStage() override;

        virtual void FinishStageHandler() override;
    };
}
#endif //LIGHTYEARS_BOSSSTAGE_H
