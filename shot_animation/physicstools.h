#pragma once

#include "particle.h"

template <typename ParticleType, typename ForceType>
void applyForce(ParticleType & particle ,ForceType force)
{
    force /= particle.mass;
    particle.acceleration += force;
}
