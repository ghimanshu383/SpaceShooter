//
// Created by ghima on 19-07-2024.
//
#include <frameWork/vfx/Particle.h>
#include <frameWork/World.h>
#include <frameWork/MathUtil.h>

#include "vfx/Explosion.h"


namespace ly {
    Explosion::Explosion(int particleAmount, float lifeTimeMin, float lifeTimeMax, float speedMin, float speedMax,
                         float sizeMin, float sizeMax) : mParticleAmt{particleAmount},
                                                         mParticleTexPath{
                                                                 std::string{
                                                                         "SpaceShooterRedux/PNG/Effects/star1.png"},
                                                                 std::string{
                                                                         "SpaceShooterRedux/PNG/Effects/star2.png"},
                                                                 std::string{
                                                                         "SpaceShooterRedux/PNG/Effects/star3.png"},
                                                         },
                                                         lifeTimeMin{lifeTimeMin},
                                                         lifeTimeMax{lifeTimeMax},
                                                         speedMin{speedMin},
                                                         speedMax{speedMax},
                                                         sizeMin{sizeMin},
                                                         sizeMax{sizeMax},
                                                         mParticleColor{
                                                                 sf::Color::Red,
                                                                 sf::Color::Yellow
                                                         } {};

    void Explosion::SpawnExplosion(ly::World *owningWorld, sf::Vector2f location) {
        if (owningWorld == nullptr) return;
        for (int i = 0; i < mParticleAmt; i++) {
            std::string Path = mParticleTexPath[(int) RandomRange(0, mParticleTexPath.size() - .1f)];
            sf::Color randomColor = mParticleColor[(int) RandomRange(0, mParticleColor.size() - .1f)];
            weak<Particle> particle = owningWorld->SpawnActor<Particle, std::string, float, float, float, float, float, float, sf::Color>(
                    Path, lifeTimeMin, lifeTimeMax, speedMin, speedMax, sizeMin, sizeMax, randomColor);
            particle.lock()->SetActorLocation(location);
            particle.lock()->GetActorSprite().setColor(randomColor);
        }
    }
}