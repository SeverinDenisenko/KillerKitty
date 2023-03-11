//
// Created by Severin on 10.03.2023.
//

#include "engine/UI.h"

namespace kke {
    void UI::ProcessEvents(EventSystem& eventSystem) {
        for (auto& i : eventSystem.events)
            gui.handleEvent(i);
    }

    void UI::Render() {
        gui.draw();
    }

    UI::UI(sf::RenderWindow& window) : gui(window) {

    }
} // kke