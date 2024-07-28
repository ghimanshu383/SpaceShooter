//
// Created by ghima on 20-07-2024.
//
#include <SFML/Graphics.hpp>
#include <frameWork/GameStage.h>

#ifndef LIGHTYEARS_HEXGUARDSTAGE_H
#define LIGHTYEARS_HEXGUARDSTAGE_H
namespace ly {
    class World;

    class HexGuardStage : public GameStage {
    public:
        HexGuardStage(World *owningWorld);

        virtual void StartStage() override;

        virtual void FinishStageHandler() override;

    private:
        int mGroups;
        int mGroupGuardCount;
        int mCurrentGuardCount;
        float mOffset;

        sf::Vector2f mCenterLoc;
        sf::Vector2f mRightLoc;
        sf::Vector2f mLeftLoc;

        unsigned int mTimerId;

        void SpawnHexGuard();
    };
}
#endif //LIGHTYEARS_HEXGUARDSTAGE_H
