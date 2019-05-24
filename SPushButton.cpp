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
	SPainterPath path;
	return path;
	// return SRect(x,y,width,height);
}

void SPushButton::paintEvent(SPaintEvent* event){

}

void SPushButton::paint(SPainter &painter){
	color = SColor(St::red);
	painter.setColor(color);
	painter.drawRect(x,y,width,height);
}

bool SPushButton::mouseEnter(SVector2 mouse){
	int mx = mouse.x;
	int my = mouse.y;
	if (mx >= x && mx <= mx+width){
		if (my >= y && my <= my+height){
			onMouseClick();
			return true;
		}
	}
	return false;
}