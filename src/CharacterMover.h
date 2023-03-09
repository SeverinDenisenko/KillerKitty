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
        float multiplier = dt.asMicroseconds() / 100000.f;
        rigidBody->move(multiplier * vx, 0);
        rigidBody->body->ApplyLinearImpulseToCenter(b2Vec2(0, vy * 100), true);
    }

    float vx;
    float vy;
};


#endif //KILLERKITTY_CHARACTERMOVER_H
