//
// Created by ghima on 17-07-2024.
//

#include <SFML/Graphics.hpp>
#include <cmath>

#ifndef LIGHTYEARS_MATHUTIL_H
#define LIGHTYEARS_MATHUTIL_H
namespace ly {
    sf::Vector2f RotationToVector(float rotation);

    float DegreeToRadians(float value);

    float RadiansToDegree(float value);

    float LerpFloat(float a, float b, float alpha);

    float RandomRange(float min, float max);

    sf::Vector2f RandomUnitVector();

    sf::Color LerpColor(const sf::Color &a, const sf::Color &b, const float alpha);

    template<typename T>
    sf::Vector2<T> LerpVector(const sf::Vector2<T> &a, const sf::Vector2<T> b, const float alpha) {
        T aVal = LerpFloat(a.x, b.x, alpha);
        T bVal = LerpFloat(a.y, b.y, alpha);

        return sf::Vector2<T>{aVal, bVal};
    }

    template<typename T>
    float GetVectorMag(sf::Vector2<T> vector) {
        return std::sqrt(vector.x * vector.y + vector.y * vector.y);
    }

    template<typename T>
    void ScaleVector(sf::Vector2<T> &vectorToScale, float amt) {
        vectorToScale.x *= amt;
        vectorToScale.y *= amt;
    }

    template<typename T>
    void NormalizeVector(sf::Vector2<T> &vector) {
        float mag = GetVectorMag<T>(vector);
        if (mag == 0) return;
        ScaleVector(vector, 1 / mag);
    }
}
#endif //LIGHTYEARS_MATHUTIL_H
