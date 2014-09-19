// animation.h
// Trevor

#pragma once

#include <SFML/Graphics.hpp>    // for use of Texture and Sprite

using namespace sf;

class AnimationHelper {
public:
	// Enum of all animation mapping
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

		BLU_SOL_STD_LFT, /* Blue soldier, stand left */
		BLU_SOL_STD_DWN, /* Blue soldier, stand down */
		BLU_SOL_STD_UPP, /* Blue soldier, stand up */

		/* Testing sprites, only for abstract RTSMovable class */
		TST_ARW_STD_RIT, /* Test arrow, standing, right */
		TST_ARW_WK1_RIT, /* Test arrow, walking, frame 1, right */
		TST_ARW_WK2_RIT, /* Test arrow, walking, frame 2, right */

		TST_ARW_STD_LFT, /* Test arrow, standing, left */
		TST_ARW_WK1_LFT, /* Test arrow, walking, frame 1, left */
		TST_ARW_WK2_LFT, /* Test arrow, walking, frame 2, left */

		TST_ARW_STD_DWN, /* Test arrow, standing, down */
		TST_ARW_WK1_DWN, /* Test arrow, walking, frame 1, down */
		TST_ARW_WK2_DWN, /* Test arrow, walking, frame 2, down */

		TST_ARW_STD_UPP, /* Test arrow, standing, up */
		TST_ARW_WK1_UPP, /* Test arrow, walking, frame 1, up */
		TST_ARW_WK2_UPP, /* Test arrow, walking, frame 2, up */

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