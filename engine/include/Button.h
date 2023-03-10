//
// Created by Severin on 10.03.2023.
//

#ifndef KILLERKITTY_BUTTON_H
#define KILLERKITTY_BUTTON_H

#include "Entity.h"
#include "UI.h"

#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/EditBox.hpp"

namespace kke {

    class UI;

    class Button : public Entity{
    public:
        Button(float x, float y, float w, float h, UI& ui);

        friend class UI;
    private:

        tgui::Button::Ptr element;
    };

} // kke

#endif //KILLERKITTY_BUTTON_H
