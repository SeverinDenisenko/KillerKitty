//
// Created by Severin on 10.03.2023.
//

#include "Button.h"

namespace kke {
    Button::Button(float x, float y, float w, float h, UI& ui) {
        element = tgui::Button::create();
        element->setPosition(x, y);
        element->setSize(w, h);
        element->getRenderer()->setBackgroundColor(sf::Color(255, 255, 255, 255));

        ui.Register(*this);
    }
} // kke