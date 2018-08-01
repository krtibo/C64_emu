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
        texWidth, texHeight);
    
    pixels = new vector<unsigned char>(texWidth * texHeight * 4, 0);

    if (TTF_Init() < 0) 
        cout << "Could not initialize SDL_TTF library." << endl;
    
    font = TTF_OpenFont("./res/C64_pro.ttf", 16);

    if (font == NULL ) {
        cout << TTF_GetError() << endl;
        return;
    }


}

void Debugger::run() {

    bool running = true;
    char* text = "This is a very long ass message to showcase multiline text.";
    SDL_Rect message_rect; 
    SDL_Surface* message_surface = NULL;
    SDL_Texture* messages[50] = { NULL };

    while (running) {

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&event)) {

            if ((SDL_QUIT == event.type) ||
                (SDL_KEYDOWN == event.type && 
                SDL_SCANCODE_ESCAPE == event.key.keysym.scancode)){
                running = false;
                break;
            }

            if (event.type == SDL_MOUSEWHEEL) {
                if (event.wheel.y > 0) {
                    selected_row--;
                } else if (event.wheel.y < 0) {
                    selected_row++;
                }
            }
        }

        // splat down some random pixels
        for (unsigned int i = 0; i < 1000; i++) {
            const unsigned int x = rand() % texWidth;
            const unsigned int y = rand() % texHeight;

            const unsigned int offset = (texWidth * 4 * y) + x * 4;
            pixels->at(offset + 0) = rand() % 256;      // b
            pixels->at(offset + 1) = rand() % 256;      // g
            pixels->at(offset + 2) = rand() % 256;      // r
            pixels->at(offset + 3) = SDL_ALPHA_OPAQUE;  // a
        } 

        SDL_UpdateTexture(texture, NULL, &pixels->at(0), texWidth * 4);
        SDL_RenderCopy(renderer, texture, NULL, NULL ); 

        for (int i=0; i<50; ++i) {

            if (i == selected_row)
                message_surface = TTF_RenderText_Solid(font, text, Red);
            else 
                message_surface = TTF_RenderText_Solid(font, text, Black);

            message_rect.w = message_surface->w; 
            message_rect.h = message_surface->h; 
            message_rect.x = 0;  
            message_rect.y = i*16; 
            messages[i] = SDL_CreateTextureFromSurface(renderer, message_surface);

            SDL_FreeSurface(message_surface);
            SDL_RenderCopy(renderer, messages[i], NULL, &message_rect);
            SDL_DestroyTexture(messages[i]);
        }
        
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}