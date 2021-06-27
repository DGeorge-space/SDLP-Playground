#include "App.h"

App::App() {


	// The screen object initialises the window, renderer, texture and buffers 1 & 2 as Null 
	
	Screen screen;
	
}

void App::Run() {
	//screen.init() sets the m_window object, with a name for the window, X & Y position [set to Undefined currently], and screen height and size:
// a possible optimisation here is to overload the init function with options for position, window width, height and name. 
// Further, might be better to split the init function into several for usability and improved experience. 
	
	if (screen.init() == false) {

		//if the function fails output a message to the console, may be better to do this using printf: 
			//cout << "Error initialising SDL" << endl;
		printf("Error initialising SDL, SDL Error: %s\n", SDL_GetError());
	}
	//This is the main 'game loop' where the magic happens

	Spectrograph spectrograph(screen,32);
	
	spectrograph.draw();

	vector<double> binHeights;


	while (true) {
		for (int i = 0; i < 32; i++) {
			binHeights.push_back(rand()%10);
		}
		spectrograph.updateBin(binHeights);
		spectrograph.draw();
		spectrograph.outputSpectrograph(screen);
		SDL_Delay(5);




		/* At the end of the loop the update function will update the texture from the data in the buffer, clear the renderer,
		* update the renderer with the updated texture and then present the renderer on to the window
		*/
		screen.update();

		/*
		A little box blur function that averages the colour RGB for a given pixel with its 9 near neighbours -
			possible optimisation:
				- only blur pixels that are not the same as the bakground colour
		*/
		screen.boxBlur();


		//All Events handling goes on in screen. processEevents() 
		if (screen.processEvents() == false) {
			
			break; // exit the program 
		}
		
	}
	
}


App::~App() {

	screen.close();
}