#ifndef LAND_HPP
#define LAND_HPP

#include "Sprite.hpp"

class Land : public Sprite {
private:
	// TODO: belong's enemies
	// TODO: unlock requirement;
	bool locked = true;
public:
	explicit Land(std::string img, int x, int y);
//	void Unlock();
	void Update(float deltaTime) override;
};
#endif

