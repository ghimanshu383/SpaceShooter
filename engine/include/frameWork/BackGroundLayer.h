//
// Created by ghima on 27-07-2024.
//
#include <string>
#include "Core.h"
#include "frameWork/Object.h"

#ifndef LIGHTYEARS_BACKGROUNDLAYER_H
#define LIGHTYEARS_BACKGROUNDLAYER_H
namespace ly {
    class World;

    class BackGroundLayer : public Object {

    public:
        explicit BackGroundLayer(World *owningWorld);

        void SpawnRandomBackgroundActors();

        void SpawnRandomPlanet();

        void Init();

    private:
        World *mWorld;
        List<std::string> mTexturePaths;
        List<std::string> mPlanetTexturePaths;
    };
}
#endif //LIGHTYEARS_BACKGROUNDLAYER_H
