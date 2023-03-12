//
// Created by Severin on 12.03.2023.
//

#include "engine/UI/UIContainer.h"

namespace kke {
    UIContainer::UIContainer() = default;

    bool UIContainer::isSelectable() const {
        return false;
    }

    void UIContainer::handleEvent(const sf::Event& event) {
        if(hasSelection() && children[selectedChild]->isActive()) {
            children[selectedChild]->handleEvent(event);
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                selectPrevious();
            else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                selectNext();
            else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
                if (hasSelection())
                    children[selectedChild]->activate();
        }
    }

    void UIContainer::select(int index){
        if (children[index]->isSelectable())
        {
            if (hasSelection())
                children[selectedChild]->deselect();
            children[index]->select();
            selectedChild = index;
        }
    }

    void UIContainer::selectNext(){
        if (!hasSelection())
            return;
        int next = selectedChild;
        do
            next = (next + 1) % children.size();
        while (!children[next]->isSelectable());
        select(next);
    }

    void UIContainer::selectPrevious(){
        if (!hasSelection())
            return;
        int prev = selectedChild;
        do
            prev = (prev + children.size() - 1) % children.size();
        while (!children[prev]->isSelectable());
        select(prev);
    }

    bool UIContainer::hasSelection(){
        return selectedChild != -1;
    }

    void UIContainer::addUIComponent(const std::shared_ptr<UIComponent>& component) {
        children.push_back(component);

        if (!hasSelection() && component->isSelectable())
            select(children.size() - 1);
    }

    void UIContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        UIComponent::draw(target, states);

        for (const auto& i: children) {
            i->draw(target, states);
        }
    }

} // kke