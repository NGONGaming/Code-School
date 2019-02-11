#pragma once

#include "utils.h"

static std::mt19937& rand_gen()
{
	static const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 gen(seed);
    return gen;
}

int random(int aStart, int aEnd)
{
    std::uniform_int_distribution<> dis(aStart, aEnd);

    return dis(rand_gen());
}