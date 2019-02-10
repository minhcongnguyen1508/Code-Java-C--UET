//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <iomanip>
using namespace std;
class Vector {
    double x_, y_;
public:
    Vector(double x = 0, double y = 0);  // dã làm ? bài 1
    void print(int precision = 2, bool newLine = true); // dã làm ? bài 1
    Vector operator+(double s) const;    
    Vector operator-(double s) const;
    Vector operator*(double s) const;
    Vector operator/(double s) const;
    Vector& operator+=(double s);    
    Vector& operator-=(double s);
    Vector& operator*=(double s);
    Vector& operator/=(double s);
};

int main(){
	Vector a(2.0, -1.0);
	Vector b(3.0, -2);
	Vector c(2.4, -1.1);

	a = a + 2;
	a.print();
	b = c * 2;
	b.print();
	b = b/2;
	b.print();
	c += 2.5;
	c.print();
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
Vector Vector::operator+(double s) const{
	Vector v1;
	v1.x_ = s + x_;
	v1.y_ = s + y_;
	return v1;
}
Vector Vector::operator-(double s) const{
	Vector v1;
	v1.x_ = x_ - s;
	v1.y_ = y_ - s;
	return v1;
}
Vector Vector::operator*(double s) const{
	Vector v1;
	v1.x_ = s * x_;
	v1.y_ = s * y_;
	return v1;
}
Vector Vector::operator/(double s) const{
	Vector v1;
	v1.x_ = x_ / s;
	v1.y_ = y_ / s;
	return v1;
}
Vector& Vector::operator+=(double s){
	x_ += s;
	y_ += s;
	return *this;
}
Vector& Vector::operator-=(double s){
	x_ -= s;
	y_ -= s;
	return *this;
}
Vector& Vector::operator*=(double s){
	x_ *= s;
	y_ *= s;
	return *this;
}
Vector& Vector::operator/=(double s){
	x_ /= s;
	y_ /= s;
	return *this;
}
