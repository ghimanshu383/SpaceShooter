//
// Created by ghima on 14-07-2024.
//
#include "frameWork/World.h"
#include "Application.h"
#include "frameWork/Actor.h"
#include "frameWork/BackGroundActors.h"
#include "frameWork/GameStage.h"
#include "frameWork/widgets/HUD.h"

namespace ly {
    World::World(Application *application) : mOwningApplication{application}, beginPlay{false}, mActorList(),
                                             mActorPendingList(), mGameStageIter(mGameStages.end()), mGameStages{} {

    }

    void World::BeginPlayInternal() {
        if (!beginPlay) {
            beginPlay = true;
            BeginPlay();
            InitGameStage();
        }
    }

    void World::BeginPlay() {

    }

    void World::TickInternal(float deltaTime) {
        Tick(deltaTime);
    }

    void World::Tick(float deltaTime) {

        for (shared<Actor> &actor: mActorPendingList) {
            if (dynamic_cast<BackgroundObjects *>(actor.get()) != nullptr) {
                mBackgroundObjectsList.push_back(actor);
            } else {
                mActorList.push_back(actor);
            }
            actor.get()->BeginPlayInternal();
        }
        mActorPendingList.clear();

        List<shared<Actor>>::iterator backgroundActorsIter = mBackgroundObjectsList.begin();

        while (backgroundActorsIter != mBackgroundObjectsList.end()) {
            if (!(*backgroundActorsIter)->isPendingDestroy()) {
                backgroundActorsIter->get()->TickInternal(deltaTime);
            }
            backgroundActorsIter++;
        }

        List<shared<Actor>>::iterator actorIter = mActorList.begin();
        while (actorIter != mActorList.end()) {
            if (!(*actorIter)->isPendingDestroy()) {
                actorIter->get()->TickInternal(deltaTime);
            }
            actorIter++;
        }

        if (mGameStageIter != mGameStages.end()) {
            (*mGameStageIter)->TickStage(deltaTime);
        }

        if (mCurrentHud.get() != nullptr && !mCurrentHud->IsInit()) {
            mCurrentHud->NativeInit(mOwningApplication->GetWindow());
        }
        if (mCurrentHud) {
            mCurrentHud->Tick(deltaTime);
        }

    }

    void World::RenderWorld(sf::RenderWindow &window) {
        for (shared<Actor> &actor: mBackgroundObjectsList) {
            if (!actor->isPendingDestroy()) {
                actor->Render(window);
            }
        }
        for (shared<Actor> &actor: mActorList) {
            if (!actor->isPendingDestroy()) {
                actor->Render(window);
            }
        }
        if (mCurrentHud) {
            mCurrentHud->Draw(window);
        }
    }

    sf::Vector2u World::GetWindowSize() const {
        return mOwningApplication->GetWindowSize();
    }

    void World::InitGameStage() {
        mGameStageIter = mGameStages.begin();
        (*mGameStageIter)->StartStage();
        (*mGameStageIter)->finishStageDelegate.Register(this, &World::NextStage);
    }

    void World::NextStage() {
        mGameStageIter = mGameStages.erase(mGameStageIter);

        if (mGameStageIter != mGameStages.end()) {
            (*mGameStageIter)->finishStageDelegate.Register(this, &World::NextStage);
            (*mGameStageIter)->StartStage();
        } else {
            AllStagesFinished();
        }
    }

    void World::AllStagesFinished() {

    }

    void World::CleanUp() {
        List<shared<Actor>>::iterator actorIter = mActorList.begin();
        while (actorIter != mActorList.end()) {
            if (actorIter->get()->isPendingDestroy()) {
                mActorList.erase(actorIter);
            } else {
                ++actorIter;
            }
        }
    }

    void World::AddStage(const shared<GameStage> &gameStage) {
        mGameStages.push_back(gameStage);
    }

    void World::HandleEvents(const sf::Event &event) {
        if (mCurrentHud) {
            mCurrentHud->HandleEvents(event);
        }
    }
}