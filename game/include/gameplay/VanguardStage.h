//
// Created by ghima on 20-07-2024.
//
#include <SFML/Graphics.hpp>

#include "frameWork/GameStage.h"

#ifndef LIGHTYEARS_VANGUARDSTAGE_H
#define LIGHTYEARS_VANGUARDSTAGE_H
namespace ly {
    class World;

    class VanguardStage : public GameStage {
    public:
        VanguardStage(World *world);

        virtual void StartStage() override;

        virtual void FinishStageHandler() override;

        void SpawnVanguard();

        void SwitchRow();

    private:
        float mSpawnInterval;
        float mRowSwitchInterval;
        float mSpawnDistanceToEdge;

        sf::Vector2f mRightLoc;
        sf::Vector2f mLeftLoc;
        sf::Vector2f mSpawnLoc;

        unsigned int mSpawnTimerId;

        int mRowsToSpawn;
        int mRowCount;

        int mVanGuardPerRow;
        int mCurrentRowVanGuardCount;


    };
}
#endif //LIGHTYEARS_VANGUARDSTAGE_H
