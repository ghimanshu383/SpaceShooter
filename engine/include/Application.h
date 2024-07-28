//
// Created by ghima on 14-07-2024.
//

#include <SFML/Graphics.hpp>

#include "Core.h"
#include "frameWork/World.h"
#include "frameWork/Actor.h"


#ifndef LIGHTYEARS_APPLICATION_H
#define LIGHTYEARS_APPLICATION_H
namespace ly {
    class Application {
    private:
        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mClock;
        sf::Clock mAssetCleanClock;
        float cleanCycleInterval;
        shared<World> currentWorld;
        sf::Vector2u mWindowSize;
    public:
        void Init();

        Application(unsigned int width, unsigned int height, const char *title);

        void Tick(float deltaTime);

        virtual void Render();

        void RenderInternal();

        sf::Vector2u GetWindowSize() const;

        sf::RenderWindow &GetWindow() { return mWindow; };

        // Adding the utility function.
        template<typename T, typename... Args, typename std::enable_if<std::is_base_of<World, T>::value, T>::type * = nullptr>
        shared<T> SpawnWorld(Args... args) {
            shared<T> world{new T{this, args...}};
            currentWorld = world;
            return world;
        }
    };

    extern void Run();
}
#endif //LIGHTYEARS_APPLICATION_H
