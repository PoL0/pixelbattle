#include <SFML/Graphics.hpp>
#include <iostream>             // For the cout
#include <unistd.h>

#include "animationhelper.h"

#define an AnimationHelper::animationFrame

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "");
    window. setFramerateLimit(10);

    AnimationHelper::Instance()->setSheet("sprites/sheet.png");

    RectangleShape bg;

    bg.setSize(sf::Vector2f(1024, 768));
    bg.setFillColor(Color(255,255,255));

    bool phase = true;
    int step = 0;

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

        if(phase){
            window.draw(* AnimationHelper::Instance()->getAnimation(an::SOLDIER_STAND_RIGHT, 20+step, 20));
        } else {
            window.draw(* AnimationHelper::Instance()->getAnimation(an::SOLDIER_WALK_RIGHT, 20+step, 20));
        }
      step+=3;

        phase = !phase;

        window.display();

    }

    return 0;
}