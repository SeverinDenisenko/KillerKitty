//
// Created by Severin on 09.03.2023.
//

#ifndef KILLERKITTY_CHARACTER_H
#define KILLERKITTY_CHARACTER_H

#include <RigidBody.h>
#include <Sprite.h>

class Character : public kke::RigidBody, public kke::Sprite{
public:
    bool collided = false;

    Character(kke::PhysicsEngine& engine, const sf::Texture& texture) : kke::RigidBody(engine, true), kke::Sprite(texture) {
        checkForCollisions = true;
    }
    Character(kke::PhysicsEngine& engine, const sf::Texture& texture, sf::IntRect rect) : kke::RigidBody(engine, true), kke::Sprite(texture, rect) {
        checkForCollisions = true;
    }

    void updateCurrent(sf::Time dt) override{
        kke::RigidBody::updateCurrent(dt);
    }

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override{
        kke::Sprite::drawCurrent(target, states);
    }

    void onCollision(RigidBody *other) override{
        if (other->getCategory() == "Floor")
            collided = true;
    }
};


#endif //KILLERKITTY_CHARACTER_H
