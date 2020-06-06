#include <iostream>
#include <cmath>
#include <iomanip>
#include "PartOne.h"

using namespace std;

int Function::double_faktorial1(int  n)
{
	int ans = 1;
	for (int a = 1; a < n + 1; a = a + 2)
	{
		ans = ans * a;
	}
	return ans;
}
int Function::double_faktorial2(int  n)
{
	int ans = 1;
	for (int a = 2; a < n + 1; a = a + 2)
	{
		ans = ans * a;
	}
	return ans;
}

Function::~Function()
{
}

Arcsin::Arcsin(float x) :Function()
{
	this->x = x;
}

float Arcsin::calculate()
{
	float arcsin = x;
	for (int m = 1; m < 9; m++)
	{
		arcsin += (double_faktorial1((2 * m) - 1) * pow(x, (2 * m) + 1)) / ((double_faktorial2(2 * m)) * ((2 * m) + 1));
	}
	return arcsin;
}

Arccos::Arccos(float x) :Function()
{
	this->x = x;
}

float Arccos::calculate()
{
	float arccos = 1.57079633 - x;
	for (int m = 1; m < 9; m++)
	{
		arccos -= (double_faktorial1((2 * m) - 1) * pow(x, (2 * m) + 1)) / ((double_faktorial2(2 * m)) * ((2 * m) + 1));
	}
	return arccos;
}