//
// Created by Severin on 08.03.2023.
//

#include "PhysicsEngine.h"

namespace kke {
    PhysicsEngine::PhysicsEngine(): world(b2Vec2(0.0f, 10.0f)) {

    }

    void PhysicsEngine::Update(sf::Time deltaTime) {
        world.Step((float)deltaTime.asMicroseconds() / 1000000.f * timeMultiplier, velocityIterations, positionIterations);
    }

    void PhysicsEngine::RegisterBody(RigidBody& rigidBody) {
        rigidBody.body = world.CreateBody(&rigidBody.bodyDef);
    }
} // kke