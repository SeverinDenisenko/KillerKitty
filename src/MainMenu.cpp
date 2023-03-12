//
// Created by Severin on 12.03.2023.
//

#include "MainMenu.h"
#include "TestScene.h"

void MainMenu::Construct() {
    camera.setSize(200, 100);

    textureHolder.Load("play_normal", "src/assets/play_1.png");
    textureHolder.Load("play_selected", "src/assets/play_2.png");
    textureHolder.Load("play_pressed", "src/assets/play_3.png");
    textureHolder.Load("exit_normal", "src/assets/exit_1.png");
    textureHolder.Load("exit_selected", "src/assets/exit_2.png");
    textureHolder.Load("exit_pressed", "src/assets/exit_3.png");

    auto a = std::make_shared<kke::Button>(textureHolder.get("play_normal"),
                                           textureHolder.get("play_selected"),
                                           textureHolder.get("play_pressed"));
    a->setPosition(0, 0);
    a->setCallback([this](){
        game.AddScene(std::make_unique<TestScene>(game));
        Running = false;
    });
    uiRoot.addUIComponent(a);
    auto b = std::make_shared<kke::Button>(textureHolder.get("exit_normal"),
                                           textureHolder.get("exit_selected"),
                                           textureHolder.get("exit_pressed"));
    b->setPosition(0, 16);
    b->setCallback([this](){
        Running = false;
    });
    uiRoot.addUIComponent(b);
}

void MainMenu::ProcessInputs() {
}
