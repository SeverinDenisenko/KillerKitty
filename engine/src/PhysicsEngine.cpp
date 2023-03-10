//
// Created by Severin on 08.03.2023.
//

#include "PhysicsEngine.h"

namespace kke {
    PhysicsEngine::PhysicsEngine(): world(b2Vec2(0.0f, 10.0f)) {

    }

    void PhysicsEngine::Update(sf::Time deltaTime) {
        world.Step((float)deltaTime.asMicroseconds() / 1000000.f * timeMultiplier, velocityIterations, positionIterations);

        for (auto i: bodies) {
            for (auto j: bodies) {
                if(i == j)
                    continue;

                bool collided = b2TestOverlap(i->shape, 0, j->shape, 0, i->body->GetTransform(), j->body->GetTransform());

                if (collided){
                    i->onCollision(j);
                }
            }
        }
    }

    void PhysicsEngine::RegisterBody(RigidBody& rigidBody) {
        rigidBody.body = world.CreateBody(&rigidBody.bodyDef);
        bodies.emplace_back(&rigidBody);
    }
} // kke