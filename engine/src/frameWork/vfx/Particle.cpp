//
// Created by ghima on 19-07-2024.
//
#include "frameWork/vfx/Particle.h"
#include "frameWork/MathUtil.h"

namespace ly {
    Particle::Particle(ly::World *owningWorld, std::string texturePath, float lifeTimeMin, float lifeTimeMax,
                       float speedMin, float speedMax, float sizeMin, float sizeMax, sf::Color color) : Actor(
            owningWorld, texturePath),
                                                                                                        mTimer(),
                                                                                                        mVelocity(),
                                                                                                        mLifeTime{},
                                                                                                        lifeTimeMin{
                                                                                                                lifeTimeMin},
                                                                                                        lifeTimeMax{
                                                                                                                lifeTimeMax},
                                                                                                        speedMin{
                                                                                                                speedMin},
                                                                                                        speedMax{
                                                                                                                speedMax},
                                                                                                        sizeMax{sizeMax},
                                                                                                        sizeMin{sizeMin},
                                                                                                        mColor{color} {}

    void Particle::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        Move(deltaTime);
        Fade(deltaTime);

        if (mTimer.getElapsedTime().asSeconds() > mLifeTime) {
            Destroy();
        }
    }

    void Particle::BeginPlay() {
        RandomVelocity(speedMin, speedMax);
        RandomSize(sizeMin, sizeMax);
        RandomLifeTime(lifeTimeMin, lifeTimeMax);
        mSprite.setColor(mColor);
    }

    void Particle::RandomVelocity(float minSpeed, float maxSpeed) {
        mVelocity = RandomUnitVector() * RandomRange(minSpeed, maxSpeed);
    }

    void Particle::RandomSize(float min, float max) {
        float randomScale = RandomRange(min, max);
        mSprite.setScale(randomScale, randomScale);
    }

    void Particle::RandomLifeTime(float min, float max) {
        mLifeTime = RandomRange(min, max);
    }

    void Particle::Move(float deltaTime) {
        AddActorLocationOffset(mVelocity * deltaTime);
    }

    void Particle::Fade(float deltaTime) {
        float elapsedTime = mTimer.getElapsedTime().asSeconds();
        mSprite.setColor(LerpColor(mSprite.getColor(), sf::Color{255, 255, 255, 0}, elapsedTime / mLifeTime));
        mSprite.setScale(LerpVector<float>(mSprite.getScale(), sf::Vector2f{0, 0}, elapsedTime / mLifeTime));

    }
}