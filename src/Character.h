//
// Created by Severin on 09.03.2023.
//

#ifndef KILLERKITTY_CHARACTER_H
#define KILLERKITTY_CHARACTER_H

#include <RigidBody.h>
#include <Sprite.h>

class Character : public kke::RigidBody, public kke::Sprite{
public:
    Character(kke::PhysicsEngine& engine, const sf::Texture& texture) : kke::RigidBody(engine, true), kke::Sprite(texture) {}
    Character(kke::PhysicsEngine& engine, const sf::Texture& texture, sf::IntRect rect) : kke::RigidBody(engine, true), kke::Sprite(texture, rect) {}

    void updateCurrent(sf::Time dt) override{
        kke::RigidBody::updateCurrent(dt);
    }

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override{
        kke::Sprite::drawCurrent(target, states);
    }
};


#endif //KILLERKITTY_CHARACTER_H
