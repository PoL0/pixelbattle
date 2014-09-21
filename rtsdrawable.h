// rtsdrawable.h
//
// Defines a drawable object. Meant to
// be a virtual object, but can be 
// instantiated and still used. Base
// class to RTSMovable, RTSCursor, and
// RTSTile objects.

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