//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_TESTSCENE_H
#define KILLERKITTY_TESTSCENE_H

#include "engine/Scene.h"
#include "engine/Entities/TileMap.h"
#include "engine/Entities/Sprite.h"
#include "engine/PhysicsEngine.h"
#include "engine/Entities/RigidBody.h"

#include "CharacterMover.h"
#include "Character.h"

class TestScene : public kke::Scene {
public:
    explicit TestScene(kke::Game& game) : kke::Scene(game){}

    kke::PhysicsEngine physicsEngine;

    void Construct() override;

    void ProcessInputs() override;

    void Update() override;

private:
    void AddWall(float x, float y, float w, float h);

    void AddFloor(float x, float y, float w, float h);
};


#endif //KILLERKITTY_TESTSCENE_H
