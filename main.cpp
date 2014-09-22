// main.cpp
// Defines the entry point of the application

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>  // for use of Color class
#include <SFML/Graphics/Image.hpp> 
#include <iostream>             // For the cout
#include <unistd.h>

#include "animationhelper.h"
#include "rtscursor.h"
#include "rtssoldier.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "Pixel Battle");
    window. setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    AnimationHelper::Instance()->setSheet("sprites/sheet.png");

    RTSCursor cursor(&window);

    RectangleShape bg;
    bg.setSize(sf::Vector2f(1920, 1080));
    bg.setFillColor(Color(100,181,59));

    RTSSoldier one(&window);
    one.setTeamColor(AnimationHelper::spriteColor::Red);
    one.setPosition(20,20);
    one.setTarget(200,20);

    unsigned long frameCount = 0;

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

        cursor.draw();

        window.display();

        frameCount++;
    }

    return 0;
}