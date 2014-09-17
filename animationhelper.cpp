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

Sprite* AnimationHelper::getAnimation(animationFrame frame, int x_draw, int y_draw){
	switch(frame){
		case animationFrame::SOLDIER_STAND_RIGHT:
			return this->getSprite(x_draw, y_draw, 0, 0);
		case animationFrame::SOLDIER_WALK_RIGHT:
			return this->getSprite(x_draw, y_draw, 0, 1);
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