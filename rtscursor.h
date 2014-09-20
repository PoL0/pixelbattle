// rtscursor.h
// Trevor

#include <SFML/Graphics.hpp>

#include "rtsdrawable.h"

class RTSCursor : public RTSDrawable {
public:
	RTSCursor(RenderWindow *window) : RTSDrawable(window){}
	void draw();
protected:
};