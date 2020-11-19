#pragma once
#include <string>
#include <iostream>
#include "Bin.h"
using namespace std;

Bin::Bin(int num) {
	i = num;
	toBinary(num);
}
Bin::Bin(string binary) {
	//if(binary.size() > numberSize) throw invalid_argument("Invalid input: the number is too big");
	//if (binary.size() < numberSize) throw invalid_argument("Invalid input: the number is too small");
	bi = binary;
	i = toInt(binary);
}

void Bin::biPrint() {
	cout << bi << endl;
}

void Bin::intPrint() {
	cout << i << endl;
}

const Bin Bin::operator+(Bin a) {

	string res;
	string sec = a.bi;
	int tmp;
	int p = 0; // целая часть

	for (int i = (bi.size() - 1); i >= 0; i--) {
		tmp = int(bi[i] - 48) + int(sec[i] - 48) + p;
		res = to_string(tmp % 2) + res;
		p = tmp / 2;
	}
	//if (p != 0) {
	//	throw invalid_argument("The number is out of range");
	//}

	if (bi[0] == '0' && sec[0] == '0' && res[0] == '1') {
		throw invalid_argument("The number is out of range");
	}
	else if (bi[0] == '1' && sec[0] == '1' && res[0] == '0') {
		throw invalid_argument("The number is out of range");
	}
	
	return Bin(res);
}

const Bin Bin::operator-(Bin a) {

	Bin tmp = Bin(bi);
	if (a.bi[0] == '1') a.bi[0] = '0';
	else a.bi[0] = '1';
	a.firstAddition();
	a = a + Bin(1);
	return tmp + a;
}

const Bin Bin::operator*(Bin a) {

	Bin tmp = Bin(bi);
	Bin res = Bin(bi);
	if (a.i == 0 || tmp.i == 0) {
		return Bin(0);
	}
	int multiplier = unsigned(a.i);
	for (int i = 0; i < multiplier - 1; i++) {
		res = res + tmp;
	}
	if (i != a.i) res.bi[0] = '1';
	else res.bi[0] = '0';
	return res;
}

const Bin Bin::operator/(Bin a) { // хранить отрицательные в дополнительном

	if (a.i == 0) {
		throw invalid_argument("Dividing by zero");
	}
	Bin tmp = Bin(bi);
	int x = tmp.i / a.i;
	Bin res = Bin(x);

	for (int i = 0; i < (a.i - 1); i++) {
		tmp = tmp - res;
	}

	if (i != a.i) tmp.bi[0] = '0';
	else tmp.bi[0] = '1';
	return tmp;
}

void Bin::toBinary(int num) { 
	if (num > (pow(2, numberSize) - 1) || num < -(pow(2, numberSize))) {
		cout << "error in toBinary" << endl;
		throw invalid_argument("The number is out of range");
	} 
	convert(num);
	if (num != -(pow(2, numberSize)) && num < 0) {
		
		Bin tmp = Bin(bi);
		tmp.firstAddition();
		tmp = tmp + 1;
		bi = tmp.bi;
		
	}
	
}

int Bin::toInt(string bi) {
	int result = 0;

	for (int i = 1; i < bi.size(); i++) {
		result += ((int)bi[i] - 48) * pow(2, (bi.size() - 1 - i));
	}
	if (bi[0] == '1') result = result - pow(2, bi.size() - 1);
	if (result > (pow(2, numberSize) - 1) || result < -(pow(2, numberSize))) {
		cout << "error in toInt" << endl;
		throw invalid_argument("The number is out of range");
	}
	return result;
}

void Bin::convert(int num) {

	string res;
	bool pos = (num >= 0);
	if (num == -pow(2, numberSize)) {
		bi = "1";
		for (int i = 0; i < numberSize; i++) {
			bi = bi + "0";
		}
	}
	else {
		if (num < 0) num = -num;
		while (num) {
			res = to_string(num % 2) + res;
			num = num / 2;
		}
		if (res.size() < numberSize) { // needed length; 7 is optional
			unsigned int tmp = res.size();

			for (int i = 0; i < numberSize - tmp; i++) {
				res = '0' + res;
			}
		}
		//if (res.size() > numberSize) {
		//	cout << "res:" << res << endl;
		//	throw invalid_argument("The number is out of range");
		//}

		if (pos) res = '0' + res; // positive - first bit = 0
		else res = '1' + res; // negative - firts bit = 1

		bi = res;
	}
}

void Bin::firstAddition() { 

	string res;
	res = bi[0];
	for (int i = 1; i < bi.size(); i++) {
		if (bi[i] == '0') res += '1';
		else res += '0';
	}
	bi = res;
}

bool operator==(const Bin& left, const Bin& right)
{
	if (left.bi == right.bi) return true;
	else return false;
}

bool operator!= (const Bin& left, const Bin& right) {
	return !(left == right);
}

ostream& operator<<(ostream& os, const Bin& at) {
	os << at.bi;
	return os;
}
