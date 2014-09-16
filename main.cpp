#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <stdio.h>

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "");
    
    sf::Texture texture;
    if (!texture.loadFromFile("sprites/GreenDarknut.png")){
        printf("Shit");
    }

    Sprite sprite;
    sprite.setTexture(texture);

    sprite.setPosition(Vector2f(60, 60));

    while (window.isOpen()){

        // Window-closing events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        texture.setSmooth(true);
        sprite.rotate(1);

        // frame cleanup
        // TODO - modify to draw when it needs to instead of always
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}