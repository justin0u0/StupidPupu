#ifndef ISCENE_HPP
#define ISCENE_HPP

class IScene {
protected:
	// IScene can only not instantiated directed
	explicit IScene() = default;
public:
	// Copy constructor is deleted
	IScene(IScene const&) = delete;
	// Copy assignment is deleted
	IScene& operator=(IScene const&) = delete;
	// The default virtual destructor to support polymorphism destruction
	virtual ~IScene() = default;
	virtual void Initialize() = 0;
	virtual void Terminate() = 0;
	void Draw() const;
	virtual void Update(float deltaTime) = 0;
};
#endif

