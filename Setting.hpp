#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "ImageButton.hpp"
#include "Image.hpp"
#include "Text.hpp"

// modify sound, sfx, save file, exit
class Setting : public Image, public IControl {
private:
	ImageButton *bgm_louder, *bgm_lower;
	ImageButton *sfx_louder, *sfx_lower;
	Text *bgm_value, *sfx_value;
	Text *bgm_label, *sfx_label;
public:
	explicit Setting();
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void Draw() const override;
	void ReverseStatus();
	bool Status() const;
}; 

