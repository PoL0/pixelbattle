// rtssoldier.cpp

#include <SFML/Graphics.hpp>

#include "animationhelper.h"
#include "rtssoldier.h"
#include "rtsmovable.h"

using namespace sf;

#define FRAMERATE 15

#define des AnimationHelper::spriteDesc
#define dir AnimationHelper::spriteDir
#define col AnimationHelper::spriteColor

RTSSoldier::RTSSoldier(RenderWindow *window) : RTSMovable (window){
	this->window = window;
	x = 0;
	y = 0;

	walkSpeed = 3;
	runSpeed = 6;
	targetX = 0;
	targetY = 0;
	direction = 0;

	frame = false;
	atTarget = false;
	running = false;

	lastFrame = des::Stand;  
	lastDir = dir::Down;   
	teamColor = col::Blue;
}

void RTSSoldier::setTeamColor(AnimationHelper::spriteColor teamColor){
	this->teamColor = teamColor;
}

void RTSSoldier::draw(int frameCount){
	if(frameCount%FRAMERATE != 0){
		window->draw(* AnimationHelper::Instance()->getSoldier(teamColor, lastFrame, lastDir, x, y));
		return;
	}

	move();
}