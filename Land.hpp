#ifndef LAND_HPP
#define LAND_HPP

#include <vector>
#include "Sprite.hpp"
#include "Point.hpp"
#include "ResourceInfo.hpp"
#include "Resource.hpp"
#include "EnemyInfo.hpp"
#include "Enemy.hpp"

class Land : public Sprite {
	friend class Player;
	friend class Enemy;
private:
	Point real_position;
	const int Size = 16;
	const int Capacity = Size * Size / 2;
	float spawn_cooldown = 0.0;
	// Resources
	std::vector<std::vector<bool>> land_state = std::vector<std::vector<bool>>(Size, std::vector<bool>(Size));
	std::vector<ResourceInfo> resource_types;
	std::vector<Resource *> resources;
	// Enemies
	std::vector<EnemyInfo> enemy_types;
	std::vector<Enemy *> enemies;
	// Utilities
	std::vector<int> GetResourceWeights();
	std::vector<int> GetEnemyWeights();
	Point NewSpawnPoint();
	// TODO: unlock requirement;
	// TODO: locked
public:
	explicit Land(std::string img, int x, int y);
	void Draw() const override;
	void Update(float deltaTime) override;
	void AddNewResourceType(std::string name);
	void AddNewEnemyType(std::string name);
	void Spawn(float deltaTime);
	void SpawnResource();
	void SpawnEnemy();
	Point LeftUpCorner() const;
	Point RightDownCorner() const;
};
#endif

