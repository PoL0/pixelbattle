#include <SFML/Graphics.hpp>
#include <iostream> // For the cout
#include <unistd.h>

#include "spritehelper.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "");

    SpriteHelper sh("sprites/sheet.png");

    bool phase = true;

    while (window.isOpen()){

        // Window-closing events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // frame cleanup
        // TODO - modify to draw when it needs to instead of always
        window.clear();

        if(phase){
            window.draw(sh.getSprite(0,0));
        } else {
            window.draw(sh.getSprite(1,0));
        }

        phase = !phase;

        window.display();

    }

    return 0;
}