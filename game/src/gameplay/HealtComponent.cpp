//
// Created by ghima on 19-07-2024.
//
#include "gameplay/HealthComponent.h"
#include <cmath>

namespace ly {
    HealthComponent::HealthComponent(float health, float maxHealth) : mHealth{health}, mMaxHealth{maxHealth} {}

    void HealthComponent::ChangeHealth(float amt) {
        if (amt == 0 || mHealth == 0) return;
        mHealth += amt;
        if (mHealth < 0) {
            mHealth = 0;
        }
        if (mHealth > mMaxHealth) {
            mHealth = mMaxHealth;
        }

        if (amt < 0) {
            TakenDamage(std::abs(amt));
            if (mHealth <= 0) {
                HealthEmpty();
            }
        } else {
            HealthRegin(amt);
        }

    }

    void HealthComponent::HealthEmpty() {
        mHealthEmptyDelegate.Invoke();
    }

    void HealthComponent::TakenDamage(float amt) {
        mHealthDelegate.Invoke(amt);
    }

    void HealthComponent::HealthRegin(float amt) {

    }
}