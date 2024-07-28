//
// Created by ghima on 17-07-2024.
//
#include <random>
#include "frameWork/MathUtil.h"


namespace ly {
    const float pi = 3.141592;

    sf::Vector2f RotationToVector(float rotation) {
        float radians = DegreeToRadians(rotation);
        return sf::Vector2f{std::cos(radians), std::sin(radians)};
    }

    float DegreeToRadians(float value) {
        return (pi / 180.f) * value;
    }

    float RadiansToDegree(float value) {
        return (180.f / pi) * value;
    }

    float RandomRange(float min, float max) {
        std::random_device rd{};
        std::mt19937 gen{rd()};

        std::uniform_real_distribution<float> distribution{min, max};
        return distribution(gen);
    }

    float LerpFloat(float a, float b, float alpha) {
        if (alpha > 1) alpha = 1;
        if (alpha < 0) alpha = 0;
        return a + (b - a) * alpha;
    }

    sf::Color LerpColor(const sf::Color &a, const sf::Color &b, const float alpha) {
        sf::Uint8 lerpR = LerpFloat(a.r, b.r, alpha);
        sf::Uint8 lerpG = LerpFloat(a.g, b.g, alpha);
        sf::Uint8 lerpB = LerpFloat(a.b, b.b, alpha);
        sf::Uint8 lerpA = LerpFloat(a.a, b.a, alpha);

        return sf::Color{lerpR, lerpG, lerpB, lerpA};

    }

    sf::Vector2f RandomUnitVector() {
        float randomX = RandomRange(-1, 1);
        float randomY = RandomRange(-1, 1);
        sf::Vector2f randomVec = sf::Vector2f{randomX, randomY};
        NormalizeVector(randomVec);
        return randomVec;
    }
}