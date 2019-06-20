#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP

#include "IScene.hpp"

class PlayScene final : public IScene {
private:
public:
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
};
#endif

