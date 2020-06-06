#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Function
{
public:
	Function() { };
	~Function();
	virtual float calculate() { return x; };
	virtual int double_faktorial1(int n);
	virtual int double_faktorial2(int n);
	float x;
private:
};

class Arcsin : public Function
{
public:
	Arcsin(float x);
	float calculate();
};

class Arccos : public Function
{
public:
	Arccos(float x);
	float calculate();
};