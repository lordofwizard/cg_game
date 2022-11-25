#include <iostream>
#include <SDL.h>
class Game{
private:
    const int window_width = 600;
    const int window_height = 337;
    const char * name;
    // Making a SDL_Window object
    SDL_Window * window = NULL;

    // Making a SDL_Renderer to use GPU and to upload sprites.
    SDL_Renderer * renderer = NULL;

public:
    // Outside Functions that can be called.

    // This function initializes the SDL Libraries and System
    void initializer();

    // This function returns a SDL_Window Object Pointer to use in constructor
    void make_window(const char * window_name);

    // Returns a renderer object pointer to use in constructor
    SDL_Renderer * make_renderer();

    // Returns a surface object pointer (CAN MAKE MANY INSTANCES)
    SDL_Surface * make_surface();

    // Event Handeling Main Function
    void event_handeling();

    // MAIN CONSTRUCTOR (where everything happens)
    Game(const char * name);

    // Destructor kill all objects and free the memory here..
    ~Game();
};
