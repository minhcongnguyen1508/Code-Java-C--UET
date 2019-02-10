//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
class Fraction {
    int a, b;
public:
    Fraction(int a_ = 1, int b_ = 1);
    friend ostream& operator<<(ostream& os, const Fraction& f);
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    void simplify();
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
};
int main(){
	Fraction a(2, -3);
	Fraction b(-3, -9);
	cout<< a+b<< endl<< a*b;
	
	return 0;
}
Fraction:: Fraction(int a_, int b_){
	a = a_;
	b = b_;
}
Fraction Fraction::operator+(const Fraction& f) const{
	Fraction x;
	x.a = a*f.b + b*f.a;
	x.b = b*f.b;
	x.simplify();
	return x;
}
Fraction Fraction::operator-(const Fraction& f) const{
	Fraction x;
	x.a = a*f.b - b*f.a;
	x.b = b*f.b;
	x.simplify();
	return x;
}
Fraction Fraction::operator*(const Fraction& f) const{
	Fraction x;
	x.a = a * f.a;
	x.b = b * f.b;
	x.simplify();
	return x;
}
Fraction Fraction::operator/(const Fraction& f) const{
	Fraction x;
	x.a = a * f.b;
	x.b = b * f.a;
	x.simplify();
	return x;
}
void Fraction::simplify(){
	int temp, tu, m;
	tu = a;
	m = b;
	while(m != 0){
		temp = tu % m;
		tu = m;
		m = temp;
	}
	a /= tu;
	b /= tu;
}
ostream& operator<<(ostream& os, const Fraction& f){
	if(f.b == 0)
		os<< "invalid";
	else if(f.a > 0 && f.b < 0){
		os<< "-"<< f.a<< "/"<< -f.b;
	}
	else if(f.a < 0 && f.b < 0){
		os<< -f.a<<"/"<< -f.b;
	}
	else{
		os<< f.a<<"/"<< f.b;
	}
	return os;
}

