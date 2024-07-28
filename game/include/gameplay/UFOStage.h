//
// Created by ghima on 22-07-2024.
//
#include <frameWork/GameStage.h>
#include <SFML/Graphics.hpp>

#ifndef LIGHTYEARS_UFOSTAGE_H
#define LIGHTYEARS_UFOSTAGE_H
namespace ly {
    class World;

    class UFOStage : public GameStage {
    public:
        UFOStage(World *owningWorld);

        virtual void StartStage() override;

        virtual void FinishStageHandler() override;

    private:
        int mUFOCount;
        int mUFOCurrentCount;

        sf::Vector2f GetRandomLocation();

        void SpawnUFO();

        unsigned int mTimerId;

    };
}
#endif //LIGHTYEARS_UFOSTAGE_H
