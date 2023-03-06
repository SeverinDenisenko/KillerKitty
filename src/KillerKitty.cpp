//
// Created by Severin on 06.03.2023.
//

#include "KillerKitty.h"

#include <Sprite.h>

void KillerKitty::Setup() {
    kke::Game::Setup();

    textures.Load("character", "src/assets/character.png");

    root.AttachChild(std::make_unique<kke::Sprite>(textures.get("character")));
    root.setScale(10, 10);
    root.setPosition(80, 80);
}
