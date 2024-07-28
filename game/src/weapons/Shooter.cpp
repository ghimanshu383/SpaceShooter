//
// Created by ghima on 17-07-2024.
//
#include "weapons/Shooter.h"

namespace ly {
    Shooter::Shooter(Actor *owningActor) : mOwnerActor{owningActor} {
    }

    void Shooter::Init() {
        if (CanShoot() && !IsOnCoolDown()) {
            ShootImpl();
        }
    }

    Actor *Shooter::GetOwningActor() const {
        return mOwnerActor;
    }

}