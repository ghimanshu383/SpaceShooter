//
// Created by ghima on 20-07-2024.
//
#include <frameWork/GameStage.h>
#include <SFML/Graphics.hpp>

#ifndef LIGHTYEARS_TWINBLADESTAGE_H
#define LIGHTYEARS_TWINBLADESTAGE_H
namespace ly {
    class World;

    class TwinBladeStage : public GameStage {
    public:
        TwinBladeStage(World *owningWorld);

        virtual void StartStage() override;

        virtual void FinishStageHandler() override;

    private:
        float mSpawnInterval;
        float mSpawnDistanceToCenter;

        sf::Vector2f mRightLoc;
        sf::Vector2f mLeftLoc;
        sf::Vector2f mSpawnLoc;

        int mSpawnAmt;
        int mCurrentSpawnCount;

        unsigned int mSpawnTimerId;

        void SpawnTwinBlade();

    };
}
#endif //LIGHTYEARS_TWINBLADESTAGE_H
