#include <SFML/Graphics.hpp>
#include <iostream> 

#include "spritehelper.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "");

    SpriteHelper sh("sprites/sheet.png");

    //Sprite sprite;
    //sprite.setTexture(texture);

    //sprite.setPosition(Vector2f(60, 60));
    //sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));

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
        //window.draw(sprite);
        window.display();
    }

    return 0;
}