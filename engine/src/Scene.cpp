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
            for (auto& i: eventSystem.events) {
                uiRoot.handleEvent(i);
            }
            eventSystem.Clear();

            // Update
            deltaTime = clock.restart();

            Update();

            while (!commandQueue.isEmpty())
                sceneRoot.onCommand(commandQueue.pop(), deltaTime);

            sceneRoot.update(deltaTime);

            // Render
            window.clear();
            window.draw(sceneRoot);
            window.draw(uiRoot);
            window.display();
        }

        Deconstruct();
    }

    Scene::Scene(Game& game) : game(game), window(game.GetWindow()), eventSystem(game.GetWindow()), camera(game.GetWindow()) {

    }
} // kke
