#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

class Random {
public:
	explicit Random() = delete;
	static int RandomInteger(int min_val, int max_val);
	static float RandomFloat(float min_val, float max_val);
};
#endif

