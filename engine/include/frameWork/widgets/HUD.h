//
// Created by ghima on 24-07-2024.
//
#include <SFML/Graphics.hpp>
#include "frameWork/Object.h"

#ifndef LIGHTYEARS_HUD_H
#define LIGHTYEARS_HUD_H
namespace ly {
    class HUD : public Object {
    public:
        virtual void Draw(sf::RenderWindow &windowRef) = 0;

        void NativeInit(sf::RenderWindow &windowRef);

        bool IsInit() const { return mInit; };

        virtual void HandleEvents(const sf::Event &event);

        virtual void Tick(float deltaTime);

    protected:
        HUD();

    private:
        virtual void Init(sf::RenderWindow &windowRef);

        bool mInit = false;
    };
}
#endif //LIGHTYEARS_HUD_H
