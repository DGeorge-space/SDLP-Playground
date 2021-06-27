
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstring>
#include <SDL.h>
#include <vector>
#include "Screen.h"
#include "Circle.h"
#include "Rect.h"
#include "Spectrograph.h"

#pragma once

using namespace std;


class App
{
private:
	Screen screen;
	

public:
	App();

	void Run();

	~App();

};

