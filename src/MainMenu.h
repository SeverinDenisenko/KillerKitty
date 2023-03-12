//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MAINMENU_H
#define KILLERKITTY_MAINMENU_H

#include "engine/Scene.h"
#include "engine/UI/Button.h"

#include "TestScene.h"

class MainMenu : public kke::Scene{
public:
    explicit MainMenu(kke::Game& game) : kke::Scene(game){}

    void Construct() override{
        camera.setSize(200, 100);

        textureHolder.Load("normal", "src/assets/button_1.png");
        textureHolder.Load("selected", "src/assets/button_2.png");
        textureHolder.Load("pressed", "src/assets/button_3.png");

        auto a = std::make_shared<kke::Button>(textureHolder.get("normal"),
                                               textureHolder.get("selected"),
                                               textureHolder.get("pressed"));
        a->setPosition(0, 0);
        a->setCallback([this](){
            game.AddScene(std::make_unique<TestScene>(game));
            Running = false;
        });
        uiRoot.addUIComponent(a);
        auto b = std::make_shared<kke::Button>(textureHolder.get("normal"),
                                               textureHolder.get("selected"),
                                               textureHolder.get("pressed"));
        b->setPosition(0, 16);
        b->setCallback([this](){
            Running = false;
        });
        uiRoot.addUIComponent(b);
        auto c = std::make_shared<kke::Button>(textureHolder.get("normal"),
                                               textureHolder.get("selected"),
                                               textureHolder.get("pressed"));
        c->setPosition(0, 32);
        c->setCallback([this](){
            game.AddScene(std::make_unique<TestScene>(game));
            Running = false;
        });
        uiRoot.addUIComponent(c);
    }

    void ProcessInputs() override{
    }
};


#endif //KILLERKITTY_MAINMENU_H
