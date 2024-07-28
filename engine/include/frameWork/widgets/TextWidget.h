//
// Created by ghima on 24-07-2024.
//
#include "frameWork/widgets/Widget.h"

#ifndef LIGHTYEARS_TEXTWIDGET_H
#define LIGHTYEARS_TEXTWIDGET_H
namespace ly {
    class TextWidget : public Widget {
    public:
        explicit TextWidget(std::string &text,
                            const std::string &fontPath = "SpaceShooterRedux/Bonus/kenvector_future.ttf",
                            unsigned int fontSize = 10);

        sf::Text &GetMText() { return mText; };
    private:
        virtual void Draw(sf::RenderWindow &window) override;

        virtual void OnLocationChange(sf::Vector2f newLocation) override;

        virtual void OnRotationChange(float rotation) override;

        sf::Text mText;
        shared<sf::Font> mFont;
    };
}
#endif //LIGHTYEARS_TEXTWIDGET_H
