//
// Created by ghima on 17-07-2024.
//
#include "frameWork/AssetManager.h"
#include <cstring>

namespace ly {
    AssetManager *AssetManager::instance = nullptr;

    AssetManager::AssetManager() = default;

    AssetManager *AssetManager::GetInstance() {
        if (instance == nullptr) {
            instance = new AssetManager();
        }
        return instance;
    }

    shared<sf::Texture> AssetManager::LoadTexture(std::string &texturePath) {

        Dict<std::string, shared<sf::Texture>>::iterator texFound = mLoadedTexture.find(mRootDir + texturePath);
        if (texFound == mLoadedTexture.end()) {
            shared<sf::Texture> texture{new sf::Texture};
            if (texture->loadFromFile(mRootDir + texturePath)) {
                mLoadedTexture.insert({texturePath, texture});
                return texture;
            } else {
                return shared<sf::Texture>{nullptr};
            }

        } else {
            return texFound->second;
        }
    }

    void AssetManager::SetRootDir(std::string &&dir) {
        mRootDir = dir;
    }

    void AssetManager::CleanCycle() {
        Dict<std::string, shared<sf::Texture>>::iterator texIterator = mLoadedTexture.begin();
        while (texIterator != mLoadedTexture.end()) {
            if (texIterator->second.unique()) {
                mLoadedTexture.erase(texIterator);
                return;
            }
            texIterator++;
        }
    }

    shared<sf::Font> AssetManager::LoadFont(const std::string &fontPath) {
        Dict<std::string, shared<sf::Font>>::iterator fontFound = mLoadedFonts.find(mRootDir + fontPath);
        if (fontFound == mLoadedFonts.end()) {
            shared<sf::Font> font{new sf::Font{}};
            if (font->loadFromFile(mRootDir + fontPath)) {
                mLoadedFonts.insert({fontPath, font});
                return font;
            } else {
                return shared<sf::Font>{nullptr};
            }
        }
        return fontFound->second;
    }
}