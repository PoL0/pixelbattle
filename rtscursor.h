// rtscursor.h
//
// Defines a cursor object used in the rts 
// "namespace". Can be very simple drawn by
// calling the draw functions.

#include <SFML/Graphics.hpp>

#include "rtsdrawable.h"

class RTSCursor : public RTSDrawable {
public:
	RTSCursor(RenderWindow *window) : RTSDrawable(window){}
	void draw();
protected:
};