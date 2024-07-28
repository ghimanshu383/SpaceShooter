//
// Created by ghima on 20-07-2024.
//
#include "frameWork/TimerManager.h"

namespace ly {

    TimerManager *TimerManager::instance = nullptr;

    TimerManager::TimerManager() = default;

    TimerManager *TimerManager::GetInstance() {
        if (instance == nullptr) {
            instance = new TimerManager{};
        }
        return instance;
    }

    void TimerManager::UpdateTimers(float deltaTime) {
        auto timerIter = mTimers.begin();
        while (timerIter != mTimers.end()) {
            if (timerIter->second.Expired()) {
                // mTimers.erase(timerIter);
                timerIter++;
            } else {
                timerIter->second.TickTimer(deltaTime);
                timerIter++;
            }
        }
    }

    void TimerManager::CleanUpTimer(unsigned int key) {
        Dict<unsigned int, Timer>::iterator iter = mTimers.find(key);
        if (iter != mTimers.end()) {
            iter->second.SetExpired();
        }
    }
}