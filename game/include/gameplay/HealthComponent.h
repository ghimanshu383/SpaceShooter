//
// Created by ghima on 19-07-2024.
//
#include <frameWork/Delegate.h>

#ifndef LIGHTYEARS_HEALTHCOMPONENT_H
#define LIGHTYEARS_HEALTHCOMPONENT_H
namespace ly {
    class HealthComponent {
    public:
        HealthComponent(float health, float maxHealth);

        void ChangeHealth(float amt);

        float GetHealth() const { return mHealth; };

        float GetMaxHealth() const { return mMaxHealth; };

        // Manage the health after the regin or the damage
        void HealthEmpty();

        void TakenDamage(float amt);

        void HealthRegin(float amt);

        Delegate<float> mHealthDelegate;

        Delegate<> mHealthEmptyDelegate;

    private:
        float mHealth;
        float mMaxHealth;
    };
}
#endif //LIGHTYEARS_HEALTHCOMPONENT_H
