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

Sprite* AnimationHelper::getSoldier(spriteColor color, spriteDesc description, spriteDir dir, int x_draw, int y_draw){
	int colorOffset = static_cast<unsigned int>(color);
	int directionOffset = static_cast<unsigned int>(dir);
	int frameOffset = static_cast<unsigned int>(description);

	sharedSprite.setTextureRect(IntRect(frameOffset,(colorOffset*64)+(directionOffset*16),16,16));

	sharedSprite.setPosition(Vector2f(x_draw, y_draw));
	return &sharedSprite;
}

Sprite* AnimationHelper::getUtility(int x, int y, int width, int height, int x_draw, int y_draw){
	sharedSprite.setTextureRect(IntRect(x,y,width,height));
	sharedSprite.setPosition(Vector2f(x_draw, y_draw));
	return &sharedSprite;
}