#include "SPushButton.h"

SPushButton::SPushButton(){
	x=y=0;
	width=50;
	height = 100;
}

SRect SPushButton::boundingRect(){
	return SRect(x,y,width,height);
}

SPainterPath SPushButton::shape(){
	return SRect(x,y,width,height);
}

void SPushButton::paintEvent(SPaintEvent* event){

}

void SPushButton::paint(){

}