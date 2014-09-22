// rtsunit.h
//
//

#pragma once

#include <vector>

#include "rtsmovable.h"

class RTSUnit {
public:
	RTSUnit();
	void addMovable(RTSMovable *movable);
	void drawMovables(int frameCount);
	void setTargets(int x, int y);
private:
	void updateUnit();
	std::vector<RTSMovable*> movableList;
	
	int x;
	int y;
};