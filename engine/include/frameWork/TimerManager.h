//
// Created by ghima on 20-07-2024.
//
#include <functional>

#include "Core.h"
#include "Object.h"

#ifndef LIGHTYEARS_TIMERMANAGER_H
#define LIGHTYEARS_TIMERMANAGER_H
namespace ly {

    struct Timer {
    public:
        Timer(Object *t, const std::function<void()> &callback, float duration, bool repeat) : mDuration{duration},
                                                                                               mRepeat{repeat},
                                                                                               mIsExpired{false},
                                                                                               mTimerCounter{0},
                                                                                               listener{t,
                                                                                                        callback} {};


        bool Expired() const {
            return mIsExpired || listener.first->isPendingDestroy();
        };

        void SetExpired() { mIsExpired = true; };

        void TickTimer(float deltaTime) {
            if (Expired()) {
                return;
            }
            mTimerCounter += deltaTime;
            if (mTimerCounter > mDuration) {
                listener.second();
                if (mRepeat) {
                    mTimerCounter = 0.f;
                } else {
                    SetExpired();
                }
            }
        };

    private:
        std::pair<Object *, std::function<void()>> listener;
        float mDuration;
        bool mRepeat;
        float mTimerCounter;
        bool mIsExpired;
    };

    class TimerManager {
    protected:
        static TimerManager *instance;
        Dict<unsigned int, Timer> mTimers{};

        TimerManager();

    public:
        static TimerManager *GetInstance();

        unsigned int timerCount = 0;

        template<typename T, typename std::enable_if<std::is_base_of<Object, T>::value>::type * = nullptr>
        unsigned int SetTimer(const weak<Object>& t, void(T::*callback)(), float duration, bool repeat = false) {
            std::function<void()> lam = [t, callback]() -> void {
                if (t.lock()->isPendingDestroy()) return;
                (reinterpret_cast<T *>(t.lock().get())->*callback)();
            };
            ++timerCount;
            mTimers.insert({timerCount, {t.lock().get(), lam, duration, repeat}});
            return timerCount;
        }

        void UpdateTimers(float deltaTime);

        void CleanUpTimer(unsigned int key);
    };
}
#endif //LIGHTYEARS_TIMERMANAGER_H
