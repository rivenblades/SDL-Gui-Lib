#pragma once
#include <iostream>
#include <string>
#include <cstring>
class SColor{
public:
	SColor(){r=g=b=0;a=255;hexColor = (r <<24)&(g<<16)&(b<<8)&(a<<4);hexColor=0x000000ff;}
	SColor(int _r, int _g, int _b):r(_r),g(_g),b(_b){hexColor = (r <<16)&(g<<8)&(b<<4);}
	SColor(int _r, int _g, int _b, int _a):r(_r),g(_g),b(_b),a(_a){hexColor = (r <<24)&(g<<16)&(b<<8)&(a<<4);}
	SColor(unsigned hexcode){
		r = (hexcode & 0xFF000000) >> 24;
		g = (hexcode & 0x00FF0000) >> 16;
		b = (hexcode & 0x0000FF00) >> 8;
		a = (hexcode & 0x000000FF) >> 4;
		hexColor = hexcode;
		// std::cout << r << std::endl;
		// std::cout << g << std::endl;
		// std::cout << b << std::endl;
		// std::cout << a << std::endl;
	}
	const char* serialize(){
		// std::cout <<r<<" "<< g << " "<< b << " " << a<<std::endl;
		// std::cout << std::hex << hexColor;
		// return 0;
		std::string res = std::to_string(static_cast<char>(r)) +","+ std::to_string(static_cast<char>(g))+","+ std::to_string(static_cast<char>(b))+","+ std::to_string(static_cast<char>(a));//+b+a;
		std::cout << res;
		char *cptr = new char[res.size()+1]; // +1 to account for \0 byte
    	std::strncpy(cptr, res.c_str(), res.size());
		cptr[res.size()] = '\0';
		return cptr;
	}
	unsigned r,g,b,a;
	unsigned hexColor;
};