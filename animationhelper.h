// animation.h
// Trevor

#pragma once

#include <SFML/Graphics.hpp>    // for use of Texture and Sprite

using namespace sf;

class AnimationHelper {
public:
	enum class animationFrame {
		BLU_SOL_STD_RIT, /* Blue soldier, stand right */
		BLU_SOL_WAK_RIT, /* Blue soldier, walk right */
		BLU_SOL_JAB_RIT, /* Blue soldier, jab right */
		BLU_SOL_SLH_RIT, /* Blue soldier, slash right, frame 1 */
		BLU_SOL_SL2_RIT, /* Blue soldier, slash right, frame 2 */
		BLU_SOL_SHT_RIT, /* Blue soldier, shoot right */
		BLU_SOL_FLE_RIT, /* Blue soldier, flee right, frame 1 */
		BLU_SOL_FL2_RIT, /* Blue soldier, flee right, frame 2 */
		BLU_HED_NEO_RIT, /* Blue Headdress, facing right, neolithic era */
		BLU_HE2_NEO_RIT, /* Blue Headdress, fleeing, facing right, neolithic era */
		BLU_HEL_NEO_RIT, /* Blue Helmet, Facing right, neolithic era */

		TIL_GRD_GRS_FLW  /* Tile, ground, made of grass, has flowers */ 
	};
	static AnimationHelper* Instance();
	void setSheet(std::string filepath);
	Sprite* getAnimation(animationFrame frame, int x_draw, int y_draw);
 private:
 	AnimationHelper(){};
 	static AnimationHelper* m_pInstance;

 	Sprite* getSprite(int x_draw, int y_draw, int column, int row);

 	Texture mainTexture;
	Sprite  mainSpriteSheet;
};