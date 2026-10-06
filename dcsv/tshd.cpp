#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class vector{
	int x, y, z;
	vector(int a=0,int b=0, int c=0): x(a), y(b),z(c){};
	friend vector operator+(const vector &a, const vector &b);
	friend vector operator-(const vector &a, const vector &b);
} 	friend int operator*(const vector &a, const vector &b);