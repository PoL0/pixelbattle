// Spritehelper.h 
// Trevor

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class SpriteHelper {
public:
  SpriteHelper(std::string filepath);
  Texture spriteSheetTexture;
};