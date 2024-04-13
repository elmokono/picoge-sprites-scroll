#include <Arduino.h>
#include <stdlib.h>
#include <time.h>

#include <sprites.h>
#include "GameDemo.h"

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

  if (joy.x >= 0.8)
    scrollX += 1;
  if (joy.y >= 0.8)
    scrollY += 1;
  if (joy.x <= -0.8)
    scrollX -= 1;
  if (joy.y <= -0.8)
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

  for (int i = 3; i < 4; i++)
  {
    engine_core_ref->canvas->drawRGBBitmap(i * 16 - scrollX, 96 - scrollY, &limestone_bricks[0], 16, 16);
    engine_core_ref->canvas->drawRGBBitmap(i * 16 - scrollX, 112 - scrollY, &dirt[0], 16, 16);
  }

}
