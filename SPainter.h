#pragma once
#include "core.h"


class SPainter{
public:
    SPainter();
    SPainter(SDL_Window* w, SDL_Renderer* r);
    virtual void paint();
    void drawRect(int x, int y, int width, int height);


    SDL_Renderer* _renderer;
    SDL_Window* _window;
    SColor _color;//foreground color to draw;
};