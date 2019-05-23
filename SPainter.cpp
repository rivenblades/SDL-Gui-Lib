#include "SPainter.h"
#include <iostream>


SPainter::SPainter(){
	_renderer = NULL;
	if (!_window){
		_window = SDL_CreateWindow(
								"SDL GUI Test", SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								400,
								400,
								SDL_WINDOW_SHOWN
								);
	}
    _renderer =  SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED);
	if (!_renderer){
		std::cout << "Couldn't create renderer";
	}
}

SPainter::SPainter(SDL_Window* w, SDL_Renderer* r){
	_window = w;
	_renderer = r;
	_color = SColor(St::red);
}

void SPainter::paint(){
	
}
void SPainter::drawRect(int x, int y, int width, int height){

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor( _renderer, _color.r, _color.g, _color.b, _color.a);

	// Render rect
	SDL_Rect r1;
	r1.x = x;
	r1.y = y;
	r1.w=width;
	r1.h=height;
	SDL_RenderFillRect( _renderer, &r1 );

}