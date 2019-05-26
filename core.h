#pragma once
#include "SRect.h"
#include "SPainterPath.h"
#include "SColor.h"
#include "St.h"
#include "SVector2.h"
#include "common.h"
#include "SFramework.h"
#include "STexture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


static const SDL_Window *window;
static const SDL_Renderer *renderer;
SDL_Window* GetWindow(){return window;}
SDL_Renderer* GetRenderer(){return renderer;}
