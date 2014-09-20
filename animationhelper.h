// animation.h
// Trevor

#pragma once

#include <SFML/Graphics.hpp>    	// for use of Texture and Sprite
#include <SFML/Graphics/Color.hpp>  // for use of Color class

using namespace sf;

class AnimationHelper {
public:
	enum class spriteType {
		Character,
		Helmet,
		Animal,
		Weapon,
		Projectile,
		MapTile,
		Utility
	};
	enum class spriteCivilization {
		Neolithic,
		Egyptian
	};

	static AnimationHelper* Instance();
	void setSheet(std::string filepath);
	Sprite* getAnimation(spriteType type, Color teamColor, int x_draw, int y_draw);
 private:
 	AnimationHelper(){};
 	static AnimationHelper* m_pInstance;

 	Sprite* getSprite(int x_draw, int y_draw, int column, int row);

 	Texture mainTexture;
	Sprite  mainSpriteSheet;
};