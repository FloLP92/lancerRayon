//============================================================================
// Name        : RGB.h
// Author      : DOISNEAU Vincent - LE PALLEC Florian
// Version     : 1 (31 Janvier 2017)
// Copyright   :
// Description : Code couleur RGB (header)
//============================================================================

#ifndef RGB_H_
#define RGB_H_
#include <iostream>

class RGB {
private:
	int red,green,blue; // code RGB
public:
	RGB(float chRed,float chGreen,float chBlue) : red(chRed), green(chGreen), blue(chBlue){}
	RGB();
	virtual ~RGB();
	friend std::ostream& operator<<(std::ostream &out, const RGB &a);
	//Getters and Setters
	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	void setRed(int chRed);
	void setGreen(int chGreen);
	void setBlue(int chBlue);
};
std::ostream& operator<<(std::ostream &out, const RGB &a);
#endif /* RGB_H_ */
