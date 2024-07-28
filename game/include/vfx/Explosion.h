//
// Created by ghima on 19-07-2024.
//
#include <string>
#include <Core.h>

#ifndef LIGHTYEARS_EXPLOSION_H
#define LIGHTYEARS_EXPLOSION_H
namespace ly {
    class World;

    class Actor;

    class Explosion {
    public:
        explicit Explosion(int particleAmount, float lifeTimeMin = .2f, float lifeTimeMax = 1.f, float speedMin = 300.f,
                           float SpeedMax = 800.f,
                           float sizeMin = .5f, float sizeMax = 2.f);

        void SpawnExplosion(World *owningWorld, sf::Vector2f location);

    private:
        int mParticleAmt;
        List<std::string> mParticleTexPath;
        List<sf::Color> mParticleColor;

        float lifeTimeMin, lifeTimeMax;
        float speedMin, speedMax;
        float sizeMin, sizeMax;
    };
}
#endif //LIGHTYEARS_EXPLOSION_H
