//
// Created by Severin on 12.03.2023.
//

#ifndef KILLERKITTY_BUTTON_H
#define KILLERKITTY_BUTTON_H

#include "UIComponent.h"

namespace kke {

    class Button : public UIComponent{
    public:
        Button(sf::Texture& normal, sf::Texture& selected, sf::Texture& pressed);

        bool isSelectable() const override;

        void select() override;
        void deselect() override;
        void activate() override;
        void deactivate() override;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void setCallback(std::function<void(void)> c);

        void handleEvent(const sf::Event &event) override;
    private:
        sf::Texture& normal;
        sf::Texture& selected;
        sf::Texture& pressed;

        std::function<void(void)> callback = [](){};

        sf::Sprite sprite;

        bool isToggle = true;
        bool isCallback = false;
    };

} // kke

#endif //KILLERKITTY_BUTTON_H
