//
// Created by Severin on 06.03.2023.
//

#include "engine/Game.h"

namespace kke {
    Game::Game(const std::string& name) : window(sf::VideoMode::getFullscreenModes()[0],
                                                 name, sf::Style::Fullscreen){

    }

    void Game::Run() {
        Setup();

        while (!sceneQueue.empty() && window.isOpen()){
            sceneQueue.front()->Run();
            sceneQueue.pop();
        }

        Shutdown();
    }
} // kke
