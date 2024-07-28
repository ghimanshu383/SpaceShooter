//
// Created by ghima on 15-07-2024.
//
#include <string>

#ifndef LIGHTYEARS_CONFIG_H
#define LIGHTYEARS_CONFIG_H

std::string GetAssetSourceDir() {
#ifdef NDEBUG
    return "assets/"
#else
    return "D:/c++games/SpaceShooter/game/assets/";
#endif
}

#endif LIGHTYEARS_CONFIG_H
