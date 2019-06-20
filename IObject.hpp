#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include "Point.hpp"

	// The base interface class for objects that needs to be drawn or rendered.
class IObject {
protected:
	// The interface cannot be instantiated directly, must be inherited.
	explicit IObject() = default;
	/// anchorX: The centerX of the object. (0, 0) means top-left, while (1, 0) means top-right
	// anchorY: The centerY of the object. (0, 1) means bottom-left, while (1, 1) means bottom-right.
	explicit IObject(float x, float y, float w = 0, float h = 0, float anchorX = 0, float anchorY = 0);
public:
	bool Visible = true;
	Point Position;
	Point Size;
	Point Anchor;
	
	virtual ~IObject() = default;
	IObject(const IObject& other);
	IObject& operator=(IObject const&) = default;
	
	virtual void Draw() const;
	virtual void Update(float deltaTime);
};
#endif // IOBJECT_HPP

