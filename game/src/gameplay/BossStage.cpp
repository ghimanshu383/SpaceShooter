//
// Created by ghima on 27-07-2024.
//
#include <frameWork/World.h>

#include "gameplay/BossStage.h"
#include "Enemy/Boss.h"

namespace ly {
    BossStage::BossStage(ly::World *owningWorld) : GameStage(owningWorld) {}

    void BossStage::StartStage() {
        weak<Boss> boss = GetWorld()->SpawnActor<Boss>();
        boss.lock()->SetActorRotation(90.f);
        boss.lock()->SetActorLocation({(float) GetWorld()->GetWindowSize().x / 2, -100.f});
        boss.lock()->GetEndDelegate().Register(this, &BossStage::FinishStageHandler);
    }

    void BossStage::FinishStageHandler() {
        Log("The Game over");
    }
}