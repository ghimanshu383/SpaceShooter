//
// Created by ghima on 25-07-2024.
//
#include <SFML/Graphics.hpp>
#include <frameWork/GameStage.h>

#ifndef LIGHTYEARS_CHAOSSTAGE_H
#define LIGHTYEARS_CHAOSSTAGE_H
namespace ly {
    class World;

    class ChaosStage : public GameStage {
    public :
        ChaosStage(World *owningWorld);

        virtual void StartStage() override;

        virtual void FinishStageHandler() override;

        void SpawnEnemy();


    private:
        float mSpawnInterval;
        float mMinSpawnInterval;
        float mSpawnIntervalDecFactor;
        float mSpawnIntervalDecFactorInterval;

        float mStageDuration;

        unsigned int mSpawnTimer;
        unsigned int mDifficultyTimer;

        sf::Clock mTimerClock;

        void SpawnVanguard();

        void SpawnTwinBlade();

        void SpawnHexGuard();

        void SpawnUFO();

        void IncreaseDifficulty();

        sf::Vector2f GetRandomLocationTop();

        sf::Vector2f GetRandomLocationSide();
    };
}
#endif //LIGHTYEARS_CHAOSSTAGE_H
