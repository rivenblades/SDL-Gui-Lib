#pragma once

class SRect{
public:
    SRect();
    SRect(int _x,int _y, int _width, int _height)
        :x(_x),y(_y),width(_width),height(_height){}
    int x,y,width,height;
};