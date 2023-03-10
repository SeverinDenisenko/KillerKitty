//
// Created by Severin on 08.03.2023.
//

#include "RigidBody.h"

namespace kke {
    RigidBody::RigidBody(PhysicsEngine& physicsEngine, bool dynamic) : physicsEngine(physicsEngine) {
        b2PolygonShape* polygonShape = new b2PolygonShape();
        polygonShape->SetAsBox(1.0f, 1.0f);
        shape = polygonShape;
        bodyDef.fixedRotation = true;

        if (dynamic)
            bodyDef.type = b2_dynamicBody;

        physicsEngine.RegisterBody(*this);

        fixtureDef.shape = shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixture = body->CreateFixture(&fixtureDef);
    }

    void RigidBody::updateCurrent(sf::Time dt) {
        b2Vec2 position = body->GetPosition();
        setPosition(position.x, position.y);
    }

    void RigidBody::setPosition(float x, float y) {
        Transformable::setPosition(x, y);

        auto p = body->GetPosition();
        auto a = body->GetAngle();

        body->SetTransform(b2Vec2(x, y), a);

        body->SetAwake(true);
    }

    void RigidBody::setSize(float x, float y) {
        body->DestroyFixture(fixture);
        dynamic_cast<b2PolygonShape*>(shape)->SetAsBox(x, y);
        fixtureDef.shape = shape;
        fixture = body->CreateFixture(&fixtureDef);
        body->SetAwake(true);
    }

    void RigidBody::move(float x, float y) {
        //Transformable::move(x, y);

        auto p = body->GetPosition();
        auto a = body->GetAngle();

        body->SetTransform(b2Vec2(p.x + x, p.y + y), a);
        body->SetAwake(true);
    }

    void RigidBody::addImpulse(float x, float y) {
        body->ApplyLinearImpulseToCenter(b2Vec2(x, y), true);
    }

    void RigidBody::onCollision(RigidBody* other) {

    }
} // kke