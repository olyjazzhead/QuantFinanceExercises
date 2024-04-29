//
//  MyComplex.cpp
//  HW 2
//
//  Created by Christopher Alpert on 7/14/22.
//

#include "MyComplex.hpp"


//IMPLEMENTATION FILE
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::exit;

//Constructor Implementation
MyComplex::MyComplex(double x, double y) : real_(x), imag_(y)
{
    reset(x,y);
    calcPolar_();
}

//Default Constructor Implementation
MyComplex::MyComplex() : real_(0), imag_(0)
{
    reset(0,0);
    calcPolar_();
}

//Implement Print Function
void MyComplex::print() const
{
    if (imag_ >= 0)
    {
        cout << "The complex number is " <<  real_ << "+" << imag_ << "i" << endl;
    }
    
    else
    {
        cout << "The complex number is " <<  real_ << "" << imag_ << "i" << endl;
    }
    
}

//Implement Acessors
double MyComplex::real() const
{
    return real_;
}
double MyComplex::imag() const
{
    return imag_;
}
double MyComplex::radius() const
{
    return radius_;
}
double MyComplex::theta() const
{
    return theta_;
}

//Implement Mutators
void MyComplex::reset(double x, double y)
{
    real_ = x;
    imag_ = y;
}

//Implement operator overload
MyComplex MyComplex::operator + (const MyComplex& comp_numb) const
{
    MyComplex sum_comp_numb(real_ + comp_numb.real_, imag_ + comp_numb.imag_);
    
    return sum_comp_numb;
}

//Implement calcPolar_() function
void MyComplex::calcPolar_()
{
    radius_ = sqrt((real_ * real_) + (imag_ * imag_));
    theta_ = atan(imag_ / real_);

}
