#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "SPainter.h"
#include "SPushButton.h"
#define IMG_PATH "flstudio_logo.jpeg"

const int width = 1280;
const int height = 920;

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "SDL GUI Test", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    SPainter painter(window,renderer);
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

   SPushButton button(500,500,100,100);

    int w, h; // texture width & height
    // load our image
	SDL_Texture *img = IMG_LoadTexture(renderer, IMG_PATH);
	SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height
	SDL_Rect texr; texr.x = width/2; texr.y = height/2; texr.w = w; texr.h = h; 

    // Set linear blending (haven't tried this with bilinear...)
SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2");

// Create a 4x4 texture to serve as the source for our gradient.
uint32_t * bgpixels;
SDL_Texture * background = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_STREAMING,4,4);

// Set up the gradient colors.
// Each 2x2 quadrant of the texture has a separate color:

// AABB
// AABB
// CCDD
// CCDD
int i;
SDL_LockTexture(background,NULL,(void**)(&bgpixels),&i);
bgpixels[0] = 0x0000ffff;
bgpixels[1] = 0x0000ffff;
bgpixels[2] = 0x00ff00ff;
bgpixels[3] = 0x00ff00ff;
bgpixels[4] = 0x0000ffff;
bgpixels[5] = 0x0000ffff;
bgpixels[6] = 0x00ff00ff;
bgpixels[7] = 0x00ff00ff;
bgpixels[8] = 0xff0000ff;
bgpixels[9] = 0xff0000ff;
bgpixels[10] = 0xffffffff;
bgpixels[11] = 0xffffffff;
bgpixels[12] = 0xff0000ff;
bgpixels[13] = 0xff0000ff;
bgpixels[14] = 0xffffffff;
bgpixels[15] = 0xffffffff;
SDL_UnlockTexture(background);

SDL_Rect r1;
r1.x=1;
r1.y=1;
r1.w=2;
r1.h=2;
// Blit it into place with the renderer.
   // main loop
	while (1) {
		
		// event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
            else if (e.type == SDL_MOUSEBUTTONDOWN){
               //If the left mouse button was pressed
                if( e.button.button == SDL_BUTTON_LEFT )
                {
                    //Get the mouse offsets
                    int x = e.button.x;
                    int y = e.button.y;
                    if ( button.mouseEnter(SVector2(x,y)) ){
                        std::cout << "Mouse in button" <<std::flush;
                    }else{
                        std::cout << "x="<<x<<",y="<<y <<std::flush;
                    }
                    std::cout<<"("<<x<<" ,"<<y<< ")"<<std::flush;
                }
            }
		} 
		
		// clear the screen
		SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,background,&r1,NULL);

        // Set render color to blue ( rect will be rendered in this color )
        SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );

        // Render rect
        SDL_RenderFillRect( renderer, &r );

        // Render the rect to the screen
        // SDL_RenderPresent(renderer);

		// copy the texture to the rendering context
		SDL_RenderCopy(renderer, img, NULL, &texr);
		// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
        painter.setColor(St::red);
        painter.drawRect(400,200,100,40);
        button.paint(painter);
		SDL_RenderPresent(renderer);
		
	}
    SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}