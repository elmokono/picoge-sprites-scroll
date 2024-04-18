#include <Arduino.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "player.h"
#include "player_sprites.h"

point playerAccel = {0.0, 0.0};
unsigned short playerAnimation = 0;
unsigned long playerAnimationTimer = millis();

const rect test_collisions[1] = {{{0, 112}, {128, 16}}};

void Player::update()
{
    playerAccel.x *= 0.9; // slowdown
    playerPos.x += playerAccel.x;
    if (abs(playerAccel.x) < 0.01)
    {
        playerAccel.x = 0;
    }

    playerAccel.y += 0.15; // gravity acceleration
    playerPos.y += playerAccel.y;

    // collisions
    for (size_t i = 0; i < ARRAY_SIZE(test_collisions); i++)
    {
        if (playerPos.y > test_collisions[i].p1.y - 1)
        {
            playerPos.y = test_collisions[i].p1.y - 1;
            playerState = PLAYER_IDLE;
            break;
        }
    }

    if (millis() - playerAnimationTimer > 100)
    {
        playerAnimationTimer = millis();
        switch (playerState)
        {
        case PLAYER_IDLE:
            playerAnimation++;
            if (playerAnimation == 5)
                playerAnimation = 0;
            currentSprite = idle[playerAnimation];
            break;
        default:
            break;
        }
    }
}

void Player::move(bool moveRight)
{
    switch (playerState)
    {
    case PLAYER_IDLE:
        playerAnimation = 0;
        playerState = PLAYER_WALKING;
        playerAccel.x = moveRight ? 0.75 : -0.75;
        break;
    case PLAYER_WALKING:
    case PLAYER_JUMPING:
        playerAccel.x = moveRight ? 0.75 : -0.75;
        break;
    default:
        break;
    }
}

void Player::jump(void)
{
    if (playerState == PLAYER_JUMPING) return;
    playerAccel.y = -3.0;
    playerState = PLAYER_JUMPING;
}