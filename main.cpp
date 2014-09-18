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

    bg.setSize(sf::Vector2f(1024, 1024));
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
            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_SOL_STD_RIT, 20+step%1024, 40));
            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_HED_NEO_RIT, 20+step%1024, 40));

            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_SOL_STD_RIT, 20+step%1024, 20));
            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_HEL_NEO_RIT, 20+step%1024, 20));
        } else {
            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_SOL_WAK_RIT, 20+step%1024, 40));
            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_HED_NEO_RIT, 20+step%1024, 41));

            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_SOL_WAK_RIT, 20+step%1024, 20));
            window.draw(* AnimationHelper::Instance()->getAnimation(an::BLU_HEL_NEO_RIT, 20+step%1024, 21));
        }
      step+=3;

        phase = !phase;

        window.display();

    }

    return 0;
}