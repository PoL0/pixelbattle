#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>  // for use of Color class
#include <SFML/Graphics/Image.hpp>  // for use of Color class
#include <iostream>             // For the cout
#include <unistd.h>

#include "animationhelper.h"

#define typ  AnimationHelper::spriteType
#define civ  AnimationHelper::spriteCiv
#define desc AnimationHelper::spriteDesc
#define dir  AnimationHelper::spriteDir

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "Pixel Battle");
    window. setFramerateLimit(60);
    //window.setMouseCursorVisible(false);

    AnimationHelper::Instance()->setSheet("sprites/sheet.png");

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

        //window.draw(* AnimationHelper::Instance()->getAnimation(typ::Character, civ::Neolithic, desc::Stand, dir::Right, 0, 0));

        window.display();

        frameCount++;

    }

    return 0;
}