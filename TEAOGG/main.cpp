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
            switch(event.type)
            {
            case SDL_QUIT:
                {
                    alive = SDL_FALSE;
                    break;
                }
            case SDL_KEYDOWN:
                {
                    if(event.key.keysym.sym == SDLK_LEFT)
                    {
                        rect.x -= 10;

                        if (rect.x < 0)
                            rect.x = 0;
                    }
                    if(event.key.keysym.sym == SDLK_RIGHT)
                    {
                        rect.x += 10;

                        if (rect.x > 640 - rect.w)
                            rect.x = 640 - rect.w;
                    }
                }
            default:
                {
                    break;
                }
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