// animationhelper.cpp
// Trevor
#include <SFML/Graphics.hpp>    // for use of Texture and Sprite
#include <stddef.h> 			// for use of NULL

#include "animationhelper.h"
#include "spritehelper.h"

using namespace sf;

AnimationHelper* AnimationHelper::m_pInstance = NULL; 

AnimationHelper* AnimationHelper::Instance(){
	// Only allow one instance of class to be generated.
	if (!m_pInstance){   
		m_pInstance = new AnimationHelper;
	}
	return m_pInstance;
}

Sprite AnimationHelper::getAnimation(animationFrame frame, int x_draw, int y_draw){
	switch(frame){
		case animationFrame::SOLDIER_STAND_RIGHT:
			return SpriteHelper::Instance()->getSprite(x_draw, y_draw, 0, 0);
		case animationFrame::SOLDIER_WALK_RIGHT:
			return SpriteHelper::Instance()->getSprite(x_draw, y_draw, 0, 1);
		default:
			break;
	}
}