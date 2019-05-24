#pragma once
#include "core.h"
#include "SPaintEvent.h"
#include "SPainter.h"
#include <functional>
class SPushButton{
public:
    SPushButton();
    SPushButton(int _x, int _y, int _width, int _height)
    :x(_x),y(_y),width(_width),height(_height){};
    SRect boundingRect();
    SPainterPath shape();//outline of the object
    void paint(SPainter &painter);
    void paintEvent(SPaintEvent *event);
    bool mouseEnter(SVector2 mouse);
    void setOnMouseClick(std::function<void ()> function){onMouseClickFunction = function;}
    void onMouseClick(){onMouseClickFunction();}


    // Members
    int x,y,width,height;
    SColor color;
    std::function<void ()> onMouseClickFunction;
};