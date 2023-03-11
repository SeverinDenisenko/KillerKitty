//
// Created by Severin on 06.03.2023.
//

#include "engine/Entities/Particles.h"

#include <cmath>

namespace kke {
    void Particles::updateCurrent(sf::Time dt) {
        for (std::size_t i = 0; i < particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = particles[i];
            p.lifetime -= dt;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero){
                // give a random velocity and lifetime to the particle
                float angle = (std::rand() % 360) * 3.14f / 180.f;
                float speed = (std::rand() % 50) + 50.f;
                particles[i].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
                particles[i].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

                // reset the position of the corresponding vertex
                vertices[i].position = {0, 0};
            }

            // update the position of the corresponding vertex
            vertices[i].position += p.velocity * dt.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / dt.asSeconds();
            vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }

    void Particles::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = nullptr;
        target.draw(vertices, states);
    }

    Particles::Particles(int count) : particles(count), vertices(sf::Points, count), lifetime(sf::seconds(3.f)) {

    }
} // kke
