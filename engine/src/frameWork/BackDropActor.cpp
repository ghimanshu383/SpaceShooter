//
// Created by ghima on 27-07-2024.
//
#include "frameWork/World.h"
#include "framework/BackDropActor.h"

namespace ly {
    BackDropActor::BackDropActor(ly::World *owningWorld, std::string &texturePath, sf::Vector2f velocity,
                                 float moveSpeed) : BackgroundObjects(
            owningWorld, texturePath, moveSpeed), mVelocity(velocity), mTopShift{0}, mLeftShift{0},
                                                    mMoveSpeed{moveSpeed} {
        auto windowSize = GetOwningWorld()->GetWindowSize();
        GetActorSprite().setTextureRect(
                sf::IntRect{sf::Vector2i{0, 0}, sf::Vector2i{(int) windowSize.x + 200, (int) windowSize.y + 200}});
        SetTextureRepeated(true);
    }

    void BackDropActor::BeginPlay() {
        // This will not initialize the physics for the backdrop

    }

    void BackDropActor::Tick(float deltaTime) {
        Actor::Tick(deltaTime);

        mLeftShift += deltaTime * mVelocity.x * mMoveSpeed;
        mTopShift += deltaTime * mVelocity.y * mMoveSpeed;
        sf::IntRect texRec = GetActorSprite().getTextureRect();
        texRec.left = mLeftShift;
        texRec.top = mTopShift;

        GetActorSprite().setTextureRect(texRec);
    }

}