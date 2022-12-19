#include <chrono>
#include "pixel.hpp"
#include "complex.hpp"
#include "fractal.hpp"
#include <iomanip>
int main() 
{
	/*
	double real_step = .003; 
	double imag_step = .000;
	double real = -1.107;
	double imag = -.5066;
	for (int i = 0; i < 100; i++)
	{	
		string name("C:/Users/camer/OneDrive/Desktop/animation2/");
		if (i < 10) 
			name.append("00");
		else if (i >= 10 && i < 100)
			name.append("0");
		name.append(to_string(i));
		name.append(".ppm");
		fractal m1(748U/8, 1024U/8, 'j', real, imag);
		saveToPPM(m1, name);
		cout << real << " " << imag << " " << name << endl;
		real += real_step;
		imag += imag_step;
	}
	return 0;

	*/

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	fractal m1(748U, 1024U, 'j', -.7566, .136);
	saveToPPM(m1, "C:/Users/camer/OneDrive/Desktop/site/julia-.7566_.136.ppm");

	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;



}

