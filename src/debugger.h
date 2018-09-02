#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

#ifndef DEBUGGER_H
#define DEBUGGER_H

class Debugger {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Event event;
    TTF_Font* font;
    int font_size = 16;

    const unsigned int texture_width = 320;
    const unsigned int texture_height = 200;
    vector<unsigned char>* pixels;
    SDL_Color black = {0, 0, 0};
    SDL_Color white = {255, 255, 255};
    SDL_Color red = {255, 0, 0};
    int selected_row = 0;
    const uint8_t rendered_line_amount = 50;
    const uint8_t rendered_line_length = 50;
    uint8_t textbox_x = 0;
    uint8_t textbox_y = 0;
    

    public:
    vector<char*>* lines_to_render;
    vector<char*>* lines_pool;
    void init();
    void run();
    bool render();
};

#endif