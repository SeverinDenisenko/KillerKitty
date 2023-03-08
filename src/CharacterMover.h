//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_CHARACTERMOVER_H
#define KILLERKITTY_CHARACTERMOVER_H

#include <Command.h>

#include <RigidBody.h>

class CharacterMover {
public:
    CharacterMover(float vx, float vy)
            : vx(vx), vy(vy)
    {
    }

    void operator() (kke::Entity& node, sf::Time dt) const
    {
        auto rigidBody = dynamic_cast<kke::RigidBody*>(&node);
        float multiplier = 100;
        rigidBody->body->ApplyForceToCenter(b2Vec2(vx * multiplier, vy * multiplier), true);
        //node.move(distance * vx, distance * vy);
    }

    float vx;
    float vy;
};


#endif //KILLERKITTY_CHARACTERMOVER_H
