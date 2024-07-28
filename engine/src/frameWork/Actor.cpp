//
// Created by ghima on 15-07-2024.
//

#include <box2d/b2_body.h>

#include "frameWork/Actor.h"
#include "Core.h"
#include "framework/AssetManager.h"
#include "frameWork/MathUtil.h"
#include "frameWork/World.h"
#include "frameWork/PhysicsSystem.h"

namespace ly {
    Actor::Actor(ly::World *world, std::string &texturePath, uint8 id) : mWorld{world}, mBeginPlay{false}, Object(),
                                                                         mSprite(),
                                                                         mPhysicsBody{nullptr}, id{id} {
        AddSpriteTexture(texturePath);

    }

    void Actor::BeginPlayInternal() {
        if (!mBeginPlay) {
            mBeginPlay = true;
            BeginPlay();
        }
    }

    void Actor::BeginPlay() {
        if (mPhysicsBody == nullptr) {
            mPhysicsBody = PhysicsSystem::GetInstance()->CreateActorBody(this);
        }
    }

    void Actor::TickInternal(float deltaTime) {
        Tick(deltaTime);


    }

    void Actor::Tick(float deltaTime) {

    }

    void Actor::AddSpriteTexture(std::string texturePath) {
        mTexture = AssetManager::GetInstance()->LoadTexture(texturePath);
        if (mTexture.get() == nullptr) {
            Log("Failed to load the Texture from %s", texturePath.c_str());
            return;
        }
        mSprite.setTexture(*mTexture);

        int width = mTexture->getSize().x;
        int height = mTexture->getSize().y;

        mSprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{width, height}});
        sf::FloatRect bounds = mSprite.getGlobalBounds();
        mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    }

    void Actor::Render(sf::RenderWindow &window) {
        window.draw(mSprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f &newLoc) {
        mSprite.setPosition(newLoc);
    }

    void Actor::SetActorRotation(const float &rotation) {
        mSprite.setRotation(rotation);
    }

    void Actor::AddActorLocationOffset(const sf::Vector2f offset) {
        mSprite.setPosition(GetActorLocation() + offset);
        UpdateBodyTransform();
    }

    void Actor::AddActorRotationOffset(float offset) {
        mSprite.setRotation(GetActorRotation() + offset);
    }

    sf::Vector2f Actor::GetActorLocation() const {
        return mSprite.getPosition();
    }

    bool Actor::IsOutOfBounds(float buff) {
        sf::FloatRect actorBounds = mSprite.getGlobalBounds();
        sf::Vector2u windowSize = mWorld->GetWindowSize();

        if (GetActorLocation().x < -actorBounds.width - buff) {
            return true;
        }
        if (GetActorLocation().x > windowSize.x + actorBounds.width + buff) {
            return true;
        }
        if (GetActorLocation().y < -actorBounds.height - buff) {
            return true;
        }
        if (GetActorLocation().y > windowSize.y + actorBounds.height + buff) {
            return true;
        }

        return false;
    }

    float Actor::GetActorRotation() const {
        return mSprite.getRotation();
    }

    sf::Vector2f Actor::GetActorForwardDir() const {
        return RotationToVector(GetActorRotation());
    }

    sf::Vector2f Actor::GetActorRightDir() const {
        return RotationToVector(GetActorRotation() + 90.f);
    }

    sf::Vector2f Actor::GetActorLeftDir() const {
        return RotationToVector(GetActorRotation() - 90.f);
    }

    World *Actor::GetOwningWorld() const {
        return mWorld;
    }

    sf::FloatRect Actor::GetActorGlobalBounds() const {
        return mSprite.getGlobalBounds();
    }

    void Actor::UpdateBodyTransform() {
        if (mPhysicsBody != nullptr && !Object::isPendingDestroy()) {
            float physicsScale = PhysicsSystem::GetInstance()->GetPhysicsScale();
            b2Vec2 pos{GetActorLocation().x * physicsScale, GetActorLocation().y * physicsScale};
            mPhysicsBody->SetTransform(pos, DegreeToRadians(GetActorRotation()));
        }
    }

    void Actor::BeginContact(Actor *other) {
        if (other == nullptr || other->isPendingDestroy()) return;
    }

    void Actor::EndContact(Actor *other) {
        if (other == nullptr || other->isPendingDestroy()) return;
    }

    b2Body *Actor::GetPhysicsBody() const {
        return mPhysicsBody;
    }

    void Actor::RemovePhysicsBody() {
        PhysicsSystem::GetInstance()->RemoveBody(this);
        mPhysicsBody = nullptr;
    }

    void Actor::OnChangeHealth(float amt) {

    }

    bool Actor::CheckOtherHostile(Actor *other) {
        return id != other->id;
    }

    sf::Sprite& Actor::GetActorSprite()  {
        return mSprite;
    }

    void Actor::SetTextureRepeated(bool value) {
        mTexture->setRepeated(value);
    }
}