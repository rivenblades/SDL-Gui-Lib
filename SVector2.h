#pragma once

class SVector2{
public:
	SVector2(){x=y=0;}
	SVector2(int _x, int _y):x(_x),y(_y){}
	int x,y;
};