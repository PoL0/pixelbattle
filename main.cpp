#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");

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
        window.display();
    }

    return 0;
}