//
// Created by Severin on 06.03.2023.
//

#include "Sprite.h"

namespace kke {
    Sprite::Sprite(const sf::Texture &texture) : sprite(texture) {
        sf::FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(sf::Vector2(bounds.width / 2.f, bounds.height / 2.f));
    }

    void Sprite::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(sprite, states);
    }

    Sprite::Sprite(const sf::Texture &texture, const sf::IntRect &rect) : sprite(texture, rect)  {

    }
} // kke