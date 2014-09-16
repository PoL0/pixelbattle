// spritehelper.h 
// Trevor

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class SpriteHelper {
public:
	static SpriteHelper* Instance();
	void setSheet(std::string filepath);
	Sprite getSprite(int x_draw, int y_draw, int column, int row);
 private:
 	SpriteHelper(){};
 	static SpriteHelper* m_pInstance;

	Texture mainTexture;
	Sprite  mainSpriteSheet;
};