#pragma once

template <typename VecType>
struct Particle
{
    VecType position;
    VecType velocity;
    VecType acceleration;

    double life = 0.0;
    double mass = 0.0;
};
