#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;

class Complex {
public:
	Complex();
	Complex(int, int);
	int getA();
	int getB();
	Complex add(Complex c1);
	Complex subtract(Complex c1);
	Complex multiply(Complex c1);
	string toString();

	Complex operator+();
	Complex operator-();
	friend ostream &operator<<(ostream&, Complex&);
	friend istream &operator>>(istream&, Complex&);
	int& operator[](int index);
	Complex &operator+=(Complex c1);
	Complex &operator-=(Complex c1);
	Complex &operator*=(Complex c1);
	Complex &operator++();
	Complex &operator--();
private:
	int a, b;
};
Complex operator+(Complex c1,Complex c2);
Complex operator-(Complex c1,Complex c2);
Complex operator*(Complex c1,Complex c2);
#endif


#include"Complex.h"
Complex::Complex() {

}
Complex::Complex(int a, int b) {
	this->a = a;
	this->b = b;
}
int Complex::getA() {
	return a;
}
int Complex::getB() {
	return b;
}
Complex Complex::add(Complex c1) {
	int x = a + c1.getA();
	int y = b + c1.getB();
	return Complex(x, y);
}
Complex Complex::subtract(Complex c1) {
	int x = a - c1.getA();
	int y = b - c1.getB();
	return Complex(x, y);
} 
Complex Complex::multiply(Complex c1) {
	int x = a*c1.getA() - b*c1.getB();
	int y = a*c1.getB() + b*c1.getA();
	return Complex(x, y);
}
string Complex::toString() {
	stringstream s1;
	s1 << a;
	if(b>0)
	    s1<<"-"<<b<<"i";
	else if(b<0)
	    s1<<"-"<<b<<"i";
	return s1.str();
}
Complex Complex::operator+() {
	return *this;
}
Complex Complex::operator-() {
	return *this;
}
ostream &operator<<(ostream& out, Complex& c) {
	if(c.b==0)
	    out<<c.a;
	else
	    out<<c.a<<c.b<<"i";
	return out;
}
istream &operator>>(istream& in, Complex& c) {
	in >> c.a >> c.b ;
	return in;
}
int& Complex::operator[](int index) {
	if (index == 0)
		return a;
	else
		return b;
}
Complex &Complex::operator+=(Complex c1) {
	*this = add(c1);
	return *this;
}
Complex &Complex::operator-=(Complex c1) {
	*this = subtract(c1);
	return *this;
}
Complex &Complex::operator*=(Complex c1) {
	*this = multiply(c1);
	return *this;
}
Complex &Complex::operator++() {
	a ++;
	return *this;
}
Complex &Complex::operator--() {
	a --;
	return *this;
}
Complex operator+(Complex c1, Complex c2) {
	return c1.add(c2);
}
Complex operator-(Complex c1, Complex c2) {
	return c1.subtract(c2);
}
Complex operator*(Complex c1, Complex c2) {
	return c1.multiply(c2);
}


#include"Complex.h"
int main() {
	Complex first = Complex(3, 4) + Complex(2, -4)*Complex(3, -1);
	Complex second = Complex(4, 3) - Complex(5, 6);

	cout << "first=" << first << endl;
	cout << "second=" << second << endl;
	cout << "++first=" << ++first << endl;
	cout << "--second=" << --second << endl;

	system("pause");
}

