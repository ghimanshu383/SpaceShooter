//
// Created by ghima on 17-07-2024.
//
#include "weapons/Bullet.h"
#include "frameWork/MathUtil.h"

namespace ly {
    Bullet::Bullet(ly::World *owningWorld, ly::Actor *owningActor, std::string &texturePath,
                   float speed, float damage)
            : Actor(owningWorld, texturePath), mSpeed{speed}, mDamage{damage},
              mOwningActor{owningActor}, mRotateOffset{0.f} {
        SetActorLocation(owningActor->GetActorLocation());
        id = owningActor->id;
    }

    void Bullet::Tick(float deltaTime) {
        Actor::Tick(deltaTime);
        Move(deltaTime);
        if (IsOutOfBounds()) {
            Destroy();
        }
    }

    void Bullet::Move(float deltaTime) {
        SetActorRotation(mOwningActor->GetActorRotation() + mRotateOffset);
        Actor::AddActorLocationOffset(GetActorForwardDir() * mSpeed * deltaTime);
    }

    void Bullet::SetSpeed(float speed) {
        mSpeed = speed;
    }

    void Bullet::SetDamage(float damage) {
        mDamage = damage;
    }

    float Bullet::GetSpeed() const {
        return mSpeed;
    }

    float Bullet::GetDamage() const {
        return mDamage;
    }

    void Bullet::BeginContact(Actor *other) {
        Actor::BeginContact(other);
        if (CheckOtherHostile(other)) {
            other->OnChangeHealth(-mDamage);
            Destroy();
        }
    }

    void Bullet::Destroy() {
        RemovePhysicsBody();
        Object::Destroy();
    }
}