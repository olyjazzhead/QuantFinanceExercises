#include "Shapes.hpp"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::unique_ptr;


//ShapeShifter Class Implementation

//**Constructor Initialization
ShapeShifter::ShapeShifter(unique_ptr<Shape> shape , const double area) : shape_(std::move(shape)), area_(area) {}


//**multiplier implementation
double ShapeShifter::multiplier(double x)
{
    shape_-> operator()();
    cout << "shape_ is type " << typeid().name() << endl;
    return   area_ * x;
}




//Rectangle Function Implementation

//**Constructor Initialization
Rectangle::Rectangle(double length, double height) :length_(length), height_(height) {}
    

double Rectangle::operator()() const
{
    return length_ * height_;
}



//Circle Function Implementation

//Constructor Initialization
Circle::Circle(double radius) :radius_(radius), pi_(3.14159265359) {}

double Circle::operator()() const
{
    return pi_ * radius_ * radius_;
}





