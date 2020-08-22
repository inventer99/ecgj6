#include "menustate.hpp"

#include <iostream>
#include <raygui.h>

#include "game.hpp"
#include "guiutils.hpp"

void MenuState::onEnter() {

}

void MenuState::onLeave() {

}

void MenuState::onUpdate() {

}

void MenuState::onDrawGui() {
    auto centerY = GetScreenHeight() / 2.f;

    if(GuiButton({ centeredX(100), centerY - 35, 100, 50 }, "Play")) {
        std::cout << "Hello" << std::endl;
    }

    if(GuiButton({ centeredX(100), centerY + 35, 100, 50 }, "Exit")) {
        GameStatics::game->stop();
    }
}
