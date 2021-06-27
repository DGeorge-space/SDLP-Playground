#include "Spectrograph.h"

#include <iostream>

Spectrograph::Spectrograph(Screen scr, int nBins) {

	numBins = nBins;
	padding = 4;
	screenHeight = scr.ScreenHeight;
	screenWidth = scr.ScreenWidth;
	calculateBinWidth();
	binStartPosition = 0;



}
Spectrograph::Spectrograph(Screen scr) {

	numBins = 32;
	padding = 4;
	screenHeight = scr.ScreenHeight;
	screenWidth = scr.ScreenWidth;
	binStartPosition = 0;

	calculateBinWidth();

}

int Spectrograph::calculateBinWidth() {
	int width = screenWidth / (numBins);
	binWidth = width;

	return width;


}

void Spectrograph::setPadding(int paddingAmount) {
	padding = paddingAmount;
}

void Spectrograph::initialiseBins() {
	int startpos = 0;
	
	for (int i = 0; i < numBins; i++) {

		int left = (i * binWidth) + padding;
		int width = binWidth;
		int binheight = screenHeight / 2;
		int top = binheight;

		binList.push_back(new Rect{left,top, binheight, width});
		binList[i]->setRGB(255, 0, (i*3)%256);
	

	}
}

void Spectrograph::updateBin(vector<double> binHeights) {
	for (int i = 0; i < binList.size(); i++) {
		binList[i]->setHeight(binHeights[i]);
		binList[i]->draw();
		binList[i]->output();
	}

}

void Spectrograph::draw() {
	for (int i = 0; i < binList.size(); i++) {
		binList[i]->draw();

	}
}
void Spectrograph::outputSpectrograph(Screen screen) {
	for (int i = 0; i < binList.size(); i++) {
		binList[i]->output(screen);
	}
}

Spectrograph::~Spectrograph() {
	for (int i = 0; i < binList.size(); i++)
	{
		delete binList[i];
	}
}