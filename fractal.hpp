#pragma once
#include "complex.hpp"
#include "pixel.hpp"

class fractal
{
private:
	complex cNum;
	unsigned int cols;
	unsigned int rows;
	char type;
	pixel** grid;
	unsigned int maxIter;
	double real;
	double imag;

	unsigned int determinePixelColor(complex, complex);
	void makeJuliaFractal(double, double);
	void makeMandelBrotFractal();
public:
	fractal();
	fractal(const fractal&);
	fractal(fractal&&);
	fractal(unsigned int, unsigned int, char, double, double);
	~fractal();
	const fractal& operator=(const fractal&);
	fractal& operator=(fractal&&);
	friend void saveToPPM(fractal&, const string);
	pixel convertToPixel(unsigned int);
};