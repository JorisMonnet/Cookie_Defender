#pragma once

template <typename VecType>
struct Particle
{
    VecType position;
    VecType velocity;

    float life = 0;
};
