//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MAINMENU_H
#define KILLERKITTY_MAINMENU_H

#include <Scene.h>
#include <Button.h>

class MainMenu : public kke::Scene{
public:
    explicit MainMenu(sf::RenderWindow& renderWindow) : kke::Scene(renderWindow){}

    void Construct() override{
        camera.setSize(15 * 16, 12 * 16);

        root.AttachChild(std::unique_ptr<kke::Button>(new kke::Button(0.f, 0.f, 100.f, 100.f, ui)));
    }

    void ProcessInputs() override{
        if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
            Running = false;
        }
    }
};


#endif //KILLERKITTY_MAINMENU_H
