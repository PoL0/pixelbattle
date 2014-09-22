// animation.h
//
// Used as a singleton helper class for all 
// other objects in the rts "namespace". 
// Shared instance necessary. Defines all the
// references to sprites through enum
// definition.

#pragma once

#include <SFML/Graphics.hpp>    	// for use of Texture and Sprite
#include <SFML/Graphics/Color.hpp>  // for use of Color class
#include <SFML/Graphics/Image.hpp>  // for use of Image class

using namespace sf;

class AnimationHelper {
public:
	enum class HelmetType {
		SabreToothHead,
		BobbedWithBone,
		AztecBirdHeaddress,
		JaguarHead,
		EgyptianKhat,
	};
	enum class spriteDesc {
		Stand,
		Walk1,
		Walk2,
		Slash1,
		Slash2,
		Shoot,
		Flee1,
		Flee2,
	};
	enum class spriteDir {
		Right,
		Left,
		Down,
		Up
	};
	enum class spriteColor {
		Blue,
		Red,
		Green,
		Purple
	};

	static AnimationHelper* Instance();
	void setSheet(std::string filepath);

	Sprite* getSoldier(spriteColor color, spriteDesc description, spriteDir dir, int x_draw, int y_draw);
	//Sprite* getHelmet(spriteColor color, HelmetType helm, spriteDir dir, bool fleeing, int x_draw, int y_draw);

	Sprite* getUtility(int x, int y, int width, int height, int x_draw, int y_draw);

 private:
 	AnimationHelper(){}
 	static AnimationHelper* m_pInstance;

 	Texture sharedTexture;
	Sprite  sharedSprite;
};