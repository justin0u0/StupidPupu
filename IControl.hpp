#ifndef ICONTROL_HPP
#define ICONTROL_HPP

class IControl {
private:
	explicit IControl() = default;
public:
	virtual OnKeyDown(int keyCode);

	virtual OnKeyUp(int keyCode);

	virtual OnMouseDown(int button, int mx, int my) {}

	virtual OnMouseUp(int button, int mx, int my) {}

	virtual OnMouseMove(int mx, int my) {}
}
#endif
