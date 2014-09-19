#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>             // For the cout
#include <unistd.h>

#include "animationhelper.h"
#include "rtsdrawable.h"
#include "rtsmovable.h"
#include "cursor.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "Pixel Battle");
    window. setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    AnimationHelper::Instance()->setSheet("sprites/sheet.png");

    Cursor cursor(&window);

    RTSMovable one(&window);
    one.setX(0);
    one.setY(0);
    one.moveto(0,50);

    RTSMovable two(&window);
    two.setX(0);
    two.setY(0);
    two.moveto(50,0);

    RTSMovable three(&window);
    three.setX(0);
    three.setY(0);
    three.moveto(50,50);

    RectangleShape bg;

    bg.setSize(sf::Vector2f(1920, 1080));
    bg.setFillColor(Color(100,181,59));

    // Game loop n shit
    while (window.isOpen()){

        // Window-closing events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(bg);

        one.draw();
        two.draw();
        three.draw();

        cursor.setX(Mouse::getPosition(window).x);
        cursor.setY(Mouse::getPosition(window).y);
        cursor.draw();

        window.display();

    }

    return 0;
}