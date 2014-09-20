// rtscursor.cpp
// Trevor

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "animationhelper.h"
#include "rtscursor.h"

using namespace sf;

void RTSCursor::draw(){
	x = Mouse::getPosition(*window).x;
	y = Mouse::getPosition(*window).y;
	window->draw(* AnimationHelper::Instance()->getUtility(48, 256, 32, 32, x, y));
}