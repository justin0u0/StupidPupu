#include "Land.hpp"
#include "GameEngine.hpp"
#include "Random.hpp"
#include "PlayScene.hpp"

Land::Land(std::string img, int x, int y)
	: Sprite(img, x, y, 800, 820) {
}
std::vector<int> Land::GetResourceWeights() {
	std::vector<int> weights;
	for (auto type : resource_types)
		weights.emplace_back(type.universality);
	return weights;
}
Point Land::NewSpawnPoint() {
	std::vector<Point> box;
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (!land_state[i][j])
				box.emplace_back(Point(i, j));
	return box[Random::RandomInteger(0, (int)box.size())];
}
void Land::Update(float deltaTime) {
	GameEngine& game = GameEngine::GetInstance();
	// Since Player is pivot at (0, 0), so lands need to move opposite side
	if (game.IsLeft())
		velocity.x = 60;
	else if (game.IsRight())
		velocity.x = -60;
	else
		velocity.x = 0;
	if (game.IsUp())
		velocity.y = 60;
	else if (game.IsDown())
		velocity.y = -60;
	else
		velocity.y = 0;
	Sprite::Update(deltaTime);
	for (auto& resource : resources) {
		resource->Update(deltaTime);
	}
}
void Land::AddNewResourceType(std::string name) {
	PlayScene* playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
	resource_types.emplace_back(playscene->GetResourceInfo(name));
}
void Land::Spawn(float deltaTime) {
	Log(Info) << "Land Spawning ...";
	spawn_cooldown -= deltaTime;
	// spawn resource
	if (spawn_cooldown < 0.0) {
		spawn_cooldown = Random::RandomFloat(15.0, 30.0);
		int ammount = std::min((int)resources.size() - Capacity, Random::RandomInteger(3, 5));
		std::vector<int> v = Random::RandomWeightedIntergerSequence(ammount, GetResourceWeights());
		for (int i = 0; i < ammount; i++) {
			auto& type = resource_types[v[i]];
			Log(Verbose) << "Land spawning a " << type.type;
			Point p = NewSpawnPoint();
			resources.emplace_back(new Resource(type.img, p.x, p.y, type.maximum_hp));
		}
	}
}

