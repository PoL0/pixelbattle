// animation.h
// Trevor
#include <SFML/Graphics.hpp>    // for use of Texture and Sprite

using namespace sf;

class AnimationHelper {
public:
	enum class animationFrame {
		SOLDIER_STAND_RIGHT,
		SOLDIER_WALK_RIGHT
	};
	static AnimationHelper* Instance();
	Sprite getAnimation(animationFrame frame, int x_draw, int y_draw);
 private:
 	AnimationHelper(){};
 	static AnimationHelper* m_pInstance;
};