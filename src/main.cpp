#include <Arduino.h>
#include <stdio.h>
#include <GameDemo.h>

Engine *engine;
GameDemo *game;

void setup()
{
  //while(!Serial.available()){}
  Serial.begin(115200);  

  engine = new Engine();
  game = new GameDemo(engine);

  game->reset();
}

void loop(void)
{  
  //joypad, gyro, pots
  game->process_inputs(engine->inputs());

  game->gameLogic();

  game->draw();

  // buffer to screen  
  engine->display();
  engine->sound();
  //fps
  engine->stats();
}
