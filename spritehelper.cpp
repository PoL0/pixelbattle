// Spritehelper.cpp
// Trevor
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "spritehelper.h"

using namespace sf;

SpriteHelper::SpriteHelper(std::string filepath){
    if (! spriteSheetTexture.loadFromFile(filepath) ){
    	std::cout << "Error: Could not load file: " << filepath << "\n";
    } else {
    	std::cout << "Successfully loaded " << filepath << "\n";
    }
}