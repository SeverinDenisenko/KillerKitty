//
// Created by Severin on 06.03.2023.
//

#include "KillerKitty.h"

#include <Sprite.h>
#include <TileMap.h>

void KillerKitty::Setup() {
    kke::Game::Setup();

    textures.Load("character", "src/assets/character.png");
    textures.Load("tiles", "src/assets/tiles.png");

    const int level[] =
            {
                    0, 1, 2, 3,
                    8, 9, 10, 11,
                    16, 17, 18, 19,
                    24, 25, 26, 27,
            };

    root.AttachChild(std::make_unique<kke::TileMap>(textures.get("tiles"), 16, 16, level, 4, 4));
    root.AttachChild(std::make_unique<kke::Sprite>(textures.get("character"), sf::IntRect(0, 0, 16, 16)));
    root.setScale(3, 3);
}
