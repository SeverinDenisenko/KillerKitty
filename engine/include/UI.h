//
// Created by Severin on 10.03.2023.
//

#ifndef KILLERKITTY_UI_H
#define KILLERKITTY_UI_H

#include "EventSystem.h"
#include "Button.h"

#include <TGUI/Backend/SFML-Graphics.hpp>

namespace kke {

    class UI {
    public:
        explicit UI(sf::RenderWindow& window);

        void ProcessEvents(EventSystem& eventSystem);
        void Render();

        void Register(auto& element) {
            gui.add(element.element);
        }

    private:
        tgui::Gui gui;
    };

} // kke

#endif //KILLERKITTY_UI_H
