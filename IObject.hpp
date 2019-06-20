#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include "Point.hpp"

class IObject {
protected:
	explicit IObject() = default;
	explicit IObject(float x, float y, float w=0, float h=0, float anchorX=0, float anchorY=0);
public:
	bool visible = false;
	Point position;
	Point size;
	Point anchor;
	virtual ~IObject() = default;
	IObject(const IObject&) = default;
	IObject& operator=(const IObject&) = default;
	virtual void Draw() const;
	virtual void Update(float deltaTime);
	Point LeftUpCorner() const;
	Point RightDownCorner() const;
};
#endif

