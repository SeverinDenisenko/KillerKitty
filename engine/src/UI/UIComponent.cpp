//
// Created by Severin on 12.03.2023.
//

#include "engine/UI/UIComponent.h"

namespace kke {
    void UIComponent::deactivate() {
        active = false;
    }

    void UIComponent::activate() {
        active = true;
    }

    bool UIComponent::isActive() const {
        return active;
    }

    void UIComponent::select() {
        selected = true;
    }

    void UIComponent::deselect() {
        selected = false;
    }

    bool UIComponent::isSelected() const {
        return selected;
    }

    void UIComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    }

    UIComponent::~UIComponent() = default;

    UIComponent::UIComponent() = default;
} // kke