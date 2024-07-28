//
// Created by ghima on 17-07-2024.
//

#include <frameWork/Actor.h>
#include "vfx/Explosion.h"

#ifndef LIGHTYEARS_SPACESHIP_H
#define LIGHTYEARS_SPACESHIP_H
namespace ly {
    class HealthComponent;

    class SpaceShip : public Actor {
    public :
        SpaceShip(World *owningWorld, std::string &texturePath);

        virtual void Tick(float deltaTime) override;

        void SetVelocity(sf::Vector2f velocity);

        sf::Vector2f GetVelocity() const;

        virtual void OnChangeHealth(float amt) override;

        virtual void OnTakeDamage(float amt);

        virtual void Blow();

        virtual void Destroy() override;

        // Animations;
        void Blink();

        void UpdateBlink(float deltaTime);

    protected:
        virtual void Shoot() = 0;

    private:
        sf::Vector2f mVelocity;
        shared<HealthComponent> mHealthComponent;
        float mBlinkTime;
        float mBlinkDuration;
        sf::Color mBlinkColor;
        Explosion explosion;
    };
}
#endif //LIGHTYEARS_SPACESHIP_H
