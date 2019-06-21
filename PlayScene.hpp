#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP

#include <vector>
#include "IScene.hpp"
#include "Land.hpp"
#include "Player.hpp"

class PlayScene final : public IScene {
private:
	std::vector<Land *> lands;
	Player* player;
public:
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
};
#endif

