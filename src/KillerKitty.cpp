//
// Created by Severin on 06.03.2023.
//

#include "KillerKitty.h"

#include <Sprite.h>
#include <TileMap.h>

void KillerKitty::Setup() {
    kke::Game::Setup();

    sf::View view = window.getDefaultView();
    window.setView(view);

    textures.Load("tiles", "src/assets/tiles.png");

    const int level[] =
            {
             0,  1, 2, 2, 2, 1,  1,  2,  3,
             8,  9, 9, 9, 9, 9,  9,  10, 11,
            16, 17,18,18,18,17, 17, 18, 19,
            16, 17,17,17,17,18, 17, 18, 19,
             8,  9, 9, 9, 9, 9,  9,  10, 11,
             16, 18,17,17,17,17, 18, 18, 19,
            24, 26,25,25,25,25, 25, 26, 27,
            };

    auto character = std::make_unique<kke::Sprite>(textures.get("tiles"), sf::IntRect(64, 32, 16, 16));
    character->setCategory("Player");

    root.AttachChild(std::make_unique<kke::TileMap>(textures.get("tiles"), 16, 16, level, 9, 7));
    root.AttachChild(std::move(character));
    root.setScale(4, 4);
}

void KillerKitty::ProcessInputs() {
    kke::Game::ProcessInputs();

    if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
        Running = false;
    }

    kke::Command<std::string> move;
    move.action = CharacterMover(0, 0);

    if (eventSystem.IsKeyDown(sf::Keyboard::D)) {
        move.category = "Player";
        move.action = CharacterMover(1, 0);
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::A)) {
        move.category = "Player";
        move.action = CharacterMover(-1, 0);
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::W)) {
        move.category = "Player";
        move.action = CharacterMover(0, -1);
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::S)) {
        move.category = "Player";
        move.action = CharacterMover(0, 1);
    }

    commandQueue.push(move);
}
