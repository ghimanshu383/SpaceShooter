//
// Created by ghima on 17-07-2024.
//

#ifndef LIGHTYEARS_SHOOTER_H
#define LIGHTYEARS_SHOOTER_H
namespace ly {
    class Actor;

    class Shooter {
    protected:
        explicit Shooter(Actor *owningActor);

        virtual bool CanShoot() { return true; }

        virtual bool IsOnCoolDown() { return false; }

        void Init();

        Actor *GetOwningActor() const;

    public:
        virtual void ShootImpl() = 0;
    private:
        Actor *mOwnerActor;
    };
}
#endif //LIGHTYEARS_SHOOTER_H
