#include "deltaTime.h"
#include <SDL2/SDL_timer.h>
double lastFrameTime = SDL_GetTicks() / 1000.0f;
double delta = 0;
void findDeltaTime(){
    double currentTime = SDL_GetTicks() / 1000.0f;
    delta =  (currentTime-lastFrameTime);
    lastFrameTime = currentTime;
}
