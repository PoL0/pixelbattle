#include <SFML/Graphics.hpp>
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
    one.setX(20);
    one.setY(20);
    one.moveto(200,40);

    RTSMovable two(&window);
    two.setX(20);
    two.setY(40);
    two.moveto(200,60);

    RTSMovable three(&window);
    three.setX(20);
    three.setY(60);
    three.moveto(200,80);

    RectangleShape bg;

    bg.setSize(sf::Vector2f(1920, 1080));
    bg.setFillColor(Color(100,181,59));

    int frameCount = 0;

    // Game loop n shit
    while (window.isOpen()){

        // Window-closing events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.draw(bg);

        one.draw(frameCount);
        two.draw(frameCount);
        if(frameCount > 46){
            three.draw(frameCount);
        }

        cursor.draw();

        window.display();

        frameCount++;

    }

    return 0;
}