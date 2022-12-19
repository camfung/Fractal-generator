#pragma once

#include "pixel.hpp"

pixel::pixel() :red{ 0 }, blue{ 0 }, green{ 0 }
{
}

pixel::pixel(const pixel& p) : red{ p.red }, blue{ p.blue }, green{ p.green }
{
}

pixel::pixel(unsigned int r, unsigned int g, unsigned int b) : red{ r }, blue{ b }, green{ g }
{
}

pixel::~pixel()
{
}

unsigned int& pixel::operator[](const char* c)
{
	if (strcmp(c, "red") == 0)
		return this->red;
	else if (strcmp(c, "green") == 0)
		return this->green;
	else if (strcmp(c, "blue") == 0)
		return this->blue;
	else exit(1);
}

ostream& operator<<(ostream& output, pixel p)
{
	output << p["red"] << " " << p["green"] << " " << p["blue"] << " ";
	return output;
}
