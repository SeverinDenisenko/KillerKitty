//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_PARTICLES_H
#define KILLERKITTY_PARTICLES_H

#include "engine/Entity.h"

namespace kke {

    class Particles : public Entity{
    public:
        Particles(int count);

    protected:

        void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

        void updateCurrent(sf::Time dt) override;

    private:
        struct Particle {
            sf::Vector2f velocity;
            sf::Time lifetime;
        };

        std::vector<Particle> particles;
        sf::VertexArray vertices;
        sf::Time lifetime;
    };

} // kke

#endif //KILLERKITTY_PARTICLES_H
