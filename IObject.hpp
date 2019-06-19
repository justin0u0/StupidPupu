#ifndef IOBJECT_HPP
#define IOBJECT_HPP

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
	IObject(const IObject& other) = default;
	IObject& operator=(IObject const&) = default;
};
#endif
