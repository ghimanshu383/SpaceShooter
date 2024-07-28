//
// Created by ghima on 27-07-2024.
//
#include "frameWork/BackGroundLayer.h"
#include "frameWork/World.h"
#include "frameWork/MathUtil.h"
#include "frameWork/BackGroundActors.h"
#include "frameWork/TimerManager.h"

namespace ly {
    BackGroundLayer::BackGroundLayer(ly::World *owningWorld) : mWorld{owningWorld},
                                                               mTexturePaths(
                                                                       {"SpaceShooterRedux//PNG/Meteors/meteorBrown_big1.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_big2.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_big3.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_big4.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_med1.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_med3.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_small1.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorBrown_small2.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorGrey_big1.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorGrey_big2.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorGrey_big3.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorGrey_big4.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorGrey_med1.png",
                                                                        "SpaceShooterRedux//PNG/Meteors/meteorGrey_med2.png"}),
                                                               mPlanetTexturePaths(
                                                                       {"SpaceShooterRedux/PNG/Planets/Planet1.png",
                                                                        "SpaceShooterRedux/PNG/Planets/Planet2.png",
                                                                        "SpaceShooterRedux/PNG/Planets/Planet3.png",
                                                                        "SpaceShooterRedux/PNG/Planets/Planet4.png",
                                                                        "SpaceShooterRedux/PNG/Planets/Planet5.png",
                                                                        "SpaceShooterRedux/PNG/Planets/Planet6.png",
                                                                        "SpaceShooterRedux/PNG/Planets/Planet7.png"}) {
    }

    void BackGroundLayer::Init() {
        TimerManager::GetInstance()->SetTimer(GetWeakRef(), &BackGroundLayer::SpawnRandomBackgroundActors, 3.f, true);
        TimerManager::GetInstance()->SetTimer(GetWeakRef(), &BackGroundLayer::SpawnRandomPlanet, 15.f, true);
    }

    void BackGroundLayer::SpawnRandomBackgroundActors() {
        int random = std::floor(RandomRange(0.f, mTexturePaths.size() - .1f));
        float randomSpeed = RandomRange(50.f, 200.f);
        weak<BackgroundObjects> randomActor = mWorld->SpawnActor<BackgroundObjects, std::string, float>(
                mTexturePaths[random], randomSpeed);
        float randomLocation = RandomRange(50.f, mWorld->GetWindowSize().x - 50.f);
        randomActor.lock()->SetActorLocation({randomLocation, -50.f});
    }

    void BackGroundLayer::SpawnRandomPlanet() {
        int random = std::floor(RandomRange(0.f, mPlanetTexturePaths.size() - .1f));
        float randomSpeed = RandomRange(50.f, 70.f);
        weak<BackgroundObjects> randomActor = mWorld->SpawnActor<BackgroundObjects, std::string, float>(
                mPlanetTexturePaths[random], randomSpeed);
        float randomLocation = RandomRange(50.f, mWorld->GetWindowSize().x - 50.f);
        randomActor.lock()->SetActorLocation(
                {randomLocation, (float) -randomActor.lock()->GetActorSprite().getTextureRect().height});
    }
}