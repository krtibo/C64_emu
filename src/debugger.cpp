#include "debugger.h"

void Debugger::init() {

    window = SDL_CreateWindow(
        "C64",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1280, 800,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        texture_width, texture_height);
    
    pixels = new vector<unsigned char>(texture_width * texture_height * 4, 0);
    lines_to_render = new vector<char*>(rendered_line_amount, " ");

    if (TTF_Init() < 0) 
        cout << "Could not initialize SDL_TTF library." << endl;
    
    font = TTF_OpenFont("./res/C64_pro.ttf", font_size);

    if (font == NULL) {
        cout << TTF_GetError() << endl;
        return;
    }
}

bool Debugger::render() {
    
    SDL_Rect message_rect; 
    SDL_Surface* message_surface = NULL;
    SDL_Texture* messages[rendered_line_amount];

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    while (SDL_PollEvent(&event)) {

        if ((SDL_QUIT == event.type) ||
            (SDL_KEYDOWN == event.type && 
            SDL_SCANCODE_ESCAPE == event.key.keysym.scancode)){
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return false;
        }

        if (event.type == SDL_MOUSEWHEEL) {
            if (event.wheel.y > 0 && selected_row > 0) {
                selected_row--;
                // cout << strlen(lines_to_render->at(selected_row)) << endl;
            } else if (event.wheel.y < 0 && selected_row < rendered_line_amount-1) {
                selected_row++;
                // cout << strlen(lines_to_render->at(selected_row)) << endl;
            }
        }
    }

    SDL_UpdateTexture(texture, NULL, &pixels->at(0), texture_width * 4);
    SDL_RenderCopy(renderer, texture, NULL, NULL ); 

    for (int i=0; i<rendered_line_amount; ++i) {

        if (strlen(lines_to_render->at(i)) > rendered_line_length) {
            // cut the reminder characters
        }

        if (i == selected_row)
            message_surface = 
                TTF_RenderText_Solid(font, lines_to_render->at(i), red);
        else 
            message_surface = 
                TTF_RenderText_Solid(font, lines_to_render->at(i), white);

        message_rect.w = message_surface->w; 
        message_rect.h = message_surface->h; 
        message_rect.x = textbox_x + 0;  
        message_rect.y = textbox_y + i*font_size; 
        messages[i] = SDL_CreateTextureFromSurface(renderer, message_surface);

        SDL_FreeSurface(message_surface);
        SDL_RenderCopy(renderer, messages[i], NULL, &message_rect);
        SDL_DestroyTexture(messages[i]);
    }

    SDL_RenderPresent(renderer);
    return true;
}