#pragma once
class Colors
{
private:
	int Red;
	int Green;
	int Blue;
public:
	int getRed();
	int getGreen();
	int getBlue();
	void setRed(int red);
	void setGreen(int green);
	void setBlue(int blue);
	void setRGB(int red, int green, int blue);
};

