#pragma once

#include "core"

class STexture{
public:
	STexture(){}
	STexture(SDL_Texture _texture);
	STexture(std::string path){
		renderer = GetRenderer();
		auto surface = IMG_Load(path.c_str();
		texture = SDL_CreateTextureFromSurface(renderer, surface);
	}
	SDL_Texture texture;
	int width,height;
	SDL_Renderer *renderer;
};