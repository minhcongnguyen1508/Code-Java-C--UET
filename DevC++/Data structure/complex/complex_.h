#ifndef COMPLEX_H_
#define COMPLEX_H_
#include<iostream>
#include<cmath>
using namespace std;

class Complex{
	private:
		double real;
		double imag;
	public:
		Complex(){
			//Todo
		}	
		~Complex(){
			//Todo
		}
		double getReal() const {
			return real;
		}
		double getImag() const {
			return imag;
		}
		double getAbs(){
			return sqrt(real*real + imag*imag);
		}
		friend Complex& operator + (const Complex& c1, const Complex& c2);
		friend const Complex operator - (const Complex& c1, const Complex& c2);
		friend const Complex operator * (const Complex& c1, const Complex& c2);
		friend const Complex operator / (const Complex& c1, const Complex& c2);			
//		friend Complex& operator = (const Complex& c);
//		friend Complex input(Complex& c);
		friend istream& operator>>(istream& in, Complex& c);
		friend ostream& operator<<(ostream& out, const Complex& c);
};
Complex& operator + (const Complex& c1, const Complex& c2){
	Complex c;
	c.real = c1.real + c2.real;
	c.imag = c1.imag + c2.imag;
	return c;
}
const Complex operator - (const Complex& c1, const Complex& c2){
	Complex c;
	c.real = c1.real - c2.real;
	c.imag = c1.imag - c2.imag;
	return c;
}
const Complex operator * (const Complex& c1, const Complex& c2){
	Complex c;
	c.real = c1.real*c2.real - c1.imag*c2.imag;
	c.imag = c1.imag*c2.real + c2.imag*c1.real;
	return c;
}
const Complex operator / (const Complex& c1, const Complex& c2){
	Complex c;
	c.real = (c1.real*c2.real + c1.imag*c2.imag)/(c2.real*c2.real + c2.imag*c2.imag);
	c.imag = (c1.imag*c2.real - c2.imag*c1.real)/(c2.real*c2.real + c2.imag*c2.imag);
	return c;
}
//Complex input(Complex& c){
//	cin>> c.real>> c.imag;
//	return c;
//}
istream& operator>>(istream& in, Complex & c){
	in>> c.real;
	in>> c.imag;
//	return c;
}
ostream& operator<<(ostream& out,const Complex& c){
	if(c.imag < 0){
		out<< c.real<<" - "<< c.imag*(-1)<< ".i";
	}
	else{
		out<< c.real<<" + "<< c.imag<< ".i";
	}
}
#endif

//

