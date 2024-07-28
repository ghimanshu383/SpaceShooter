//
// Created by ghima on 14-07-2024.
//

#include <iostream>
#include <frameWork/AssetManager.h>
#include "Config.h"

#include "GameApplication.h"
#include "levels/LevelOne.h"

namespace ly {

    GameApplication::GameApplication(unsigned int width, unsigned int height, const char *title) : Application(width,
                                                                                                               height,
                                                                                                               title) {

        AssetManager::GetInstance()->SetRootDir(GetAssetSourceDir());
        RunGame();
    }

    void GameApplication::RunGame() {
        shared<LevelOne> levelOne = SpawnWorld<LevelOne>();
    }
}

void ly::Run() {
    std::cout << "The Application Started" << std::endl;
    ly::GameApplication app{600, 1024, "Light Years"};
    app.Init();
}