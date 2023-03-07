//
// Created by Severin on 06.03.2023.
//

#include "KillerKitty.h"

#include <Sprite.h>
#include <TileMap.h>

void KillerKitty::Setup() {
    kke::Game::Setup();

    sf::View defaultView = window.getView();
    int width = 15 * 16;
    int height = 12 * 16;
    float ratio = (float)width / (float)height;
    float currentWidth = defaultView.getSize().x;
    float currentHeight = defaultView.getSize().y;
    float currentRatio = currentWidth / currentHeight;
    sf::View view = sf::View(sf::FloatRect(0, 0, width, height));
    if (currentRatio > ratio){
        float offset = (1.f - (currentHeight * ratio) / currentWidth) / 2;
        view.setViewport(sf::FloatRect(offset, 0, 1 - offset * 2, 1));
    } else {
        float offset = (1.f - currentWidth / (ratio * currentHeight)) / 2;
        view.setViewport(sf::FloatRect(0, offset, 1, 1 - offset * 2));
    }
    window.setView(view);

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
