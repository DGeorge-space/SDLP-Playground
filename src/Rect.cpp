#include "Rect.h"

Rect::Rect() {
	Xpos = 0;
	Ypos = 0;
	height = 0;
	width = 0;
}

Rect::Rect(int left, int top, int h, int w) {

	// left & top refer to the coordinates of the top left part of the rect

	Xpos = left;
	Ypos = top;
	height = h;
	width = w;

	bottomYcoordinate = height;
	bottomXcoordinate = Xpos + width;



}

void Rect::draw() {

	for (int x = Xpos; x < Xpos + width+1; x++) {
		for (int y = Ypos; y < Ypos+height+1; y++) {
			pushBackX(x);
			pushBackY(y);
		}
	}

}

void Rect::setHeight(int h) {
	height = h;
	this->draw();
}
void Rect::setWidth(int w) {
	bottomXcoordinate = w;
}




;
