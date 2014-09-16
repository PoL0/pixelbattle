// spritehelper.cpp
// Trevor

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "spritehelper.h"

using namespace sf;

SpriteHelper::SpriteHelper(std::string filepath){
    if (! mainTexture.loadFromFile(filepath) ){
    	std::cout << "Error: Could not load file: " << filepath << "\n";
    }
    mainSpriteSheet.setTexture(mainTexture);
}

Sprite SpriteHelper::getSprite(int x, int y){
	mainSpriteSheet.setTextureRect(IntRect(x*16,y*16,16,16));
	return mainSpriteSheet;
}