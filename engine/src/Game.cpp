//
// Created by Severin on 06.03.2023.
//

#include "engine/Game.h"

namespace kke {
    Game::Game(const std::string& name) : window(sf::VideoMode::getFullscreenModes()[0],
                                                 name, sf::Style::Fullscreen){

    }

    void Game::Run() {
        if (Running)
            throw std::runtime_error("Game already running!");

        Running = true;

        Setup();

        while (!sceneQueue.empty() && window.isOpen() && Running){
            sceneQueue.front()->Run();
            sceneQueue.pop();
        }

        Shutdown();
    }

    sf::RenderWindow& Game::GetWindow() {
        return window;
    }

    void Game::AddScene(std::unique_ptr<Scene> scene) {
        sceneQueue.push(std::move(scene));
    }
} // kke
