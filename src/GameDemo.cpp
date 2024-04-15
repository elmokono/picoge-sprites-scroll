#include <Arduino.h>
#include <stdlib.h>
#include <time.h>

#include <sprites.h>
#include <maps.h>
#include "GameDemo.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define MAGENTA 0xF81F

#define PRESS_ANY_KEY "-PRESS ANY KEY-"

Engine *engine_core_ref;

float scrollX, scrollY = 0.0;

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
}

Point::Point()
{
  this->x = 0;
  this->y = 0;
}

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

  if (joy.x >= 0.8 && scrollX < (level0.blockWidth * level0.mapWidthInBlocks) - engine_core_ref->canvas->width())
    scrollX += 1;
  if (joy.y >= 0.8 && scrollY < (level0.blockHeight * level0.mapHeightInBlocks) - engine_core_ref->canvas->height())
    scrollY += 1;
  if (joy.x <= -0.8 && scrollX > 0)
    scrollX -= 1;
  if (joy.y <= -0.8 && scrollY > 0)
    scrollY -= 1;
  if (joy.b1)
    engine_core_ref->rgb(0, 0, 0);
}

void GameDemo::process_inputs(inputs_state state)
{
  process_joy(state.joy_state);
}

void GameDemo::gameLogic(void)
{
}

void GameDemo::draw(void)
{
  engine_core_ref->canvas->fillBitmap(&bgImage[0]);

  // tiles
  for (unsigned short i = 0; i < ARRAY_SIZE(level0.tiles); i++)
  {
    if (level0.tiles[i] == nullptr)
      continue;

    const unsigned short y = (i / level0.mapWidthInBlocks) * level0.blockHeight;
    const unsigned short x = (i % level0.mapWidthInBlocks) * level0.blockWidth;

    engine_core_ref->canvas->drawRGBBitmap(x - scrollX, y - scrollY, level0.tiles[i], level0.blockWidth, level0.blockHeight);
  }
}
