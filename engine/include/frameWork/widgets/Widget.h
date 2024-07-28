//
// Created by ghima on 24-07-2024.
//
#include <SFML/Graphics.hpp>
#include "frameWork/Object.h"

#ifndef LIGHTYEARS_WIDGET_H
#define LIGHTYEARS_WIDGET_H
namespace ly {
    class Widget : public Object {
    public:
        explicit Widget();

        void NativeDraw(sf::RenderWindow &window);

        virtual void HandleEvents(const sf::Event &event);

        void SetWidgetLocation(sf::Vector2f location);

        void SetWidgetRotation(float rotation);

        void SetWidgetVisibility(float visibility);

        sf::Vector2f GetWidgetLocation() const { return mWidgetTransform.getPosition(); };

        float GetWidgetRotation() const { return mWidgetTransform.getRotation(); };

        bool GetIsVisible() const { return mIsVisible; };

    private:
        sf::Transformable mWidgetTransform;
        bool mIsVisible;

        virtual void Draw(sf::RenderWindow &windowRef) = 0;

        virtual void OnLocationChange(sf::Vector2f newLoc) = 0;

        virtual void OnRotationChange(float rotation) = 0;
    };
}
#endif //LIGHTYEARS_WIDGET_H
