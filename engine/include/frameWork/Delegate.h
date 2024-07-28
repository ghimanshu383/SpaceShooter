//
// Created by ghima on 19-07-2024.
//
#include <functional>
#include "Object.h"
#include <Core.h>

#ifndef LIGHTYEARS_DELEGATE_H
#define LIGHTYEARS_DELEGATE_H
namespace ly {
    template<typename... Args>
    class Delegate {
    private:
        List<std::function<bool(Args...)>> implFunction;
    public:
        template<class T, typename std::enable_if<std::is_base_of<Object, T>::value, T>::type * = nullptr>
        void Register(T *t, void(T::*callback)(Args...)) {
            std::function<bool(Args...)> lam = [t, callback](Args... args) {
                if (!(reinterpret_cast<Object *>(t))->isPendingDestroy()) {
                    (t->*callback)(args...);
                    return true;
                }
                return false;
            };
            implFunction.emplace_back(lam);
        }

        void Invoke(Args... args) {
            auto funcIter = implFunction.begin();
            while (funcIter != implFunction.end()) {
                if ((*funcIter)(args...)) {
                    funcIter++;
                } else {
                    implFunction.erase(funcIter);
                }
            }
        }
    };
}


#endif //LIGHTYEARS_DELEGATE_H
