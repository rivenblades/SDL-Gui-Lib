#pragma once
#include "core.h"
#include "SPaintEvent.h"
class SPushButton{
public:
    SPushButton();
    SPushButton(int _x, int _y, int _width, int _height)
    :x(_x),y(_y),width(_width),height(_height){};
    int x,y,width,height;
    SRect boundingRect();
    SPainterPath shape();//outline of the object
    void paint();
    void paintEvent(SPaintEvent *event);
};