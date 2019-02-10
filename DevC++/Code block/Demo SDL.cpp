#include <SDL.h>

int main(int argc, char*argv[])
{
    SDL_Window*window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("demo",400,200,640,480,4);
    renderer=SDL_CreateRenderer(window, -1,0);

    SDL_SetRenderDrawColor(renderer, 0, 255, 8, 3);
    SDL_SetRenderDrawColor(renderer, 2, 255, 8, 3);
    SDL_RenderDrawLine(renderer, 50,50,50,100);
    SDL_RenderDrawLine(renderer, 20,20,20,100);


    SDL_RenderPresent(renderer);




    SDL_Delay(10000);


}
