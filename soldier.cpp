// soldier.cpp
// Trevor

#include <SFML/Graphics.hpp> // For the window

#include "soldier.h"

using namespace sf;

Soldier::Soldier(RenderWindow window){
	mainWindow = &window;
}

void Soldier::draw(){
	mainWindow.draw();
}