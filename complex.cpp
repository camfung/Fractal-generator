#include <iostream>
#include "complex.hpp"
using namespace std;

// Must use an initializer list to initialize 
// real and imag to zero.
complex::complex() : real{ 0 }, imag{ 0 }
{
}

// Must use an initializer list to initialize 
// real and imag to r and i, respectively.
complex::complex(double r, double i) : real{ r }, imag{ i }
{
}

// Must use an initializer list to initialize 
// real and imag to real and image from object c.
complex::complex(const complex& c) : real{ c.real }, imag{ c.imag }
{
}

complex::~complex()
{
}

const complex operator*(const complex& a, const complex& b)
{
	complex result;
	result.real = (a.real * b.real) - (a.imag * b.imag);
	result.imag = (a.real * b.imag) + (a.imag * b.real);
	return result;
}

const complex operator+(const complex& a, const complex& b)
{
	complex result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

double getMagnitudeSquared(const complex& c)
{
	return (c.real * c.real) + (c.imag * c.imag);
}

double& complex::operator[](const char* c)
{
	if (strcmp(c, "real") == 0)
		return real;
	else if (strcmp(c, "imag") == 0)
		return imag;
	else exit(1);
}