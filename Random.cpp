#include <random>
#include "Random.hpp"

int Random::Integer(int min_val, int max_val) {
	std::uniform_int_distribution<int> dis(min_val, max_val);
	return dis(gen);
}
float Random::Float(float min_val, float max_val) {
	std::uniform_real_distribution<float> dis(min_val, max_val);
	return dis(gen);
}
std::vector<int> Random::WeightedIntergerSequence(int size, std::vector<int> weights) {
	std::discrete_distribution<int> dis(weights.begin(), weights.end());
	std::vector<int> result;
	for (int i = 0; i < size; i++)
		result.emplace_back(dis(gen));
	return result;
}
Random& Random::GetRandom() {
	static Random random;
	return random;
}

