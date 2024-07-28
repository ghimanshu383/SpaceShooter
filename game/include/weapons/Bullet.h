//
// Created by ghima on 17-07-2024.
//
#include <frameWork/Actor.h>

#ifndef LIGHTYEARS_BULLET_H
#define LIGHTYEARS_BULLET_H
namespace ly {
    class Bullet : public Actor {
    public:
        Bullet(World *owningWorld, Actor *owningActor, std::string &texturePath,
               float speed = 1000.f,
               float damage = 10.f);

        virtual void Tick(float deltaTime) override;

        void Move(float deltaTime);

        void SetSpeed(float speed);

        void SetDamage(float damage);

        float GetSpeed() const;

        float GetDamage() const;

        virtual void BeginContact(Actor *other) override;

        virtual void Destroy() override;

        void SetRotateOffset(float offset) {mRotateOffset = offset; };

        float GetRotateOffset () const {return mRotateOffset;}

    private:
        Actor *mOwningActor;
        float mSpeed;
        float mDamage;
        float mRotateOffset;
    };
}
#endif //LIGHTYEARS_BULLET_H
