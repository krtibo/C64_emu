#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <vector>

using namespace std;

#ifndef DEBUGGER_H
#define DEBUGGER_H

class Debugger {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Event event;
    TTF_Font* font;

    const unsigned int texWidth = 320;
    const unsigned int texHeight = 200;
    vector<unsigned char>* pixels;
    SDL_Color Black = {0, 0, 0};
    SDL_Color White = {255, 255, 255};
    SDL_Color Red = {255, 0, 0};
    int selected_row = 0;
    const uint8_t rendered_line_amount = 50;
    const uint8_t rendered_line_length = 50;
    vector<char*>* lines_to_render;

    public:

    void init();
    void run();
};

#endif