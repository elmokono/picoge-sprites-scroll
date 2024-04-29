#ifndef PLAYER_H
#define PLAYER_H

#include "structs.h"
class Player
{
public:
    char playerState;
    precisionPoint playerPos;
    bool playerFacingRight;
    unsigned short *currentSprite;

    precisionPoint playerAccel;
    unsigned short playerAnimation;
    unsigned long playerAnimationTimer;
    uint16_t playerWidth;
    uint16_t playerHeight;

    Player(void);

    void update(const rect *collisions, u_int16_t collisions_length);
    void move(bool moveRight);
    void jump(void);

private:
};

#endif
