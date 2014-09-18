#include <SFML/Graphics.hpp>
#include <iostream>             // For the cout
#include <unistd.h>

#include "animationhelper.h"
#include "rtsdrawable.h"
#include "rtsmovable.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "");
    window. setFramerateLimit(10);

    AnimationHelper::Instance()->setSheet("sprites/sheet.png");

    RTSMovable three(&window);
    three.setFrame(AnimationHelper::animationFrame::BLU_SOL_STD_RIT);
    three.setX(20);
    three.setY(20);

    RectangleShape bg;

    bg.setSize(sf::Vector2f(1024, 768));
    bg.setFillColor(Color(255,255,255));

    // Game loop n shit
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

        window.draw(bg);

        three.draw();

        window.display();

    }

    return 0;
}