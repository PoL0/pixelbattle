// soldier.h
// Trevor

#include <SFML/Graphics.hpp> // For the window

using namespace sf;

class Soldier{
public:
	Soldier(RenderWindow window);
	void act();
	void draw();
private:
	RenderWindow *mainWindow;
};