// rtsmovable.h
// 
//

#pragma once

#include <SFML/Graphics.hpp>

#include "animationhelper.h"
#include "rtsdrawable.h"

using namespace sf;

class RTSMovable : public RTSDrawable {
public:
	RTSMovable(RenderWindow *window) : RTSDrawable (window){}
	void draw(int frameCount);
	void setTarget(double targetX, double targetY);
protected:
	double targetX;
	double targetY;
	double direction;
	AnimationHelper::spriteDesc  lastFrame;
	AnimationHelper::spriteDir   lastDir;
	AnimationHelper::spriteColor teamColor;
};