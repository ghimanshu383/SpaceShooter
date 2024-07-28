//
// Created by ghima on 14-07-2024.
//
#include <SFML/Graphics.hpp>
#include <type_traits>

#include "Core.h"
#include "Object.h"

#ifndef LIGHTYEARS_WORLD_H
#define LIGHTYEARS_WORLD_H

namespace ly {
    class Application;

    class Actor;

    class GameStage;

    class HUD;

    class World : public Object {
    private:
        Application *mOwningApplication;
        bool beginPlay;
        shared<HUD> mCurrentHud;
        List<shared<Actor>> mActorList;
        List<shared<Actor>> mActorPendingList;

        List<shared<Actor>> mBackgroundObjectsList;
        List<shared<Actor>> mBackgroundActorsPendingList;

        List<shared<GameStage>> mGameStages;
        List<shared<GameStage>>::
        iterator mGameStageIter;
    public:
        explicit World(Application *application);

        void TickInternal(float deltaTime);

        virtual void Tick(float deltaTime);

        void BeginPlayInternal();

        virtual void BeginPlay();

        void RenderWorld(sf::RenderWindow &window);

        sf::Vector2u GetWindowSize() const;

        void CleanUp();

        // Game play functions;
        virtual void InitGameStage();

        virtual void AllStagesFinished();

        void NextStage();

        void AddStage(const shared<GameStage> &gameStage);

        // HUD Display
        virtual void HandleEvents(const sf::Event &event);

        virtual ~World() = default;

        // Adding the utility functions with templates

        template<typename T, typename... Args, typename std::enable_if<std::is_base_of<Actor, T>::value, T>::type * = nullptr>
        weak<T> SpawnActor(Args... args) {
            shared<T> actor{new T{this, args...}};
            mActorPendingList.push_back(actor);
            return weak<T>{actor};
        }

        template<typename T, typename... Args, typename std::enable_if<std::is_base_of<HUD, T>::value, T>::type * = nullptr>
        weak<T> SpawnHUD(Args... args) {
            shared<T> hud{new T{args...}};
            mCurrentHud = hud;
            return hud;
        }
    };
}
#endif //LIGHTYEARS_WORLD_H
