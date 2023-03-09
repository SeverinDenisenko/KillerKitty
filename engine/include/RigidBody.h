//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_RIGIDBODY_H
#define KILLERKITTY_RIGIDBODY_H

#include <Entity.h>
#include <PhysicsEngine.h>
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"

namespace kke {

    class RigidBody : public Entity{
    public:
        explicit RigidBody(PhysicsEngine& physicsEngine, bool dynamic);

        void updateCurrent(sf::Time dt) override;

        void setPosition(float x, float y);
        void setSize(float x, float y);
        void move(float x, float y);
        void addImpulse(float x, float y);

    private:
        b2PolygonShape dynamicBox;
        b2BodyDef bodyDef;
        b2Body* body;
        b2FixtureDef fixtureDef;
        b2Fixture* fixture;

        PhysicsEngine& physicsEngine;
    };

} // kke

#endif //KILLERKITTY_RIGIDBODY_H
