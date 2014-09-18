// animationhelper.cpp
// Trevor
#include <SFML/Graphics.hpp>    // for use of Texture and Sprite
#include <stddef.h> 			// for use of NULL
#include <iostream>				// for use of cout

#include "animationhelper.h"

using namespace sf;

AnimationHelper* AnimationHelper::m_pInstance = NULL; 

AnimationHelper* AnimationHelper::Instance(){
	// Only allow one instance of class to be generated.
	if (!m_pInstance){   
		m_pInstance = new AnimationHelper;
	}
	return m_pInstance;
}

// Bigass switch statement... yechh
Sprite* AnimationHelper::getAnimation(animationFrame frame, int x_draw, int y_draw){
	switch(frame){
		case animationFrame::BLU_SOL_STD_RIT:
			return this->getSprite(x_draw, y_draw, 0, 0);
		case animationFrame::BLU_SOL_WAK_RIT:
			return this->getSprite(x_draw, y_draw, 0, 1);
		case animationFrame::BLU_SOL_JAB_RIT:
			return this->getSprite(x_draw, y_draw, 0, 2);
		case animationFrame::BLU_SOL_SLH_RIT:
			return this->getSprite(x_draw, y_draw, 0, 3);
		case animationFrame::BLU_SOL_SL2_RIT:
			return this->getSprite(x_draw, y_draw, 0, 4);
		case animationFrame::BLU_SOL_SHT_RIT:
			return this->getSprite(x_draw, y_draw, 0, 5);
		case animationFrame::BLU_SOL_FLE_RIT:
			return this->getSprite(x_draw, y_draw, 0, 6);
		case animationFrame::BLU_SOL_FL2_RIT:
			return this->getSprite(x_draw, y_draw, 0, 7);
		case animationFrame::BLU_HED_NEO_RIT:
			return this->getSprite(x_draw, y_draw, 0, 8);
		case animationFrame::BLU_HE2_NEO_RIT:
			return this->getSprite(x_draw, y_draw, 0, 9);
		case animationFrame::BLU_HEL_NEO_RIT:
			return this->getSprite(x_draw, y_draw, 0, 10);

		case animationFrame::TIL_GRD_GRS_FLW:
			return this->getSprite(x_draw, y_draw, 16, 0);
		default:
			break;
	}
}

void AnimationHelper::setSheet(std::string filepath){
	if (! mainTexture.loadFromFile(filepath) ){
    	std::cout << "Error: Could not load file: " << filepath << "\n";
    }
    mainSpriteSheet.setTexture(mainTexture);
}

Sprite* AnimationHelper::getSprite(int x_draw, int y_draw, int column, int row){
	mainSpriteSheet.setTextureRect(IntRect(row*16,column*16,16,16));
	mainSpriteSheet.setPosition(Vector2f(x_draw, y_draw));
	return &mainSpriteSheet;
}