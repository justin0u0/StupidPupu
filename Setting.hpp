#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "ImageButton.hpp"
#include "Image.hpp"
#include "Text.hpp"

// modify sound, sfx, save file, exit
class Setting : public Image, public IControl {
private:
	// 0 bgm_label, 1 bgm_value, 2 sfx_label, 3 sfx_value
	Text* labels[4];
	// 0 bgm_louder, 1 bgm_lower, 2 sfx_louder, 3 sfx_lower
	ImageButton* buttons[4];
public:
	float bgm_value;
	float sfx_value;
	explicit Setting();
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void Draw() const override;
	void ReverseStatus();
	bool Status() const;
	void SetValue(std::function<void(void)> onclick_function, int id);
}; 

