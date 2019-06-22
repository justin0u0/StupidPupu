#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include "Sprite.hpp"
#include "IControl.hpp"

class Resource : public Sprite, public IControl {
public:
	// type of the resource
	std::string type;
	// health point of the resource
	int health;
	explicit Resource(std::string img, float x, float y, int health);
	Resource(const Resource&) = default;
	Resource& operator=(const Resource&) = default;
	void Update(float deltaTime) override;
};
#endif

