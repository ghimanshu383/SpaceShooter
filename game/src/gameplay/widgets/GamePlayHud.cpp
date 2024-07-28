//
// Created by ghima on 24-07-2024.
//
#include "gameplay/widgets/GamePlayHud.h"

namespace ly {
    GamePlayHud::GamePlayHud(std::string &frameRateText) : HUD(), mTextWidget{frameRateText} {
        mTextWidget.SetWidgetVisibility(true);
    }

    void GamePlayHud::Draw(sf::RenderWindow &windowRef) {
        mTextWidget.NativeDraw(windowRef);
    }

    void GamePlayHud::Tick(float deltaTime) {
        HUD::Tick(deltaTime);
        int frameRate = (int) (1 / deltaTime);
        std::string frameRateString = std::to_string(frameRate);
        mTextWidget.GetMText().setCharacterSize(20);
        mTextWidget.GetMText().setString("Frame Rate : " + frameRateString);
    }
}