//
// Created by Severin on 06.03.2023.
//

#include "Game.h"

namespace kke {
    Game::Game(const std::string& name) : window(sf::VideoMode::getFullscreenModes()[0],
                                                 name, sf::Style::Fullscreen), eventSystem(window) {

    }

    void Game::Run() {
        Setup();

        while (Running && window.isOpen()){
            eventSystem.Collect();
            ProcessInputs();
            eventSystem.Clear();
            Update();
            window.clear();
            Render();
            window.display();
        }

        Shutdown();
    }

    void Game::Render() {
        window.draw(root);
    }

    void Game::Update() {
        deltaTime = clock.restart();

        while (!commandQueue.isEmpty())
            root.onCommand(commandQueue.pop(), deltaTime);

        root.update(deltaTime);
    }

    void Game::ProcessInputs() {

    }
} // kke