/*
* Auther:	 sanfan66
*
* Date        	 | Change
*--------------------------------------------
* 231017   		 | <record>: None¡úVersion 0.0a£¬Original finished
*                | (describe): Obtain random numbers of Uniform and Gauss
*                | !warning!: Set left and right limits as needed
*/
#pragma once
#include <iostream>//cout
using namespace std;//cout
constexpr auto PI = 3.1415926535897932385;
class Random {
public:
	Random() {};
	~Random() {};
	void SetSeed(const char* mode) const;
	void SetSeed(int num) const;
	double Uniform(double minValue, double maxValue) const;
	double Gauss(double mean, double sigma) const;
};
