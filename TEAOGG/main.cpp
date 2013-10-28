#include <SDL.h>

int main(int argc, char *argv[])
{
    const char *title     = "The Extreme Adventure Of Grandpa George";
    const unsigned width  = 640;
    const unsigned height = 480;
    SDL_Rect rect;
    rect.h = 100;
    rect.w = 100;
    rect.x = 250;
    rect.y = 150;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    SDL_Event event;
    SDL_bool alive = SDL_TRUE;

    while(alive)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                alive = SDL_FALSE;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);

        SDL_RenderFillRect(renderer,&rect);

        SDL_SetRenderDrawColor(renderer, 0, 238, 0, 255);

        SDL_RenderDrawRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}