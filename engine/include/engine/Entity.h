//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_ENTITY_H
#define KILLERKITTY_ENTITY_H

#include <vector>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include "Command.h"

namespace kke {

    class Entity : public sf::Transformable, public sf::Drawable, private sf::NonCopyable{
    public:
        Entity() : parent(nullptr) {}

        void AttachChild(std::unique_ptr<Entity> child);
        std::unique_ptr<Entity> DetachChild(const Entity& child);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update(sf::Time dt);
        void onCommand(const Command<std::string>& command, sf::Time dt);

        sf::Transform getWorldTransform() const;
        sf::Vector2f getWorldPosition() const;

        std::string getCategory();
        void setCategory(std::string category);

    private:
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void updateCurrent(sf::Time dt);

    private:
        std::string category = "Scene";
        std::vector<std::unique_ptr<Entity>> children;
        Entity* parent;
    };

} // kke

#endif //KILLERKITTY_ENTITY_H
