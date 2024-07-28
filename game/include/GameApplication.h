//
// Created by ghima on 14-07-2024.
//
#include <Application.h>

#ifndef LIGHTYEARS_GAMEAPPLICATION_H
#define LIGHTYEARS_GAMEAPPLICATION_H
namespace ly {
    class GameApplication : public Application {
    public:
        GameApplication(unsigned int width, unsigned int height, const char *title);

        void RunGame();
    };
}
#endif //LIGHTYEARS_GAMEAPPLICATION_H
