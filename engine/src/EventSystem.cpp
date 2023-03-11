//
// Created by Severin on 06.03.2023.
//

#include "engine/EventSystem.h"

namespace kke {
    void EventSystem::Collect() {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            events.push_back(event);
        }
}

    EventSystem::EventSystem(sf::Window& window) : window(window) {

    }

    void EventSystem::Clear() {
        events.clear();
    }

    bool EventSystem::IsKeyPressed(sf::Keyboard::Key key) {
        auto found = std::find_if(
                events.begin(),
                events.end(),
                [&] (sf::Event& e) -> bool { return e.type == sf::Event::KeyPressed && e.key.code == key; }
        );

        if (found != events.end()){
            events.erase(found);
            return true;
        }

        return false;
    }

    bool EventSystem::IsKeyReleased(sf::Keyboard::Key key) {
        auto found = std::find_if(
                events.begin(),
                events.end(),
                [&] (sf::Event& e) -> bool { return e.type == sf::Event::KeyReleased && e.key.code == key; }
        );

        if (found != events.end()){
            events.erase(found);
            return true;
        }

        return false;
    }

    bool EventSystem::IsKeyDown(sf::Keyboard::Key key) {
        return sf::Keyboard::isKeyPressed(key);
    }
} // kke
