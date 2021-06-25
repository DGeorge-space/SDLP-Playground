#include "Shapes.h"


Shapes::Shapes() {
	
}

void Shapes::setRGB(Uint8 red, Uint8 green, Uint8 blue) {
	R = red;
	G = green;
	B = blue;
}
void Shapes::setR(int red) {
	R = red;
}
void Shapes::setG(int green) {
	G = green;

}
void Shapes::setB(int blue) {
	G = blue;

}
Uint8 Shapes::getR() {
	return R;
}
Uint8 Shapes::getG() {
	return G;
}
Uint8 Shapes::getB() {
	return B;
}

void Shapes::setSize(int size) {
	size = size;
}
int Shapes::getSize() {
	return size;
}

int Shapes::getXpos() {
	return Xpos;
}
int Shapes::getYpos() {
	return Ypos;
}

void Shapes::setYpos(int y) {
	Ypos = y;
}
void Shapes::setXpos(int x) {
	Xpos = x;
}
void Shapes::setXandY(int x, int y) {
	Xpos = x;
	Ypos = y;
}

void Shapes::pushBackX(int x) {
	xValsForShape.push_back(x);
}

void Shapes::pushBackY(int y) {
	yValsForShape.push_back(y);
}

void Shapes::output(Screen screen) {
	for (int i = 0; i < xValsForShape.size(); i++) {
		screen.setPixel(xValsForShape[i], yValsForShape[i], getR(), getG(), getB());
	}
}

Shapes::~Shapes() {

}


//CIRCLE METHODS:

Circle::Circle() {
	radius = 10;
}
Circle::Circle(int Radius) {
	radius = Radius;
}
void Circle::setRadius(int radius) {
	radius = radius;
}
void Circle::draw() {
	const float PI = 3.14159265;


	
	for (int i = 0; i < 361; i++) {
		int xp = getXpos() + radius * cos((i * PI) / 180);
		int yp = getYpos() + radius * sin((i * PI) / 180);

		pushBackX(xp);
		pushBackY(yp);

		
	}
}

// RECT METHODS

Rect::Rect()
{
	setSize(1);
}
Rect::Rect(int value) {
	setSize(value);
}

Rect::Rect(int sizex, int sizey) {
	setSize(sizex);
	setSizey(sizey);
	setXandY(300, 300);
	
}

void Rect::setSizey(int size) {
	sizey=size;
}


void Rect::draw() {

	int size = getSize();
	int xPos = getXpos();
	int yPos = getYpos();
	int halfSize = size / 2;

	for (int j = -halfSize; j < halfSize; j++) {
		for (int i = -halfSize; i < halfSize; i++) {
			int xp = xPos + i;
			int yp = yPos + j;
			pushBackX(xp);
			pushBackY(yp);
		}
	}
}

Rect::~Rect()
{
}