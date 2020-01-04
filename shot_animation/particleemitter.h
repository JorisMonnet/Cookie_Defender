#pragma once

#include "particle.h"
/**
 *Class ParticleEmitter
 *
 * this class provide some usefull particles for the animation of the shoot
 */

template <typename containerType>
class ParticleEmitter
{
public:
    template<typename Func>
    void init(int N, Func f)
    {
        particles.resize(N);
        for(int i =0; i<N; i++)
            f(particles[i], i);
    }

    template<typename Func>
    void visit(Func f)
    {
        for(int i =0;i<particles.size();i++)
        {
            f(particles[i], i);
        }
    }

    template<typename ParticleType>
    void integrate(ParticleType &particle, double dt)
    {
        particle.position += particle.velocity *dt;
        particle.velocity += particle.acceleration *dt;
    }

    void update(double dt)
    {
        for(auto & particle : particles)
            integrate(particle, dt);
    }
private:
    containerType particles;
};

