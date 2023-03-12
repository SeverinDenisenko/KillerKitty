//
// Created by Severin on 12.03.2023.
//

#ifndef KILLERKITTY_UICONTAINER_H
#define KILLERKITTY_UICONTAINER_H

#include "UIComponent.h"

namespace kke {

    class UIContainer : public UIComponent{
    public:
        UIContainer();

        bool isSelectable() const override;
        void handleEvent(const sf::Event &event) override;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void addUIComponent(const std::shared_ptr<UIComponent>& component);
    private:
        std::vector<std::shared_ptr<UIComponent>> children;
        int selectedChild = -1;

        void select(int index);
        void selectNext();
        void selectPrevious();
        bool hasSelection();
    };

} // kke

#endif //KILLERKITTY_UICONTAINER_H
