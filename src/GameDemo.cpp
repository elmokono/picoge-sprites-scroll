#include <Arduino.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "sprites.h"
#include "maps.h"
#include "GameDemo.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MAGENTA 0xF81F

Engine *engine_core_ref;
Player *player = new Player();

float scrollX, scrollY = 0.0;

GameDemo::GameDemo(Engine *engine_core)
{
  engine_core_ref = engine_core;
  reset();
}

void GameDemo::reset()
{

}

void GameDemo::process_joy(joystick_state joy)
{
  if (joy.novalue)
    return;

  if (joy.x >= 0.8) // && scrollX < (level0.cellWidth * level0.mapCellsWidth) - engine_core_ref->canvas->width())
    player->move(true);
  // scrollX += 1;
  // if (joy.y >= 0.8 && scrollY < (level0.cellHeight * level0.mapCellsHeight) - engine_core_ref->canvas->height())
  //   scrollY += 1;
  if (joy.x <= -0.8)     // && scrollX > 0)
    player->move(false); // scrollX -= 1;
  // if (joy.y <= -0.8 && scrollY > 0)
  //   scrollY -= 1;
  if (joy.b1)
    player->jump();
}

void GameDemo::process_inputs(inputs_state state)
{
  process_joy(state.joy_state);
}

void GameDemo::gameLogic(void)
{
  // character
  player->update();

  // npcs

  // scene
}

void GameDemo::draw(void)
{
  engine_core_ref->canvas->fillBitmap(&bgImage[0]);

  if (player->playerPos.x + scrollX > 64)
    scrollX--;
  if (player->playerPos.x + scrollX < 32)
    scrollX++;
  if (player->playerPos.y + scrollY > 64)
    scrollY--;
  if (player->playerPos.y + scrollY < 32)
    scrollY++;
  // if (player->playerPos.x < 32) scrollX++;
  // if (player->playerPos.y > engine_core_ref->canvas->height() - 32) scrollY++;
  // if (player->playerPos.y < 32) scrollY--;

  // tiles
  for (unsigned short i = 0; i < ARRAY_SIZE(level0.cells); i++)
  {
    if (level0.cells[i] == nullptr)
      continue;

    const unsigned short y = (i / level0.mapCellsWidth) * level0.cellHeight;
    const unsigned short x = (i % level0.mapCellsWidth) * level0.cellWidth;

    engine_core_ref->canvas->drawRGBBitmap(x + scrollX, y + scrollY, level0.cells[i], level0.cellWidth, level0.cellHeight);
  }

  // player
  engine_core_ref->canvas->drawRGBBitmap(player->playerPos.x + scrollX, player->playerPos.y - 32 + scrollY, player->currentSprite, 32, 32, 0x0000);

  // Serial.println(scrollX);
}
