// rtsmovable.cpp

#include <SFML/Graphics.hpp>
#include <math.h>       // For use of Atan2()
#include <iostream>

#include "animationhelper.h"
#include "rtsmovable.h"

#define PRECISION 4
#define FRAMERATE 15

#define PI 3.14

#define des AnimationHelper::spriteDesc
#define dir AnimationHelper::spriteDir
#define col AnimationHelper::spriteColor

using namespace sf;

RTSMovable::RTSMovable(RenderWindow *window) : RTSDrawable (window){
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

void RTSMovable::draw(int frameCount){
	if(frameCount%FRAMERATE != 0){
		window->draw(* AnimationHelper::Instance()->getSoldier(teamColor, lastFrame, lastDir, x, y));
		return;
	}

	move();
}

void RTSMovable::move(){

	atTarget = (x < targetX+PRECISION && x > targetX-PRECISION && y < targetY+PRECISION && y > targetY-PRECISION);

	if(! atTarget){
		double deltaX = targetX-x;
		double deltaY = targetY-y;

		direction = atan2(deltaY, deltaX);

		double speed;
		if(running){
			speed = runSpeed;
		} else {
			speed = walkSpeed;
		}

		x+=speed*cos(direction);
		y+=speed*sin(direction);

		double dirDeg = direction * 180 / PI;
		int dirDegInt = int(dirDeg)%360;
		if(dirDegInt < 0){
			dirDegInt+=360;
		}

		if(dirDegInt <= 45 || dirDegInt >= 315){
			lastDir = dir::Right;
		} else if (dirDegInt > 45 && dirDegInt <= 135){
			lastDir = dir::Down;
		} else if (dirDegInt > 135 && dirDegInt <= 225){
			lastDir = dir::Left;
		} else {
			lastDir = dir::Up;
		}

		if(frame){
			lastFrame = des::Walk1;
		} else {
			lastFrame = des::Walk2;
		}

		frame = !frame;
		
	} else {
		lastFrame = des::Stand;
	}

	window->draw(* AnimationHelper::Instance()->getSoldier(teamColor, lastFrame, lastDir, x, y));
	
}

void RTSMovable::setTarget(double targetX, double targetY){
	this->targetX = targetX;
	this->targetY = targetY;
}