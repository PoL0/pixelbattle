// spritehelper.cpp
// Trevor

#include <SFML/Graphics.hpp>    // for use of Texture and Sprite
#include <stddef.h> 			// for use of NULL
#include <iostream> 			// for use of cout
#include <string>   			// for use of std::string

#include "spritehelper.h"

using namespace sf;

SpriteHelper* SpriteHelper::m_pInstance = NULL; 

SpriteHelper* SpriteHelper::Instance(){
	// Only allow one instance of class to be generated.
	if (!m_pInstance){   
		m_pInstance = new SpriteHelper;
	}
	return m_pInstance;
}

void SpriteHelper::setSheet(std::string filepath){
	 if (! mainTexture.loadFromFile(filepath) ){
    	std::cout << "Error: Could not load file: " << filepath << "\n";
    }
    mainSpriteSheet.setTexture(mainTexture);
}

Sprite SpriteHelper::getSprite(int x_draw, int y_draw, int column, int row){
	mainSpriteSheet.setTextureRect(IntRect(row*16,column*16,16,16));
	mainSpriteSheet.setPosition(Vector2f(x_draw, y_draw));
	return mainSpriteSheet;
}