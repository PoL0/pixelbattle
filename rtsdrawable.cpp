// rtsdrawable.cpp
// Trevor

#include <SFML/Graphics.hpp>

#include "animationhelper.h"
#include "rtsdrawable.h"

using namespace sf;

RTSDrawable::RTSDrawable(RenderWindow *window){
	this->window = window;
	x = 0;
	y = 0;
}

void RTSDrawable::draw(){
	window->draw(* AnimationHelper::Instance()->getUtility(0, 0, 16, 16, x, y));
}

void RTSDrawable::setPosition(double x, double y){
	this->x = x;
	this->y = y;
}