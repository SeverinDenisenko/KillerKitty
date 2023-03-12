//
// Created by Severin on 12.03.2023.
//

#include <utility>

#include "engine/UI/Button.h"

namespace kke {
    Button::Button(sf::Texture& normal, sf::Texture& selected, sf::Texture& pressed) : normal(normal), selected(selected), pressed(pressed), sprite(normal) {

    }

    bool Button::isSelectable() const {
        return true;
    }

    void Button::select() {
        UIComponent::select();
        sprite.setTexture(selected);
    }

    void Button::deselect()
    {
        UIComponent::deselect();
        sprite.setTexture(normal);
    }

    void Button::activate() {
        UIComponent::activate();
        if (isToggle)
            sprite.setTexture(pressed);

        if (isCallback)
            callback();

        if (!isToggle)
            deactivate();
    }

    void Button::deactivate() {
        UIComponent::deactivate();
        if (isToggle)
        {
            if (isSelected())
                sprite.setTexture(selected);
            else
                sprite.setTexture(normal);
        }
    }

    void Button::setCallback(std::function<void(void)> c) {
        callback = std::move(c);
        isCallback = true;
        isToggle = false;
    }

    void Button::handleEvent(const sf::Event& event) {

    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        UIComponent::draw(target, states);
        states.transform *= getTransform();
        target.draw(sprite, states);
    }
} // kke