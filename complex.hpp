#pragma once
#include <iostream>
using namespace std;

class complex
{
private:
	double real, imag;
public:

	complex();
	complex(double, double);
	complex(const complex&);
	~complex();

	double& operator[](const char*);

	friend const complex operator*(const complex&, const complex&);
	friend const complex operator+(const complex&, const complex&);
	friend double getMagnitudeSquared(const complex&);
};
