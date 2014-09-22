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
#include "rtsunit.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "Pixel Battle");
    window. setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    AnimationHelper::Instance()->setSheet("sprites/sheet.png");

    RTSCursor cursor(&window);

    RectangleShape bg;
    bg.setSize(sf::Vector2f(1024, 768));
    bg.setFillColor(Color(100,181,59));

    // Soldier declarations
    RTSSoldier one(&window);
    one.setTeamColor(AnimationHelper::spriteColor::Blue);
    one.setPosition(20,20);
    one.setTarget(20,20);

    RTSSoldier two(&window);
    two.setTeamColor(AnimationHelper::spriteColor::Blue);
    two.setPosition(500,400);
    two.setTarget(500,400);

    RTSUnit unit;
    unit.addMovable(&one);
    unit.addMovable(&two);
    unit.setTargets(50,50);

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

        unit.drawMovables(frameCount);

        cursor.draw();

        window.display();

        frameCount++;
    }

    return 0;
}