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

void AnimationHelper::setSheet(std::string filepath){
	if (! sharedTexture.loadFromFile(filepath) ){
    	std::cout << "Error: Could not load file: " << filepath << "\n";
    }
    sharedSprite.setTexture(sharedTexture);
}

//Sprite* AnimationHelper::getSprite(int x_draw, int y_draw, int column, int row){
	//mainSpriteSheet.setTextureRect(IntRect(row*16,column*16,16,16));
	//mainSpriteSheet.setPosition(Vector2f(x_draw, y_draw));
	//return &mainSpriteSheet;
//}