#include "Random.hpp"

#include <random>

int Random::RandomInteger(int min_val, int max_val) {
	static std::random_device rd;
	static std::default_random_engine gen(rd());
	std::uniform_int_distribution<int> dis(min_val, max_val);
	return dis(gen);
}
float Random::RandomFloat(float min_val, float max_val) {
	static std::random_device rd;
	static std::default_random_engine gen(rd());
	std::uniform_real_distribution<float> dis(min_val, max_val);
	return dis(gen);
}
std::vector<int> Random::RandomWeightedIntergerSequence(int size, std::vector<int> weights) {
	static std::random_device rd;
	static std::default_random_engine gen(rd());
	std::discrete_distribution<int> dis(weights.begin(), weights.end());
	std::vector<int> result;
	for (int i = 0; i < size; i++)
		result.emplace_back(dis(gen));
	return result;
}

