//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
class Complex{
private:
    double a, b;
public:
    Complex(double x = 0, double y = 0){
    	a = x;
    	b = y;
	};
    friend ostream& operator<<(ostream& os, const Complex& f);
    Complex operator+(const Complex& f) const;
    Complex operator-(const Complex& f) const;
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    float get_a(){
    	return a;
	}
	float get_b(){
		return b;
	}
};
ostream& operator<<(ostream& os, const Complex& f){
    if(f.a == 0 && f.b != 0) os<<fixed << setprecision(2)<< f.b<<".i";
    else if(f.a != 0 && f.b == 0) os<<fixed << setprecision(2)<< f.a;
    else if(f.a != 0 && f.b < 0) os<< fixed << setprecision(2)<<f.a << "-"<< abs(f.b)<< ".i";
    else if(f.a != 0 && f.b > 0) os<<fixed << setprecision(2)<< f.a << "+"<< f.b<< ".i";
    else if(f.a == 0 && f.b == 0) os<< 0.00;
    return os;
}
Complex& Complex::operator+=(const Complex& c)
{
	a += c.a;
	b += c.b;
    return  *this;
}
Complex& Complex::operator-=(const Complex& c)
{
	Complex f(a, b);
	f.a -= c.a;
	f.b -= c.b;
    return f;
}

Complex& Complex::operator-=(const Complex& c)
{
	a -= c.a;
	b -= c.b;
    return *this;
}
Complex Complex::operator+(const Complex& f) const
{
	Complex c(a,b);
	c.a += f.a;
	c.b += f.b;
	return c;
}
Complex Complex::operator-(const Complex& f) const
{
	return Complex(a - f.a, b - f.b);
}
int main(){
	 Complex x(6, 6);
	 Complex y(1, -4);

	 x -= y;

	 
	 cout << fixed << setprecision(2) << x<<endl;

	return 0;
}

