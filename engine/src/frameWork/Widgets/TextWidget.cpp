//
// Created by ghima on 24-07-2024.
//
#include "frameWork/widgets/TextWidget.h"
#include "frameWork/AssetManager.h"

namespace ly {
    TextWidget::TextWidget(std::string &text, const std::string &fontPath, unsigned int fontSize)
            : Widget(), mFont(AssetManager::GetInstance()->LoadFont(fontPath)) {
        if (mFont.get() == nullptr) {
            Log("Failed to Load the Font");
            mText = {text, {}};
            return;
        }
        mText = {text, *(mFont.get())};
    }

    void TextWidget::Draw(sf::RenderWindow &window) {
        window.draw(mText);
    }

    void TextWidget::OnLocationChange(sf::Vector2f newLocation) {

    }

    void TextWidget::OnRotationChange(float rotation) {

    }
}