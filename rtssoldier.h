// rtssoldier.h
//
//

#pragma once

#include <SFML/Graphics.hpp>

#include "animationhelper.h"
#include "rtsmovable.h"

using namespace sf;

class RTSSoldier : public RTSMovable {
public:
	RTSSoldier(RenderWindow *window);
	void setTeamColor(AnimationHelper::spriteColor teamColor);

	void draw(int frameCount);
	void attack();
	void defend();
	void flee();
protected:
};