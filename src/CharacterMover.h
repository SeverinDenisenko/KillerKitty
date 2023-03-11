//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_CHARACTERMOVER_H
#define KILLERKITTY_CHARACTERMOVER_H

#include "engine/Command.h"

#include "Character.h"

class CharacterMover {
public:
    CharacterMover(float vx, float vy)
            : vx(vx), vy(vy)
    {
    }

    void operator() (kke::Entity& node, sf::Time dt) const
    {
        auto character = dynamic_cast<Character*>(&node);

        float multiplier = dt.asMicroseconds() / 10000.f;

        character->move(multiplier * vx, 0);
        if (character->collided){
            character->addImpulse(0, vy * 100);
            character->collided = false;
        }
    }

    float vx;
    float vy;
};


#endif //KILLERKITTY_CHARACTERMOVER_H
