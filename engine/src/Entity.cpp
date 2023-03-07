//
// Created by Severin on 06.03.2023.
//

#include "Entity.h"

#include <utility>

namespace kke {
    void Entity::AttachChild(std::unique_ptr <Entity> child) {
        child->parent = this;
        children.push_back(std::move(child));
    }

    std::unique_ptr<Entity> Entity::DetachChild(const Entity &child) {
        auto found = std::find_if(
                children.begin(),
                children.end(),
                [&] (std::unique_ptr<Entity>& p) -> bool { return p.get() == &child; }
        );

        if (found == children.end())
            throw std::runtime_error("Is no child found!");

        std::unique_ptr<Entity> result = std::move(*found);
        result->parent = nullptr;
        children.erase(found);

        return result;
    }

    void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        drawCurrent(target, states);

        for (const auto & child : children)
            child->draw(target, states);
    }

    void Entity::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

    }

    void Entity::updateCurrent(sf::Time dt) {

    }

    void Entity::update(sf::Time dt) {
        updateCurrent(dt);

        for (const auto & child : children)
            child->update(dt);
    }

    sf::Transform Entity::getWorldTransform() const {
        sf::Transform transform = sf::Transform::Identity;

        for (const Entity* node = this; node != nullptr; node = node->parent)
            transform = node->getTransform() * transform;

        return transform;
    }

    sf::Vector2f Entity::getWorldPosition() const {
        return getWorldTransform() * sf::Vector2f();
    }

    std::string Entity::getCategory() {
        return category;
    }

    void Entity::onCommand(const Command<std::string>& command, sf::Time dt) {
        if (command.category == getCategory())
            command.action(*this, dt);

        for (const auto & child : children)
            child->onCommand(command, dt);
    }

    void Entity::setCategory(std::string c) {
        category = std::move(c);
    }
} // kke