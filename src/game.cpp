#include "game.h"



void Game::initializer(){
    /*
        This function Initializes the window and prints the error if
        Initlization of SDL Goes Wrong

        Note use of Conditional Operators is used
    */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL Could not be initialized, \nError"<< SDL_GetError()<< std::endl;
    }
    else{
        std::cout << "SDL initialized Successfully";
        make_window("IDK, some project i guess");
    }
}

void Game::make_window(const char * window_name){
    /* TODO Documentation */
    window = SDL_CreateWindow(window_name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        std::cout << "Window Could not be initialized \nError " << SDL_GetError() << std::endl;
    }
    else{
        SDL_Surface * surface = make_surface();
    }
}
void Game::event_handeling(){
    SDL_Event event;
    bool quit = false;

    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) quit = true;
        }
    }
}

SDL_Surface * Game::make_surface(){
    SDL_Surface * surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface , NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ));
    SDL_UpdateWindowSurface(window);
    return surface;
}



Game::Game(const char * name){
    initializer();
    make_window(name);
    event_handeling();
}

Game::~Game(){
    SDL_DestroyWindow( window );
    SDL_Quit();
}
