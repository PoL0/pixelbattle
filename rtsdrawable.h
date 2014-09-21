// rtsdrawable.h

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class RTSDrawable {
public:
	RTSDrawable(RenderWindow *window);
	void draw();
	void setPosition(double x, double y);
protected:
	RenderWindow *window;
	double x;
	double y;
};