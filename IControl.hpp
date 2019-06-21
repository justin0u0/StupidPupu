#ifndef ICONTROL_HPP
#define ICONTROL_HPP

class IControl {
	protected:
		explicit IControl() = default;
	public:
		virtual ~IControl() = default;
		// Copy constructor
		IContol(const IControl& other);
		IControl& operator=(IControl const&) = default;
		
		virtual void OnKeyDown(int keycode);
		virtual void OnKeyUp(int keycode);
		virtual void OnMouseDown(int button, int mx, int my);
		virtual void OnMouseUp(int button, int mx, int my);
		virtual void OnMouseMove(int mx, int my);
		virtual void OnMouseScroll(int mx, int my, int delta);
};	

#endif // ICONTROL_HPP
