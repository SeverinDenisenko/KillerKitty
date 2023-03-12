//
// Created by Severin on 12.03.2023.
//

#include "TestScene.h"
#include "MainMenu.h"

void TestScene::Construct() {
    camera.setSize(15 * 16, 12 * 16);

    physicsEngine.timeMultiplier = 8;

    musicPlayer.Load("music", "src/assets/music.mp3");
    musicPlayer.Play("music");

    auto floor = std::make_unique<kke::RigidBody>(physicsEngine, false);
    floor->setPosition(0, 11 * 16);
    floor->setSize(6 * 16, 16);
    floor->setCategory("Floor");
    floor->checkForCollisions = true;
    sceneRoot.AttachChild(std::move(floor));

    auto floor2 = std::make_unique<kke::RigidBody>(physicsEngine, false);
    floor2->setPosition(0, 12 * 16);
    floor2->setSize(15 * 16, 16);
    floor2->setCategory("Floor");
    floor2->checkForCollisions = true;
    sceneRoot.AttachChild(std::move(floor2));

    auto floor3 = std::make_unique<kke::RigidBody>(physicsEngine, false);
    floor3->setPosition(16 * 16, 11 * 16);
    floor3->setSize(6 * 16, 16);
    floor3->setCategory("Floor");
    floor3->checkForCollisions = true;
    sceneRoot.AttachChild(std::move(floor3));

    auto floor4 = std::make_unique<kke::RigidBody>(physicsEngine, false);
    floor4->setPosition(17 * 16, 10 * 16);
    floor4->setSize(6 * 16, 16);
    floor4->setCategory("Floor");
    floor4->checkForCollisions = true;
    sceneRoot.AttachChild(std::move(floor4));

    auto wall1 = std::make_unique<kke::RigidBody>(physicsEngine, false);
    wall1->setPosition(-16, 0);
    wall1->setSize(0, 12 * 16);
    sceneRoot.AttachChild(std::move(wall1));

    auto wall2 = std::make_unique<kke::RigidBody>(physicsEngine, false);
    wall2->setPosition(15 * 16, 0);
    wall2->setSize(0, 12 * 16);
    sceneRoot.AttachChild(std::move(wall2));

    // Load textures and setup world
    textureHolder.Load("tiles", "src/assets/tiles.png");

    sceneRoot.AttachChild(std::make_unique<kke::TileMap>(textureHolder.get("tiles"), "src/assets/tilemap.tmj"));

    auto character = std::make_unique<Character>(physicsEngine, textureHolder.get("tiles"), sf::IntRect(64, 32, 16, 16));

    character->setCategory("Player");
    character->setPosition(1.0f, 1.0f);
    character->setSize(16.0f, 16.0f);

    sceneRoot.AttachChild(std::move(character));
}

void TestScene::ProcessInputs() {
    if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
        Running = false;
        game.AddScene(std::make_unique<MainMenu>(game));
    }

    float up = 0;
    float right = 0;
    float left = 0;
    bool send = false;

    kke::Command<std::string> move;
    move.category = "Player";

    if (eventSystem.IsKeyDown(sf::Keyboard::D)) {
        right = 1;
        send = true;
    }
    if (eventSystem.IsKeyDown(sf::Keyboard::A)) {
        left = -1;
        send = true;
    }
    if (eventSystem.IsKeyPressed(sf::Keyboard::Space)) {
        up = 1;
        send = true;
    }

    move.action = CharacterMover(right + left, -200 * up);

    if (send)
        commandQueue.push(std::move(move));
}

void TestScene::Update() {
    physicsEngine.Update(deltaTime);
}
