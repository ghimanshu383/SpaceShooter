//
// Created by ghima on 19-07-2024.
//
#include "frameWork/Actor.h"

#ifndef LIGHTYEARS_PARTICLE_H
#define LIGHTYEARS_PARTICLE_H
namespace ly {
    class Particle : public Actor {
    public:
        Particle(World *owningWorld, std::string texturePath, float lifeTimeMin, float lifeTimeMax, float speedMin,
                 float speedMax, float sizeMin, float sizeMax, sf::Color color);

        virtual void Tick(float deltaTime) override;

        virtual void BeginPlay() override;

        void RandomVelocity(float minSpeed, float maxSpeed);

        void RandomSize(float min, float max);

        void RandomLifeTime(float min, float max);

    private:
        sf::Clock mTimer;
        sf::Vector2f mVelocity;
        float mLifeTime;
        float speedMin, speedMax;
        float sizeMin, sizeMax;
        float lifeTimeMin, lifeTimeMax;
        sf::Color mColor;

        void Move(float deltaTime);

        void Fade(float);
    };
}
#endif //LIGHTYEARS_PARTICLE_H
