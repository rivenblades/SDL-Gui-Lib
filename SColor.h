#pragma once
#include <iostream>
class SColor{
public:
	SColor(){r=g=b=0;a=255;}
	SColor(int _r, int _g, int _b):r(_r),g(_g),b(_b){}
	SColor(int _r, int _g, int _b, int _a):r(_r),g(_g),b(_b),a(_a){}
	SColor(unsigned hexcode){
		// std::cout << hexcode;
		// std::cout <<"Eniwsa";
		// // std::cout << hexcode/65536;
		// // std::cout << hexcode/65536/652800;
		// // std::cout << hexcode/65536/652800/2550;
		// r = ((hexcode & 0xF800)>>8);
		// g = ((hexcode & 0x07E0)>>3);
		// b = ((hexcode & 0x001F)>>3);
		// a = 255;
		// std::cout << ((hexcode & 0xFF0000))<<std::endl;
		// std::cout << ((hexcode & 0x07E0))*255/63<<std::endl;
		// std::cout << ((hexcode & 0x001F))*255/31<<std::endl;
		
		r = (hexcode & 0xFF0000) >> 16;
		g = (hexcode & 0x00FF00) >> 8;
		b = (hexcode & 0x0000FF) >> 4;
		std::cout << r<<std::endl;
		std::cout << g<<std::endl;
		std::cout << b<<std::endl;
	}
	unsigned r,g,b,a;
};