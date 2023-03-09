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

class TestScene : public kke::Scene {
public:
    explicit TestScene(sf::RenderWindow& renderWindow) : kke::Scene(renderWindow){}

    kke::PhysicsEngine physicsEngine;

    void Construct() override{
        camera.setSize(15 * 16, 12 * 16);

        // Music
        musicPlayer.Load("theme", "src/assets/music.mp3");
        musicPlayer.volume = 50.f;
        //musicPlayer.Play("theme");

        auto body = std::make_unique<kke::RigidBody>(physicsEngine, true);

        auto floor = std::make_unique<kke::RigidBody>(physicsEngine, false);
        floor->setPosition(0.0f, 150.0f);
        floor->setSize(50.0f, 10.0f);
        root.AttachChild(std::move(floor));

        // Load textures and setup world
        textureHolder.Load("tiles", "src/assets/tiles.png");

        auto character = std::make_unique<kke::Sprite>(textureHolder.get("tiles"), sf::IntRect(64, 32, 16, 16));
        body->setCategory("Player");

        root.AttachChild(std::make_unique<kke::TileMap>(textureHolder.get("tiles"), "src/assets/tilemap.tmj"));
        body->AttachChild(std::move(character));
        root.AttachChild(std::move(body));
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
        if (eventSystem.IsKeyPressed(sf::Keyboard::Space)) {
            move.action = CharacterMover(0, -1);
        }
        commandQueue.push(move);
    }

    void Update() override{
        physicsEngine.Update(deltaTime);
    }
};


#endif //KILLERKITTY_TESTSCENE_H
