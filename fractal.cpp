#include "fractal.hpp"
#include "complex.hpp"

fractal::fractal() : cols{ 0 }, rows{ 0 }, type{ '\0' }, grid{ nullptr }, maxIter{ 0 }
{}



fractal::fractal(const fractal& f) : cols{ f.cols }, grid{ nullptr }, rows{ f.rows }, type{ f.type }, maxIter{ f.maxIter }
{
	cout << "Copy Constructor called..." << endl;
	grid = new pixel * [rows];
	for (unsigned int i = 0; i < rows; i++) {
		grid[i] = new pixel[cols];
	}
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			grid[i][j] = f.grid[i][j];
		}
	}
}

fractal::fractal(fractal&& f) : cols{ f.cols }, grid{ f.grid }, rows{ f.rows }, type{ f.type }, maxIter{ f.maxIter }
{
	cout << "Move Constructor called..." << endl;
	f.grid = nullptr;
	f.cols = 0;
	f.rows = 0;
	f.type = '\0';
	f.maxIter = 0;
}

fractal::~fractal()
{
	for (unsigned int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;

}

const fractal& fractal::operator=(const fractal& f)
{
	cout << "assignment operator called" << endl;
	if (this != &f)
	{
		if (grid != nullptr)
			delete[] grid;
		grid = new pixel * [rows];
		for (unsigned int i = 0; i < rows; i++) {
			grid[i] = new pixel[cols];
		}
		for (unsigned int i = 0; i < rows; i++)
		{
			for (unsigned int j = 0; j < cols; j++)
			{
				grid[i][j] = f.grid[i][j];
			}
		}
	}
	return *this;
}

fractal& fractal::operator=(fractal&& f)
{
	cout << "Move assignment operator called..." << endl;
	swap(rows, f.rows);
	swap(cols, f.cols);
	swap(grid, f.grid);
	swap(maxIter, f.maxIter);
	swap(type, f.type);
	return *this;
}


fractal::fractal(unsigned int r, unsigned int c, char t, double l, double i):
	cols{ c }, rows{ r }, type{ t }, grid{ nullptr }, maxIter{ 512 }, real{ l }, imag{ i }
{
	grid = new pixel * [rows];
	for (unsigned int i = 0; i < rows; i++) {
		grid[i] = new pixel[cols];
	}
	if (type == 'm')
		makeMandelBrotFractal();
	else makeJuliaFractal(real, imag);
}

unsigned int fractal::determinePixelColor(complex z, complex c)
{
	double lengthSqrd;
	for (unsigned int iter = 0; iter < maxIter; iter++)
	{
		z = z * z;
		z = z + c;
		lengthSqrd = getMagnitudeSquared(z);
		if (lengthSqrd > 4.0)
			return iter;
	}
	return maxIter;
}


void fractal::makeJuliaFractal(double real, double imag)
{
	complex z;
	complex c(real, imag);
	double stepHeight = 4.0 / static_cast<double>(rows);
	double stepWidth = 4.0 / static_cast<double>(cols);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			z["real"] = ((static_cast<double>(i) * stepHeight) - 2.0);
			z["imag"] = ((static_cast<double>(j) * stepWidth) - 2.0);
			unsigned int color = determinePixelColor(z, c);
			grid[i][j] = convertToPixel(color);
		}
	}
}


void fractal::makeMandelBrotFractal()
{
	cout << "Now creating the Mandel Brot Fractal..." << endl;
	complex c, z;
	double stepHeight = 3.0 / static_cast<double>(rows);
	double stepWidth = 4.0 / static_cast<double>(cols);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			z["imag"] = 0.0;
			z["real"] = 0.0;
			c["real"] = ((static_cast<double>(i) * stepHeight) - 2.0);
			c["imag"] = ((static_cast<double>(j) * stepWidth) - 2.0);
			unsigned int color = determinePixelColor(z, c);
			grid[i][j] = convertToPixel(color);
		}
	}
}

pixel fractal::convertToPixel(unsigned int colour)
{
	int red = (colour / 64) % 8;
	int green = (colour / 8) % 8;
	int blue = colour % 8;
	return pixel(blue,red, green);
}

void saveToPPM(fractal& f, const string c)
{
	fstream output(c, ios::out);
	output << "P3" << endl;
	if (f.type == 'm') output << "# Mandel Brot Fractal" << endl;
	else output << "# Julia Fractal" << endl;
	output << f.cols << " " << f.rows << " " << endl;
	output << "7" << endl;
	for (unsigned int i = 0; i < f.rows; i++)
	{
		for (unsigned int j = 0; j < f.cols; j++)
		{
			output << f.grid[i][j];
		}
		output << endl;
	}
}