// spritehelper.h 
// Trevor

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class SpriteHelper {
public:
  SpriteHelper(std::string filepath);
  Sprite getSprite(int x, int y);
 private:
  Texture mainTexture;
  Sprite  mainSpriteSheet;
};