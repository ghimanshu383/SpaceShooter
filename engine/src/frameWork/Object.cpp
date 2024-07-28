//
// Created by ghima on 15-07-2024.
//

#include "frameWork/Object.h"

namespace ly {
    Object::Object() : mPendingDestroy{false} {}

    Object::~Object() {
        Destroy();
    }

    void Object::Destroy() {
        if (!mPendingDestroy) {
            mPendingDestroy = true;
        }
    }
}