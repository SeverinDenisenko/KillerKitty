//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_EVENTSYSTEM_H
#define KILLERKITTY_EVENTSYSTEM_H

#include <vector>
#include <SFML/Window.hpp>

namespace kke {

    class EventSystem {
    public:
        explicit EventSystem(sf::Window& window);

        void Collect();
        bool IsKeyPressed(sf::Keyboard::Key key);
        bool IsKeyReleased(sf::Keyboard::Key key);
        bool IsKeyDown(sf::Keyboard::Key key);
        void Clear();

        std::vector<sf::Event> events;

    private:
        sf::Window& window;
    };
} // kke

#endif //KILLERKITTY_EVENTSYSTEM_H
