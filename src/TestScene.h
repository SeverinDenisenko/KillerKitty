//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_TESTSCENE_H
#define KILLERKITTY_TESTSCENE_H

#include <Scene.h>
#include <TileMap.h>
#include <Sprite.h>

#include "CharacterMover.h"

class TestScene : public kke::Scene {
public:
    explicit TestScene(sf::RenderWindow& renderWindow) : kke::Scene(renderWindow) {}

    void Construct() override{
        camera.setSize(15 * 16, 12 * 16);

        textureHolder.Load("tiles", "src/assets/tiles.png");

        auto character = std::make_unique<kke::Sprite>(textureHolder.get("tiles"), sf::IntRect(64, 32, 16, 16));
        character->setCategory("Player");

        root.AttachChild(std::make_unique<kke::TileMap>(textureHolder.get("tiles"), "src/assets/tilemap.tmj"));
        root.AttachChild(std::move(character));
    }

    void ProcessInputs() override{
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

    void Deconstruct() override{

    }
};


#endif //KILLERKITTY_TESTSCENE_H
