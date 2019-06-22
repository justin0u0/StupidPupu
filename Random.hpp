#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <vector>
#include <chrono>

class Random {
private:
	std::default_random_engine gen = std::default_random_engine(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	explicit Random() = default;
public:
	int Integer(int min_val, int max_val);
	float Float(float min_val, float max_val);
	std::vector<int> WeightedIntergerSequence(int size, std::vector<int> weights);
	static Random& GetRandom();
};
#endif

