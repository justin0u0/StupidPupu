#include "Land.hpp"
#include "GameEngine.hpp"
#include "Random.hpp"
#include "PlayScene.hpp"

Land::Land(std::string img, int x, int y)
	: Sprite(img, x, y, 800, 820), real_position(x, y) {
}
std::vector<int> Land::GetResourceWeights() {
	std::vector<int> weights;
	for (auto type : resource_types)
		weights.emplace_back(type.universality);
	return weights;
}
std::vector<int> Land::GetEnemyWeights() {
	std::vector<int> weights;
	for (auto type : enemy_types)
		weights.emplace_back(type.universality);
	return weights;
}
Point Land::NewSpawnPoint() {
	std::vector<Point> box;
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (!land_state[i][j])
				box.emplace_back(Point(i, j));
	Point p = box[Random::GetRandom().Integer(0, (int)box.size())];
	p -= Point(7.5, 7.5);
	p = p * (size.x / Size) + real_position;
	return p; 
}
void Land::Draw() const {
	Sprite::Draw();
	for (auto& resource : resources)
		resource->Draw();
	for (auto& enemy : enemies)
		enemy->Draw();
}
void Land::Update(float deltaTime) {
	Spawn(deltaTime);
	GameEngine& game = GameEngine::GetInstance();
	PlayScene* playscene = dynamic_cast<PlayScene *>(game.GetActiveScene());
	position = playscene->RepositionWithPivot(real_position);
	for (auto& resource : resources)
		resource->Update(deltaTime);
	for (auto& enemy : enemies)
		enemy->Update(deltaTime);
	for (auto it = resources.begin(); it != resources.end(); ) { 
		auto next_it = it;
		// resource died
		if ((*it)->health < 0) {
			Log(Debug) << "Resource died.";
			playscene->AddToPackage((*it)->item, 2);
			next_it = resources.erase(it);
		} else {
			next_it++;
		}
		it = next_it;
	}
	for (auto it = enemies.begin(); it != enemies.end(); ) {
		auto next_it = it;
		// enemy died
		if ((*it)->health < 0) {
			Log(Debug) << "Enemy died.";
			playscene->AddToPackage((*it)->item, 2);
			next_it = enemies.erase(it);
		} else {
			next_it++;
		}
		it = next_it;
	}
}
void Land::AddNewResourceType(std::string name) {
	PlayScene *playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
	resource_types.emplace_back(playscene->GetResourceInfo(name));
}
void Land::AddNewEnemyType(std::string name) {
	PlayScene *playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
	enemy_types.emplace_back(playscene->GetEnemyInfo(name));
}
void Land::Spawn(float deltaTime) {
	spawn_cooldown -= deltaTime;
	// spawn resource
	if (spawn_cooldown < 0.0) {
		spawn_cooldown = Random::GetRandom().Float(15.0, 30.0);
		Log(Info) << "Land Spawning Resources ...";
		SpawnResource();
		Log(Info) << "Land Spawning Enemies ...";
		SpawnEnemy();
		Log(Info) << "End Spawning";
	}
}
void Land::SpawnResource() {
	int ammount = std::min(Capacity - (int)resources.size(), Random::GetRandom().Integer(3, 5));
	std::vector<int> v = Random::GetRandom().WeightedIntergerSequence(ammount, GetResourceWeights());
	for (int i = 0; i < ammount; i++) {
		auto& type = resource_types[v[i]];
		Log(Verbose) << "Land spawning a " << type.type;
		Point p = NewSpawnPoint();
		Log(Verbose) << "SpawnPoint: " << p.x << ' ' << p.y;
		resources.emplace_back(new Resource(type.img, p.x, p.y, type.maximum_hp, type.item));
	}
}
void Land::SpawnEnemy() {
	int ammount = std::min(Capacity / Size - (int)enemies.size(), Random::GetRandom().Integer(1, 2));
	std::vector<int> v = Random::GetRandom().WeightedIntergerSequence(ammount, GetEnemyWeights());
	for (int i = 0; i < ammount; i++) {
		auto& type = enemy_types[v[i]];
		Log(Verbose) << "Land spawning a " << type.type;
		Point p = NewSpawnPoint();
		Log(Verbose) << "SpawnPoint: " << p.x << ' ' << p.y;
		enemies.emplace_back(new Enemy(type.img, p.x, p.y, type.size.x, type.size.y
			, type.maximum_hp, type.damage, type.speed, type.detect_radius, type.attack_cooldown, type.item));
	}
}
Point Land::LeftUpCorner() const {
	return Point(real_position.x - size.x / 2, real_position.y - size.y / 2);
}
Point Land::RightDownCorner() const {
	return Point(real_position.x + size.x / 2, real_position.y + size.y / 2); 
}

