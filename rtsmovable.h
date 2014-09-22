// rtsmovable.h
// 
// Class for a movable object that has a target
// and animates in sequence as it walks. Descended
// from RTSDrawable. Will be base class for RTSSoldier,
// RTSAnimal, and RTSProjectile.

#pragma once

#include <SFML/Graphics.hpp>

#include "animationhelper.h"
#include "rtsdrawable.h"

using namespace sf;

class RTSMovable : public RTSDrawable {
public:
	RTSMovable(RenderWindow *window);
	void move();
	void setTarget(double targetX, double targetY);
protected:
	double walkSpeed;
	double runSpeed;
	double targetX;
	double targetY;
	double direction;

	bool frame;
	bool atTarget;
	bool running;

	AnimationHelper::spriteDesc  lastFrame;
	AnimationHelper::spriteDir   lastDir;
	AnimationHelper::spriteColor teamColor;
};