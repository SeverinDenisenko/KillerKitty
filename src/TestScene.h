//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_TESTSCENE_H
#define KILLERKITTY_TESTSCENE_H

#include <Scene.h>
#include <TileMap.h>
#include <Sprite.h>
#include <PhysicsEngine.h>
#include <RigidBody.h>

#include "CharacterMover.h"
#include "Character.h"

class TestScene : public kke::Scene {
public:
    explicit TestScene(sf::RenderWindow& renderWindow) : kke::Scene(renderWindow){}

    kke::PhysicsEngine physicsEngine;

    void Construct() override{
        camera.setSize(15 * 16, 12 * 16);

        physicsEngine.timeMultiplier = 8;

        auto floor = std::make_unique<kke::RigidBody>(physicsEngine, false);
        floor->setPosition(0, 12 * 16);
        floor->setSize(15 * 16 * 2, 0);
        floor->setCategory("Floor");
        floor->checkForCollisions = true;
        root.AttachChild(std::move(floor));

        auto wall1 = std::make_unique<kke::RigidBody>(physicsEngine, false);
        wall1->setPosition(-16, 0);
        wall1->setSize(0, 12 * 16);
        root.AttachChild(std::move(wall1));

        auto wall2 = std::make_unique<kke::RigidBody>(physicsEngine, false);
        wall2->setPosition(15 * 16, 0);
        wall2->setSize(0, 12 * 16);
        root.AttachChild(std::move(wall2));

        // Load textures and setup world
        textureHolder.Load("tiles", "src/assets/tiles.png");

        root.AttachChild(std::make_unique<kke::TileMap>(textureHolder.get("tiles"), "src/assets/tilemap.tmj"));

        auto character = std::make_unique<Character>(physicsEngine, textureHolder.get("tiles"), sf::IntRect(64, 32, 16, 16));

        character->setCategory("Player");
        character->setPosition(1.0f, 1.0f);
        character->setSize(16.0f, 16.0f);

        root.AttachChild(std::move(character));
    }

    void ProcessInputs() override{
        if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
            Running = false;
        }

        float up = 0;
        float right = 0;
        bool send = false;

        kke::Command<std::string> move;
        move.category = "Player";

        if (eventSystem.IsKeyDown(sf::Keyboard::D)) {
            right = 1;
            send = true;
        }
        if (eventSystem.IsKeyDown(sf::Keyboard::A)) {
            right = -1;
            send = true;
        }
        if (eventSystem.IsKeyPressed(sf::Keyboard::Space)) {
            up = 1;
            send = true;
        }

        move.action = CharacterMover(right, -200 * up);

        if (send)
            commandQueue.push(std::move(move));
    }

    void Update() override{
        physicsEngine.Update(deltaTime);
    }
};


#endif //KILLERKITTY_TESTSCENE_H
