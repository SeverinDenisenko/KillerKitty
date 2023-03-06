//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_CHARACTER_H
#define KILLERKITTY_CHARACTER_H

#include <Entity.h>
#include <Sprite.h>

#include <iostream>

class Character : public kke::Entity{
public:
    Character() = default;

protected:
    void updateCurrent(sf::Time dt) override{

        float distance = 0.00004f * dt.asMicroseconds();

        sf::Transform transform = getTransform();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            transform.translate(distance, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            transform.translate(-distance, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            transform.translate(0, -distance);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            transform.translate(0, distance);
        }

        setPosition(transform * sf::Vector2f());
    }
};


#endif //KILLERKITTY_CHARACTER_H
