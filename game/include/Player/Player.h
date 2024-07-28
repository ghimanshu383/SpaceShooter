//
// Created by ghima on 23-07-2024.
//
#include <frameWork/Object.h>

#ifndef LIGHTYEARS_PLAYER_H
#define LIGHTYEARS_PLAYER_H
namespace ly {
    class World;

    class PlayerSpaceShip;

    class Player : public Object {
    protected:
        explicit Player();

        static Player *instance;
        weak<PlayerSpaceShip> mCurrentSpaceShip;
        int mLifeCount;
        int mCurrentLifeCount;
        int score;
    public:
        static Player *GetInstance();

        void SpawnSpaceShip(World *owningWorld);

        void EndGame();
    };
}
#endif //LIGHTYEARS_PLAYER_H
