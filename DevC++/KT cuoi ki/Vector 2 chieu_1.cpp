//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <iomanip>
using namespace std;
class Vector{
private:
    double x_, y_;
public:
    Vector(double x = 0, double y = 0);
    void print(int precision = 2, bool newLine = true);
    Vector& operator=(const Vector& v);    
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
};

int main(){
	Vector a(2.1, 1.0);
	Vector b(2, 0);
	Vector c(-1, 1.0);
	Vector d(2, -2);

	a = a + b;
	b = b - c;
	c += d;
	
	b.print();
	a.print();
	c.print();
	d.print();
	
	return 0;
}
Vector::Vector(double x, double y){
    x_ = x;
    y_ = y;
}
void Vector::print(int precision, bool newLine){
    if(newLine){
        std::cout<< fixed<< setprecision(precision)<<
        "("<<x_ <<", "<< y_<<")"<<endl;
    }
    else{
        std::cout<< fixed<< setprecision(precision)<<
        "("<<x_ <<", "<< y_<<")";
    }
} 
Vector& Vector::operator=(const Vector& v){
	x_ = v.x_;
	y_ = v.y_;
	return *this;	
}
Vector Vector::operator+(const Vector& v) const{
	Vector v1;
	v1.x_ = x_ + v.x_;
	v1.y_ = y_ + v.y_;
	return v1;
}
Vector Vector::operator-(const Vector& v) const{
	Vector v1;
	v1.x_ = x_ - v.x_;
	v1.y_ = y_ - v.y_;
	return v1;
}
Vector& Vector::operator+=(const Vector& v){
	x_ += v.x_;
	y_ += v.y_;
	return *this;
}
Vector& Vector::operator-=(const Vector& v){
	x_ -= v.x_;
	y_ -= v.y_;
	return *this;
}
