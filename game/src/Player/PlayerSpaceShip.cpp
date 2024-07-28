//
// Created by ghima on 17-07-2024.
//
#include "frameWork/MathUtil.h"
#include "frameWork/World.h"

#include "Player/PlayerSpaceShip.h"
#include "weapons/BulletShooter.h"
#include "gameplay/HealthComponent.h"
#include "weapons/ThreeWayShooter.h"
#include "weapons/FrontalWipper.h"
#include "Player/Player.h"

namespace ly {
    PlayerSpaceShip::PlayerSpaceShip(World *owningWorld, std::string texturePath) : SpaceShip(owningWorld,
                                                                                              texturePath),
                                                                                    moveInput(), mSpeed{400.f},
                                                                                    mWindowSize(
                                                                                            owningWorld->GetWindowSize()),
                                                                                    mBulletShooter{
                                                                                            new BulletShooter{this,
                                                                                                              0.1f,
                                                                                                              "SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
                                                                                                              {0.f,
                                                                                                               -45.f}}} {

    }

    void PlayerSpaceShip::Tick(float deltaTime) {
        SpaceShip::Tick(deltaTime);
        HandleInput();
        ConsumeInput();
    }

    void PlayerSpaceShip::HandleInput() {
        moveInput = sf::Vector2f{};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            moveInput.y = -1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            moveInput.x = 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            moveInput.y = 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            moveInput.x = -1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Shoot();
        }
        ClampInputOnEdge();
        NormalizeVector(moveInput);
    }

    void PlayerSpaceShip::ConsumeInput() {
        SetVelocity(moveInput * mSpeed);
    }

    void PlayerSpaceShip::Shoot() {
        mBulletShooter->ShootImpl();
    }

    void PlayerSpaceShip::ClampInputOnEdge() {
        sf::Vector2f actorPos = GetActorLocation();
        sf::FloatRect actorSize = mSprite.getGlobalBounds();

        if (actorPos.x < actorSize.width / 2 && moveInput.x < 0) {
            moveInput.x = 0;
        }
        if (actorPos.x > (float) mWindowSize.x - actorSize.width / 2 && moveInput.x > 0) {
            moveInput.x = 0;
        }
        if (actorPos.y < actorSize.height / 2 && moveInput.y < 0) {
            moveInput.y = 0;
        }
        if (actorPos.y > (float) mWindowSize.y - actorSize.height / 2 && moveInput.y > 0) {
            moveInput.y = 0;
        }
    }

    float PlayerSpaceShip::getMSpeed() const {
        return mSpeed;
    }

    void PlayerSpaceShip::setMSpeed(float newSpeed) {
        PlayerSpaceShip::mSpeed = newSpeed;
    }

    void PlayerSpaceShip::OnTakeDamage(float amt) {
        SpaceShip::OnTakeDamage(amt);
    }

    void PlayerSpaceShip::Blow() {
        Player::GetInstance()->SpawnSpaceShip(mWorld);
        SpaceShip::Blow();
    }

}