//
// Created by ghima on 19-07-2024.
//

#include <Application.h>
#include <frameWork/TimerManager.h>

#include <memory>
#include <frameWork/BackDropActor.h>
#include <frameWork/BackGroundLayer.h>
#include "levels/LevelOne.h"
#include "Player/Player.h"
#include "gameplay/VanguardStage.h"
#include "gameplay/TwinBladeStage.h"
#include "gameplay/HexGuardStage.h"
#include "gameplay/UFOStage.h"
#include "gameplay/Rewards.h"
#include "gameplay/ChaosStage.h"
#include "gameplay/BossStage.h"
#include "gameplay/widgets/GamePlayHud.h"


namespace ly {
    LevelOne::LevelOne(Application *application) : World(application), mApplication{application},
                                                   mBackgroundLayer(new BackGroundLayer{this}) {
        weak<GamePlayHud> spawnHud = SpawnHUD<GamePlayHud, std::string>(std::string{"Frame Rate"});
        SpawnActor<BackDropActor, std::string, sf::Vector2f, float>(
                std::string{"SpaceShooterRedux/Backgrounds/darkPurple.png"},
                {0.f, -1.f}, 40.f);
        mBackgroundLayer->SpawnRandomPlanet();
        mBackgroundLayer->Init();
    }

    void LevelOne::BeginPlay() {
        Player::GetInstance()->SpawnSpaceShip(this);

    }

    void LevelOne::TestTimer() {
        Log("This is a test for the timer");
    }

    void LevelOne::InitGameStage() {

        AddStage(std::make_shared<VanguardStage>(this));
        // By default the game stage is used for a particular wait time between two stages.
        AddStage(std::make_shared<GameStage>(this));
        AddStage(std::make_shared<TwinBladeStage>(this));
        AddStage(std::make_shared<HexGuardStage>(this));
        AddStage(std::make_shared<UFOStage>(this));
        AddStage(std::make_shared<GameStage>(this));
        AddStage(std::make_shared<ChaosStage>(this));
        AddStage(std::make_shared<GameStage>(this));
        AddStage(std::make_shared<BossStage>(this));

        World::InitGameStage();
    }
}