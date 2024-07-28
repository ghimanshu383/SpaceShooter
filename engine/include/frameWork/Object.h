//
// Created by ghima on 15-07-2024.
//

#include <memory>
#include "Core.h"

#ifndef LIGHTYEARS_OBJECT_H
#define LIGHTYEARS_OBJECT_H
namespace ly {
    class Object : public std::enable_shared_from_this<Object> {
    private:
        bool mPendingDestroy;
    public:
        Object();

        virtual ~Object();

        virtual void Destroy();

        bool isPendingDestroy() const { return mPendingDestroy; };

        weak<Object> GetWeakRef() {
            return weak<Object>{shared_from_this()};
        }

    };
}
#endif //LIGHTYEARS_OBJECT_H
