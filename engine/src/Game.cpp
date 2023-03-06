//
// Created by Severin on 06.03.2023.
//

#include "Game.h"

namespace kke {
    Game::Game(const std::string& name) : window(sf::VideoMode::getFullscreenModes()[0],
                                                 name, sf::Style::Fullscreen) {

    }

    void Game::Run() {
        Setup();

        while (Running && window.isOpen()){
            ProcessInputs();
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

        root.update(deltaTime);
    }

    void Game::ProcessInputs() {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
} // kke