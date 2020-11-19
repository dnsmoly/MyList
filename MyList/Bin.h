#pragma once
#include <string>
#include <iostream>
using namespace std;

static int numberSize = 7;

class Bin {

public:

	//Bin();
	Bin(int num);
	Bin(string binary = "00000000");

	void biPrint();
	void intPrint();
	const Bin operator+(Bin a);
	const Bin operator-(Bin a);
	const Bin operator*(Bin a);
	const Bin operator/(Bin a);
	friend bool operator== (const Bin& left, const Bin& right);
	friend bool operator!= (const Bin& left, const Bin& right);
	friend ostream& operator<<(ostream& os, const Bin& at);

private:

	string bi;
	int i;

	void toBinary(int num);
	int toInt(string bi);
	void convert(int num);
	void firstAddition();
	

	
};
