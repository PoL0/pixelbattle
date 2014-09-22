// rtsmovable.cpp

#include "rtsmovable.h"

#define FRAMERATE 4

#define des AnimationHelper::spriteDesc
#define dir AnimationHelper::spriteDir
#define col AnimationHelper::spriteColor

void RTSMovable::draw(int frameCount){
	if(frameCount%FRAMERATE != 0){
		window->draw(* AnimationHelper::Instance()->getSoldier(teamColor, lastFrame, lastDir, x, y));
		return;
	}
}

void RTSMovable::setTarget(double targetX, double targetY){
	this->targetX = targetX;
	this->targetY = targetY;
}