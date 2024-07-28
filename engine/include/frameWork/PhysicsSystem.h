//
// Created by ghima on 18-07-2024.
//
#include "box2d/box2d.h"
#include "Core.h"

#ifndef LIGHTYEARS_PHYICSSYSTEM_H
#define LIGHTYEARS_PHYICSSYSTEM_H
namespace ly {
    class Actor;

    class PhysicsSystemContactListener : public b2ContactListener {
        virtual void BeginContact(b2Contact *contact) override;

        virtual void EndContact(b2Contact *contact) override;
    };

    class PhysicsSystem {
    protected:
        PhysicsSystem();

        static PhysicsSystem *instance;
    private:
        b2World mPhysicsWorld;
        PhysicsSystemContactListener *mContactListener;
        int mVelocityIterations;
        int mPositionIterations;
        float mPhysicsScale;
        Set<b2Body *> mPendingRemovalBody;
    public:
        static PhysicsSystem *GetInstance();

        void Step(float deltaTime);

        b2Body *CreateActorBody(Actor *target);

        void RemoveBody(Actor *target);

        float GetPhysicsScale() const;

        void ProcessPendingRemoveListeners();
    };
}
#endif //LIGHTYEARS_PHYICSSYSTEM_H
