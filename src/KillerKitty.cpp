//
// Created by Severin on 06.03.2023.
//

#include "KillerKitty.h"

#include <Sprite.h>
#include <TileMap.h>

void KillerKitty::Setup() {
    kke::Game::Setup();

    camera.setSize(15 * 16, 12 * 16);

    textures.Load("tiles", "src/assets/tiles.png");

    auto character = std::make_unique<kke::Sprite>(textures.get("tiles"), sf::IntRect(64, 32, 16, 16));
    character->setCategory("Player");

    root.AttachChild(std::make_unique<kke::TileMap>(textures.get("tiles"), "src/assets/tilemap.tmj"));
    root.AttachChild(std::move(character));
}

void KillerKitty::ProcessInputs() {
    kke::Game::ProcessInputs();

    if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
        Running = false;
    }

    kke::Command<std::string> move;
    move.action = CharacterMover(0, 0);
    move.category = "Player";

    if (eventSystem.IsKeyDown(sf::Keyboard::D)) {
        move.action = CharacterMover(1, 0);
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::A)) {
        move.action = CharacterMover(-1, 0);
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::W)) {
        move.action = CharacterMover(0, -1);
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::S)) {
        move.action = CharacterMover(0, 1);
    }
    commandQueue.push(move);
}
