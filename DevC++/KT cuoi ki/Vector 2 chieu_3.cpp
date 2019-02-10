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
    Vector(double x = 0, double y = 0);  // dã làm ? bài tru?c
    void print(int precision = 2, bool newLine = true); // dã làm ? bài tru?c
    void truncate(double length);
    bool isOrtho(const Vector& v) const;
    static float dot(const Vector& v1, const Vector& v2);
    static float cross(const Vector& v1, const Vector& v2);
    friend ostream& operator<<(ostream& os, const Vector& v); 
};

int main(){
	Vector a(2.1, 1.00);
	Vector b(-1, 2.1);
	Vector c(-1.2, 2.1);
	a.print();
	a.truncate(2);
	a.print();
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
void Vector::truncate(double length){
	x_ = x_ / length;
	y_ = y_ / length;
}
bool Vector::isOrtho(const Vector& v) const{
	if(x_*v.x_ + y_*v.y_ == 0)
		return true;
	return false;
}
float Vector::dot(const Vector& v1, const Vector& v2){
	return v1.x_*v2.x_ + v1.y_*v2.y_;
}
float Vector::cross(const Vector& v1, const Vector& v2){
	return v1.x_*v2.y_ - v1.y_*v2.x_;
}
ostream& operator<<(ostream& os, const Vector& v){
	os<< "("<< v.x_<<", "<< v.y_<< ")";
	return os;
}
