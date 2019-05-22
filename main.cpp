#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define IMG_PATH "flstudio_logo.jpeg"

const int width = 1280;
const int height = 920;

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );

    // Render the rect to the screen
    SDL_RenderPresent(renderer);

    int w, h; // texture width & height
    // load our image
	SDL_Texture *img = IMG_LoadTexture(renderer, IMG_PATH);
	SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height
	SDL_Rect texr; texr.x = width/2; texr.y = height/2; texr.w = w; texr.h = h; 
   // main loop
	while (1) {
		
		// event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
		} 
		
		// clear the screen
		SDL_RenderClear(renderer);
		// copy the texture to the rendering context
		SDL_RenderCopy(renderer, img, NULL, &texr);
		// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
		SDL_RenderPresent(renderer);
		
	}
    SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}