#include <Arduino.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "player.h"
#include "player_sprites.h"
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

const char PLAYER_IDLE = 0;
const char PLAYER_WALKING = 1;
const char PLAYER_CROUCHING = 2;
const char PLAYER_HITTING = 3;
const char PLAYER_JUMPING = 4;

Player::Player()
{
    playerAccel = {0.0, 0.0};
    playerAnimation = 0;
    playerAnimationTimer = millis();
    playerWidth = 32;
    playerHeight = 32;

    playerState = PLAYER_IDLE;
    playerPos = {0, 0};
    playerFacingRight = true;
    currentSprite = idle[playerAnimation];
}

void Player::update(const rect *collisions, uint16_t collisions_length)
{
    playerAccel.x *= 0.9; // slowdown
    if (abs(playerAccel.x) < 0.01)
    {
        playerAccel.x = 0;
    }
    playerAccel.y += 0.15; // gravity acceleration

    // collisions
    playerPos.y += playerAccel.y;
    for (size_t i = 0; i < collisions_length; i++)
    {
        if (
            ((playerPos.x + playerWidth - 1) >= collisions[i].p1.x) &&
            (playerPos.x <= collisions[i].p2.x) &&
            (playerPos.y >= collisions[i].p1.y) &&
            ((playerPos.y - playerHeight) <= collisions[i].p2.y))
        {
            if (playerAccel.y > 0)
            {
                playerPos.y -= playerAccel.y;
                playerAccel.y = 0;
                playerState = PLAYER_IDLE;
                break;
            }
            else if (playerAccel.y < 0)
            {
                playerPos.y -= playerAccel.y;
                playerAccel.y = 0;
                break;
            }
        }
    }

    playerPos.x += playerAccel.x;
    for (size_t i = 0; i < collisions_length; i++)
    {
        if (
            ((playerPos.x + playerWidth - 1) >= collisions[i].p1.x) &&
            (playerPos.x <= collisions[i].p2.x) &&
            (playerPos.y >= collisions[i].p1.y) &&
            ((playerPos.y - playerHeight) <= collisions[i].p2.y))
        {
            if (playerAccel.x > 0)
            {
                playerPos.x -= playerAccel.x;
                playerAccel.x = 0;
                playerState = PLAYER_IDLE;
                break;
            }
            else if (playerAccel.x < 0)
            {
                playerPos.x -= playerAccel.x;
                playerAccel.x = 0;
                playerState = PLAYER_IDLE;
                break;
            }
        }
    }

    if (millis() - playerAnimationTimer > 100)
    {
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
        playerAnimationTimer = millis();
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
    if (playerAccel.y != 0)
        return;

    playerAccel.y = -3.0;
    playerState = PLAYER_JUMPING;
}