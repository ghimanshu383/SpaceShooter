//
// Created by ghima on 24-07-2024.
//
#include "frameWork/widgets/HUD.h"

namespace ly {
    void HUD::NativeInit(sf::RenderWindow &windowRef) {
        if (!mInit) {
            mInit = true;
            Init(windowRef);
        }
    }

    void HUD::Init(sf::RenderWindow &windowRef) {

    }

    void HUD::HandleEvents(const sf::Event &event) {

    }

    void HUD::Tick(float deltaTime) {

    }

    HUD::HUD() = default;
}