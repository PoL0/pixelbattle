// rtscursor.cpp

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "animationhelper.h"
#include "rtscursor.h"

using namespace sf;

#define X_TILE 3
#define Y_TILE 16

void RTSCursor::draw(){
	x = Mouse::getPosition(*window).x;
	y = Mouse::getPosition(*window).y;
	window->draw(* AnimationHelper::Instance()->getUtility(X_TILE*16, Y_TILE*16, 32, 32, x, y));
}