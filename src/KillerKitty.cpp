//
// Created by Severin on 06.03.2023.
//

#include "KillerKitty.h"

#include <Sprite.h>
#include <TileMap.h>

#include "Character.h"

void KillerKitty::Setup() {
    kke::Game::Setup();

    sf::View view = window.getDefaultView();
    window.setView(view);

    textures.Load("tiles", "src/assets/tiles.png");

    const int level[] =
            {
             0,  1, 2, 2, 2, 1,  1,  2,  3,
             8,  9, 9, 9, 9, 9,  9,  10, 11,
            16, 17,18,18,18,17, 17, 18, 19,
            16, 17,17,17,17,18, 17, 18, 19,
             8,  9, 9, 9, 9, 9,  9,  10, 11,
             16, 18,17,17,17,17, 18, 18, 19,
            24, 26,25,25,25,25, 25, 26, 27,
            };

    auto character = std::make_unique<Character>();
    character->AttachChild(std::make_unique<kke::Sprite>(textures.get("tiles"), sf::IntRect(64, 32, 16, 16)));

    root.AttachChild(std::make_unique<kke::TileMap>(textures.get("tiles"), 16, 16, level, 9, 7));
    root.AttachChild(std::move(character));
    root.setScale(4, 4);
}
