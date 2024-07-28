//
// Created by ghima on 17-07-2024.
//

#include <utility>
#include <frameWork/MathUtil.h>

#include "SpaceShip/SpaceShip.h"
#include "gameplay/HealthComponent.h"

namespace ly {
    SpaceShip::SpaceShip(ly::World *owningWorld, std::string &texturePath) : Actor(owningWorld, texturePath),
                                                                             mVelocity(), mHealthComponent{
                    new HealthComponent{100.f, 100.f}},
                                                                             mBlinkTime{0.f}, mBlinkDuration{.2f},
                                                                             mBlinkColor({255, 0, 0, 255}),
                                                                             explosion(200.f, 1.f) {
        mHealthComponent->mHealthDelegate.Register(this, &SpaceShip::OnTakeDamage);
        mHealthComponent->mHealthEmptyDelegate.Register(this, &SpaceShip::Blow);
    }

    void SpaceShip::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        Actor::AddActorLocationOffset(GetVelocity() * deltaTime);
        UpdateBlink(deltaTime);
    }

    void SpaceShip::SetVelocity(sf::Vector2f velocity) {
        mVelocity = velocity;
    }

    sf::Vector2f SpaceShip::GetVelocity() const {
        return mVelocity;
    }

    void SpaceShip::OnChangeHealth(float amt) {
        mHealthComponent->ChangeHealth(amt);
    }

    void SpaceShip::OnTakeDamage(float amt) {
        Log("Now Taking the damage");
        Blink();
    }

    void SpaceShip::Blow() {
        Log("The Health is empty now blowing with animation");
        explosion.SpawnExplosion(mWorld, GetActorLocation());
        Destroy();
    }

    void SpaceShip::Destroy() {
        RemovePhysicsBody();
        Object::Destroy();
    }

    void SpaceShip::Blink() {
        if (mBlinkTime == 0.f) {
            mBlinkTime = mBlinkDuration;
        }
    }

    void SpaceShip::UpdateBlink(float deltaTime) {
        if (mBlinkTime > 0) {
            mBlinkTime -= deltaTime;
            mBlinkTime = mBlinkTime > 0 ? mBlinkTime : 0.f;
            mSprite.setColor(LerpColor(sf::Color::White, mBlinkColor, mBlinkTime));
        }
    }

}