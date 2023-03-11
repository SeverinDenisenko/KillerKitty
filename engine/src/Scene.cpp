//
// Created by Severin on 07.03.2023.
//

#include "engine/Scene.h"

namespace kke {
    void Scene::Run() {
        Construct();

        while (Running && window.isOpen()){
            // Inputs
            eventSystem.Collect();
            ProcessInputs();
            ui.ProcessEvents(eventSystem);
            eventSystem.Clear();

            // Update
            deltaTime = clock.restart();

            Update();

            while (!commandQueue.isEmpty())
                root.onCommand(commandQueue.pop(), deltaTime);

            root.update(deltaTime);

            // Render
            window.clear();
            window.draw(root);
            ui.Render();
            window.display();
        }

        Deconstruct();
    }

    Scene::Scene(sf::RenderWindow& window) : window(window), eventSystem(window), camera(window), ui(window) {

    }
} // kke
