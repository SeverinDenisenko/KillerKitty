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

    AddWall(-1, 0, 0, 10);
    AddWall(15, 0, 0, 10);

    AddFloor(0, 11, 15, 0);
    AddFloor(0, 10, 5.95, 0);
    AddWall(6, 11, 0, 1);
    AddWall(10, 11, 0, 1);
    AddFloor(14, 10, 3.95, 0);
    AddWall(11, 10, 0, 1);
    AddFloor(15, 9, 3.95, 0);

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

void TestScene::AddWall(float x, float y, float w, float h) {
    auto wall = std::make_unique<kke::RigidBody>(physicsEngine, false);
    wall->setPosition(x * 16, y * 16);
    wall->setSize(w * 16, h * 16);
    sceneRoot.AttachChild(std::move(wall));
}

void TestScene::AddFloor(float x, float y, float w, float h) {
    auto wall = std::make_unique<kke::RigidBody>(physicsEngine, false);
    wall->setPosition(x * 16, y * 16);
    wall->setSize(w * 16, h * 16);
    wall->setCategory("Floor");
    wall->checkForCollisions = true;
    sceneRoot.AttachChild(std::move(wall));
}
