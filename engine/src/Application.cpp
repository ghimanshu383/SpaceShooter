//
// Created by ghima on 14-07-2024.
//
#include "frameWork/PhysicsSystem.h"
#include "Application.h"
#include "Core.h"
#include "frameWork/AssetManager.h"
#include "frameWork/TimerManager.h"

namespace ly {
    Application::Application(unsigned int width, unsigned int height, const char *title) : mWindow(
            sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close), mTargetFrameRate{60.f},
                                                                                           mClock(), mAssetCleanClock(),
                                                                                           cleanCycleInterval{2.f},
                                                                                           mWindowSize(width, height) {
    }

    void Application::Init() {
        mClock.restart();
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f / mTargetFrameRate;

        while (mWindow.isOpen()) {
            sf::Event event{};
            while (mWindow.pollEvent(event)) {
                if (event.type == sf::Event::EventType::Closed) {
                    mWindow.close();
                } else {
                    currentWorld->HandleEvents(event);
                }
            }

            accumulatedTime += mClock.restart().asSeconds();
            while (accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                PhysicsSystem::GetInstance()->Step(targetDeltaTime);

                // It is vital to tick and clean up after the physics body removal as if any of the actor is pending
                // for the destroy the physics body for the same needs to be destroyed before the actor* is nullptr.
                Tick(targetDeltaTime);

                RenderInternal();
            }
        }
    }

    void Application::Tick(float deltaTime) {
        if (currentWorld.get() != nullptr) {
            currentWorld->BeginPlayInternal();
            currentWorld->TickInternal(deltaTime);
            TimerManager::GetInstance()->UpdateTimers(deltaTime);

        }
        if (mAssetCleanClock.getElapsedTime().asSeconds() >= cleanCycleInterval) {
            AssetManager::GetInstance()->CleanCycle();
            if (currentWorld.get() != nullptr) {
                currentWorld->CleanUp();
            }
            mAssetCleanClock.restart();
        }
    }

    void Application::RenderInternal() {
        mWindow.clear();
        Render();
        mWindow.display();
    }

    void Application::Render() {
        if (currentWorld.get() != nullptr) {
            currentWorld->RenderWorld(mWindow);
        }
    }

    sf::Vector2u Application::GetWindowSize() const {
        return mWindowSize;
    }
}