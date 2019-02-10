//
# include <iostream>
# include <algorithm>
# include <string>
# include <cmath>
using namespace std;
class Complex {
    double a, b;
public:
    Complex(double a_ = 0, double b_ = 0);
    friend ostream& operator<<(ostream& os, const Complex& f);
    Complex operator+(const Complex& f) const;
    Complex operator-(const Complex& f) const;
    Complex operator*(const Complex& f) const;
    Complex operator/(const Complex& f) const;
    double modulus() const;
    bool operator==(const Complex& f) const;
    bool operator!=(const Complex& f) const;
};
int main(){
	Complex a(2, 3);
	Complex b(3, 4);
	cout<< a<<endl;

	a = a*b;
	
	cout<< a<<endl;
	return 0;
}
Complex::Complex(double a_, double b_){
	a = a_;
	b = b_;
}
ostream& operator<<(ostream& os, const Complex& f){
	if(f.a != 0 && f.b != 0){
		if(f.b > 0 && f.b != 1)
			os<< f.a<< "+"<< f.b<<"i";
		else if(f.b < 0 && f.b != -1)
			os<< f.a<< "-"<< abs(f.b)<< "i";
		else if(f.b > 0 && f.b == 1)
			os<< f.a<< "+"<< "i"; 
		else if(f.b < 0 && f.b == -1)
			os<< f.a<< "-"<< "i"; 
	}
	else if(f.a == 0 && f.b != 0){
		os << f.b<< "i";
	}
	else
		os<< f.a;

	return os;
}
Complex Complex:: operator+(const Complex& f) const{
	Complex x;
	x.a = a + f.a;
	x.b = b + f.b;
	return x;
}
Complex Complex:: operator-(const Complex& f) const{
	Complex x;
	x.a = a - f.a;
	x.b = b - f.b;
	return x;
}
Complex Complex:: operator*(const Complex& f) const{
	Complex x;
	x.a = a*f.a - b*f.b;
	x.b = a*f.b + b*f.a;
	return x;
}
Complex Complex:: operator/(const Complex& f) const{
	Complex x;
	x.a = (a*f.a + b*f.b)/(f.a*f.a + f.b*f.b);
	x.b = (b*f.a - a*f.b)/(f.a*f.a + f.b*f.b);
	return x;
}
bool Complex::operator==(const Complex& f) const{
	if(a == f.a && b == f.b)
		return true;
	return false;
}
bool Complex::operator!=(const Complex& f) const{
	if(a != f.a || b != f.b)
		return true;
	return false;
}
double Complex::modulus() const{
	return sqrt(a*a + b*b);
}
