//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_PHYSICSENGINE_H
#define KILLERKITTY_PHYSICSENGINE_H

#include <box2d/b2_world.h>
#include "SFML/System.hpp"

namespace kke {

    class PhysicsEngine {
    public:
        PhysicsEngine();

        void Update(sf::Time deltaTime);

        int velocityIterations = 6;
        int positionIterations = 2;

        b2World world;
    };

} // kke

#endif //KILLERKITTY_PHYSICSENGINE_H
