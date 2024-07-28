//
// Created by ghima on 24-07-2024.
//
#include "frameWork/widgets/Widget.h"

namespace ly {
    Widget::Widget() : mIsVisible{false}, mWidgetTransform() {}

    void Widget::NativeDraw(sf::RenderWindow &window) {
        if (mIsVisible) {
            Draw(window);
        }
    }

    void Widget::SetWidgetLocation(sf::Vector2f location) {
        mWidgetTransform.setPosition(location);
        OnLocationChange(location);
    }

    void Widget::SetWidgetRotation(float rotation) {
        mWidgetTransform.setRotation(rotation);
        OnRotationChange(rotation);
    }

    void Widget::SetWidgetVisibility(float visibility) {
        mIsVisible = visibility;
    }

    void Widget::HandleEvents(const sf::Event &event) {

    }
}