//
// Created by ghima on 24-07-2024.
//
#include <frameWork/widgets/HUD.h>
#include <frameWork/widgets/TextWidget.h>

#ifndef LIGHTYEARS_GAMEPLAYHUD_H
#define LIGHTYEARS_GAMEPLAYHUD_H
namespace ly {
    class GamePlayHud : public HUD {
    public:
        explicit GamePlayHud(std::string &frameRateText);

        virtual void Draw(sf::RenderWindow &windowRef) override;

        virtual void Tick(float deltaTime) override;

    private:
        TextWidget mTextWidget;
    };
}
#endif //LIGHTYEARS_GAMEPLAYHUD_H
