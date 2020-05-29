#include <iostream>
#include <time.h>
#include <cstring>
#include <SDL.h>
#include "Screen.h"

#include "Draw.h"

using namespace std;


const int ScreenWidth = 600;
const int halfScreenWidth = ScreenWidth / 2;
const int ScreenHeight = 800;



int main(int argc, char* argv[])
{
	srand(time(NULL));

	Screen screen;
	Draw circle;
	Draw square;
	Draw square2;
	if (screen.init() == false) {
		cout << "Error initialising SDL" << endl;
	}
	while (true) {
		//update particles
		//draw particles
		int elapsed = SDL_GetTicks();

		unsigned char green = (1 + sin(elapsed * 0.0005)) * 128;
		unsigned char red = (1 + cos(elapsed * 0.005)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0007)) * 128;

		int x = ScreenWidth/2;
		int y = ScreenHeight/2;

		int theta = 0;

		int radius = 1000;


		while (radius>1)
		{
			circle.circle(x, y, radius);
			radius-=10;
		}

		square.rect(0, 0);
		square2.rect(ScreenWidth, ScreenHeight);

		///added a comment to test


		square.output(screen,20, 20, 20);
		circle.output(screen);
		


		screen.boxBlur();

		screen.update();


		
		if (screen.processEvents() == false) {
			break;
		}
	}


	screen.close();
	return 0;
}