//
// Created by Severin on 12.03.2023.
//

#ifndef KILLERKITTY_LABEL_H
#define KILLERKITTY_LABEL_H

#include "UIComponent.h"

namespace kke {

    class Label : UIComponent{
    public:
        bool isSelectable() const override;

        Label(const std::string& text, const sf::Font& font);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void setText(const std::string& t);

        void handleEvent(const sf::Event &event) override;

    private:
        sf::Text text;
    };

} // kke

#endif //KILLERKITTY_LABEL_H
