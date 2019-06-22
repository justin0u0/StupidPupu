#ifndef LAND_HPP
#define LAND_HPP

#include <vector>
#include "Sprite.hpp"
#include "ResourceInfo.hpp"
#include "Resource.hpp"
#include "Point.hpp"

class Land : public Sprite {
private:
	const int Size = 16;
	const int Capacity = Size * Size / 2;
	float spawn_cooldown = 0.0;
	std::vector<std::vector<bool>> land_state;
	// TODO: belong's enemies
	// TODO: unlock requirement;
	// TODO: locked
	std::vector<ResourceInfo> resource_types;
	std::vector<Resource *> resources;
	std::vector<int> GetResourceWeights();
	Point NewSpawnPoint();
public:
	explicit Land(std::string img, int x, int y);
	void Update(float deltaTime) override;
	void AddNewResourceType(std::string name);
	void Spawn(float deltaTime);
};
#endif

