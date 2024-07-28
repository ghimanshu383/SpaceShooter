//
// Created by ghima on 15-07-2024.
//
#include <SFML/Graphics.hpp>
#include <string>

#include "Object.h"

#ifndef LIGHTYEARS_ACTOR_H
#define LIGHTYEARS_ACTOR_H

class b2Body;

namespace ly {
    class World;

    class Actor : public Object {
    public:
        explicit Actor(World *world, std::string &TexturePath, uint8 id = 255);

        void TickInternal(float deltaTime);

        virtual void Tick(float deltaTime);

        void BeginPlayInternal();

        virtual void BeginPlay();

        void AddSpriteTexture(std::string texturePath);

        void SetTextureRepeated(bool value);

        void Render(sf::RenderWindow &window);

        // Set Actor Transform
        void SetActorLocation(const sf::Vector2f &newLoc);

        void SetActorRotation(const float &rotation);

        void AddActorLocationOffset(const sf::Vector2f offset);

        void AddActorRotationOffset(float offset);

        sf::Vector2f GetActorLocation() const;

        bool IsOutOfBounds(float buff = 10.f);

        float GetActorRotation() const;

        sf::Vector2f GetActorForwardDir() const;

        sf::Vector2f GetActorRightDir() const;

        sf::Vector2f GetActorLeftDir() const;

        World *GetOwningWorld() const;

        sf::Sprite& GetActorSprite() ;

        sf::FloatRect GetActorGlobalBounds() const;

        // Physics System
        void UpdateBodyTransform();

        virtual void BeginContact(Actor *other);

        virtual void EndContact(Actor *other);

        b2Body *GetPhysicsBody() const;

        void RemovePhysicsBody();

        virtual void OnChangeHealth(float amt);

        bool CheckOtherHostile(Actor *other);


        uint8 id;
    protected:
        World *mWorld;
        bool mBeginPlay;
        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;
        b2Body *mPhysicsBody;
    };
}
#endif //LIGHTYEARS_ACTOR_H
