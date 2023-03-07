//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_CHARACTERMOVER_H
#define KILLERKITTY_CHARACTERMOVER_H

#include <Command.h>

class CharacterMover {
public:
    CharacterMover(float vx, float vy)
            : vx(vx), vy(vy)
    {
    }

    void operator() (kke::Entity& node, sf::Time dt) const
    {
        float distance = 0.00004f * (float)dt.asMicroseconds();
        node.move(distance * vx, distance * vy);
    }

    float vx;
    float vy;
};


#endif //KILLERKITTY_CHARACTERMOVER_H
