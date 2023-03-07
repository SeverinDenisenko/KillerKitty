//
// Created by Severin on 07.03.2023.
//

#include "Scene.h"

namespace kke {
    void Scene::Run() {
        Construct();

        while (Running && window.isOpen()){
            // Inputs
            eventSystem.Collect();
            ProcessInputs();
            eventSystem.Clear();

            // Update
            deltaTime = clock.restart();

            while (!commandQueue.isEmpty())
                root.onCommand(commandQueue.pop(), deltaTime);

            root.update(deltaTime);

            // Render
            window.clear();
            window.draw(root);
            window.display();
        }

        Deconstruct();
    }

    Scene::Scene(sf::RenderWindow& window) : window(window), eventSystem(window), camera(window) {

    }
} // kke
