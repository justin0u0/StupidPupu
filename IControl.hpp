#ifndef ICONTROL_HPP
#define ICONTROL_HPP

class IControl {
private:
	explicit IControl() = default;
public:
	virtual void OnKeyDown(int keyCode);

	virtual void OnKeyUp(int keyCode);

	virtual void OnMouseDown(int button, int mx, int my);

	virtual void OnMouseUp(int button, int mx, int my);

	virtual void OnMouseMove(int mx, int my);
};
#endif
