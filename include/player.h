#include "structs.h"
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

const char PLAYER_IDLE = 0;
const char PLAYER_WALKING = 1;
const char PLAYER_CROUCHING = 2;
const char PLAYER_HITTING = 3;
const char PLAYER_JUMPING = 4;

//sprites

class Player
{
public:
    char playerState = PLAYER_IDLE;
    point playerPos = {0, 0};
    bool playerFacingRight = true;
    unsigned short* currentSprite;

    void update(const rect *collisions, u_int16_t collisions_length);
    void move(bool moveRight);
    void jump(void);
private:
    
};
