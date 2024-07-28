//
// Created by ghima on 18-07-2024.
//
#include <box2d/b2_body.h>

#include "frameWork/PhysicsSystem.h"
#include "frameWork/Actor.h"
#include "frameWork/MathUtil.h"

namespace ly {
    PhysicsSystem *PhysicsSystem::instance = nullptr;

    // Initialized with 0 gravity as the game has no gravity.
    PhysicsSystem::PhysicsSystem() : mPhysicsWorld(b2Vec2{0, 0}), mVelocityIterations{8}, mPositionIterations{3},
                                     mPhysicsScale{0.01f}, mContactListener{new PhysicsSystemContactListener{}} {
        mPhysicsWorld.SetContactListener(mContactListener);
        mPhysicsWorld.SetAllowSleeping(false);
    }

    PhysicsSystem *PhysicsSystem::GetInstance() {
        if (instance == nullptr) {
            instance = new PhysicsSystem();
        }
        return instance;
    }

    void PhysicsSystem::Step(float deltaTime) {
        // It is vital to clean up the physics body before we step as in some case if the actor is
        // destroyed we need to clean the body of the physics system so it cannot be in the timer phase.
        ProcessPendingRemoveListeners();
        mPhysicsWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
    }

    b2Body *PhysicsSystem::CreateActorBody(Actor *target) {
        if (target->isPendingDestroy()) return nullptr;
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(target->GetActorLocation().x * GetPhysicsScale(),
                             target->GetActorLocation().y * GetPhysicsScale());
        bodyDef.angle = DegreeToRadians(target->GetActorRotation());

        b2Body *body = mPhysicsWorld.CreateBody(&bodyDef);
        b2PolygonShape polygonShape;
        sf::FloatRect bounds = target->GetActorGlobalBounds();
        polygonShape.SetAsBox(bounds.width / 2.f * GetPhysicsScale(), bounds.height / 2.f * GetPhysicsScale());

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &polygonShape;
        fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(target);
        fixtureDef.density = 0.f;
        fixtureDef.friction = 0.3f;
        fixtureDef.isSensor = true;
        body->CreateFixture(&fixtureDef);

        return body;

    }

    float PhysicsSystem::GetPhysicsScale() const {
        return mPhysicsScale;
    }

    void PhysicsSystem::RemoveBody(Actor *target) {
        if (target->GetPhysicsBody() != nullptr) {
            mPendingRemovalBody.insert(target->GetPhysicsBody());

        }
    }

    void PhysicsSystem::ProcessPendingRemoveListeners() {
        for (b2Body *body: mPendingRemovalBody) {
            mPhysicsWorld.DestroyBody(body);
        }
        mPendingRemovalBody.clear();
    }

    void PhysicsSystemContactListener::BeginContact(b2Contact *contact) {
        Actor *actorOne = reinterpret_cast<Actor *>(contact->GetFixtureA()->GetUserData().pointer);
        Actor *actorTwo = reinterpret_cast<Actor *>(contact->GetFixtureB()->GetUserData().pointer);

        if (actorOne != nullptr && !actorOne->isPendingDestroy()) {
            actorOne->BeginContact(actorTwo);
        }
        if (actorTwo != nullptr && !actorTwo->isPendingDestroy()) {
            actorTwo->BeginContact(actorOne);
        }
    }

    void PhysicsSystemContactListener::EndContact(b2Contact *contact) {
        Actor *actorOne = nullptr;
        Actor *actorTwo = nullptr;

        if (contact->GetFixtureA() && contact->GetFixtureA()->GetBody()) {
            actorOne = reinterpret_cast<Actor *>( contact->GetFixtureA()->GetUserData().pointer);
        }
        if (contact->GetFixtureB() && contact->GetFixtureB()->GetBody()) {
            actorTwo = reinterpret_cast<Actor *>(contact->GetFixtureB()->GetUserData().pointer);
        }

        if (actorOne != nullptr && !actorOne->isPendingDestroy()) {
            actorOne->EndContact(actorTwo);
        }
        if (actorTwo != nullptr && !actorTwo->isPendingDestroy()) {
            actorTwo->EndContact(actorOne);
        }
    }
}