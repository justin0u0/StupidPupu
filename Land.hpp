#ifndef LAND_HPP
#define LAND_HPP

#include <vector>
#include "Sprite.hpp"
#include "ResourceInfo.hpp"
#include "Resource.hpp"
#include "EnemyInfo.hpp"
#include "Enemy.hpp"

class Land : public Sprite {
private:
	const int Size = 16;
	const int Capacity = Size * Size / 2;
	float spawn_cooldown = 0.0;
	// Resources
	std::vector<std::vector<bool>> land_state = std::vector<std::vector<bool>>(Size, std::vector<bool>(Size));
	std::vector<ResourceInfo> resource_types;
	std::vector<Resource *> resources;
	std::vector<int> GetResourceWeights();
	Point NewSpawnPoint();
	// Enemies
	std::vector<EnemyInfo> enemy_types;
	std::vector<Enemy *> enemies;
	// TODO: unlock requirement;
	// TODO: locked
public:
	explicit Land(std::string img, int x, int y);
	void Draw() const override;
	void Update(float deltaTime) override;
	void AddNewResourceType(std::string name);
	void AddNewEnemyType(std::string name);
	void Spawn(float deltaTime);
};
#endif

