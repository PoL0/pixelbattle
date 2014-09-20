// animation.h
// Trevor

#pragma once

#include <SFML/Graphics.hpp>    	// for use of Texture and Sprite
#include <SFML/Graphics/Color.hpp>  // for use of Color class
#include <SFML/Graphics/Image.hpp>  // for use of Image class

using namespace sf;

class AnimationHelper {
public:
	enum class spriteCiv {
		Neolithic,
		Egyptian
	};
	enum class spriteDesc {
		Stand,
		Walk,
	};
	enum class spriteDir {
		Up,
		Down,
		Right,
		Left
	};
	enum class spriteColor {
		Red,
		Green,
		Blue,
		Purple
	};

	static AnimationHelper* Instance();
	void setSheet(std::string filepath);

	Sprite* getSoldier(spriteColor color, spriteDesc description, spriteDir dir, int x_draw, int y_draw);
	Sprite* getHelmet(spriteColor color, spriteCiv civ, spriteDir dir, bool fleeing, int x_draw, int y_draw);

 private:
 	AnimationHelper(){}
 	static AnimationHelper* m_pInstance;

 	Texture sharedTexture;
	Sprite  sharedSprite;
};