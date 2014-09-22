// rtsunit.cpp

#include "rtsunit.h"

#define FRAMERATE 60

RTSUnit::RTSUnit(){
	updateUnit();
}

void RTSUnit::addMovable(RTSMovable *movable){
	movableList.push_back(movable);
}

void RTSUnit::drawMovables(int frameCount){
	if(frameCount%FRAMERATE == 0){
		updateUnit();
	}

	for(int i(0); i < movableList.size(); ++i){
		movableList[i]->draw(frameCount);
	}
}

void RTSUnit::setTargets(int targetX, int targetY){
	// change to have x, y offsets from unit
	for(int i(0); i < movableList.size(); ++i){
		movableList[i]->setTarget(targetX, targetY);
	}
}


void RTSUnit::updateUnit(){
	// sort and reorganize x and y coords
}