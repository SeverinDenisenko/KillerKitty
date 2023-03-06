//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_SPRITE_H
#define KILLERKITTY_SPRITE_H

#include "Entity.h"

namespace kke {

    class Sprite : public Entity{
    public:
        explicit Sprite(const sf::Texture& texture);
        Sprite(const sf::Texture& texture, const sf::IntRect& rect);

    private:
        void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::Sprite sprite;
    };

} // kke

#endif //KILLERKITTY_SPRITE_H
