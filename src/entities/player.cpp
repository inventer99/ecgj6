#include "player.hpp"

#include <iostream>

static const float SPEED = 25;

void Player::onStart() {
    std::cout << "Player Start" << std::endl;
}

void Player::onStop() {
    std::cout << "Player Stop" << std::endl;
}

void Player::onUpdate() {
    if(IsKeyDown(KEY_W))
        position.y -= SPEED * GetFrameTime();
    if(IsKeyDown(KEY_S))
        position.y += SPEED * GetFrameTime();
    if(IsKeyDown(KEY_A))
        position.x -= SPEED * GetFrameTime();
    if(IsKeyDown(KEY_D))
        position.x += SPEED * GetFrameTime();
}

void Player::onDraw() {
    DrawRectangle(position.x, position.y, 20, 20, RED);
}
