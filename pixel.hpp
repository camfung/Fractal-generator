#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class pixel
{
private:
	unsigned int red;
	unsigned int green;
	unsigned int blue;
public:
	pixel();
	pixel(const pixel&);
	pixel(unsigned int r, unsigned int g, unsigned int b);
	~pixel();
	unsigned int& operator[](const char*);
	friend ostream& operator<<(ostream&, pixel);
};