//
// Created by Severin on 12.03.2023.
//

#include "engine/UI/Label.h"

namespace kke {
    bool Label::isSelectable() const {
        return false;
    }

    Label::Label(const std::string& text, const sf::Font& font) : text(text, font, 16)
    {
    }

    void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(text, states);
    }

    void Label::setText(const std::string& t) {
        text.setString(t);
    }

    void Label::handleEvent(const sf::Event& event) {

    }
} // kke