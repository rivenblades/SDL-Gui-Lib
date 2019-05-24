#pragma once
#include <iostream>
class SColor{
public:
	SColor(){r=g=b=0;a=255;}
	SColor(int _r, int _g, int _b):r(_r),g(_g),b(_b){}
	SColor(int _r, int _g, int _b, int _a):r(_r),g(_g),b(_b),a(_a){}
	SColor(unsigned hexcode){
		r = (hexcode & 0xFF000000) >> 24;
		g = (hexcode & 0x00FF0000) >> 16;
		b = (hexcode & 0x0000FF00) >> 8;
		a = (hexcode & 0x000000FF) >> 4;
		// std::cout << r << std::endl;
		// std::cout << g << std::endl;
		// std::cout << b << std::endl;
		// std::cout << a << std::endl;
	}
	unsigned r,g,b,a;
};