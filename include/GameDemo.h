#include <engine_core.h>
class GameDemo
{
    public:
    GameDemo(Engine *engine_core);
    void reset();
    void process_joy(joystick_state joy);
    void process_inputs(inputs_state state);
    void gameLogic(void);
    void draw(void);
private:
    
};
