#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP

#include <vector>
#include <unordered_map>
#include "IScene.hpp"
#include "Land.hpp"
#include "Player.hpp"
#include "ResourceInfo.hpp"

class PlayScene final : public IScene {
private:
	std::vector<Land *> lands;
	std::unordered_map<std::string, ResourceInfo> resources;
	Player* player;
public:
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
	void AddNewResourceType(std::string name, std::string img, int hp, int universality);
	ResourceInfo& GetResourceInfo(std::string name);
};
#endif

