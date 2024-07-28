//
// Created by ghima on 17-07-2024.
//

#include <SFML/Graphics.hpp>
#include "Core.h"

#ifndef LIGHTYEARS_ASSETMANAGER_H
#define LIGHTYEARS_ASSETMANAGER_H
namespace ly {
    class AssetManager {
    protected:
        AssetManager();

    private:
        Dict<std::string, shared<sf::Texture>> mLoadedTexture{};
        Dict<std::string, shared<sf::Font>> mLoadedFonts{};
        static AssetManager *instance;
        std::string mRootDir;
    public:
        static AssetManager *GetInstance();

        shared<sf::Texture> LoadTexture(std::string &texturePath);

        shared<sf::Font> LoadFont(const std::string &fontPath);

        void SetRootDir(std::string &&dir);

        void CleanCycle();

        template<typename T>
        shared<T> LoadAsset(std::string &texturePath, Dict<std::string, shared<T>> &container) {
            auto assetFound = container.find(mRootDir + texturePath);
            if (assetFound == container.end()) {
                shared<T> asset{new T{}};
                if (asset->loadFromFile(mRootDir + assetFound)) {
                    container.insert({assetFound, asset});
                    return asset;
                } else {
                    return shared<T>{nullptr};
                }
            }
            return assetFound->second;
        }
    };
}
#endif //LIGHTYEARS_ASSETMANAGER_H
