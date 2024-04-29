//
//  Functions.cpp
//  HW 3.1
//
//  Created by Christopher Alpert on 7/26/22.
//

#include "Functions.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::numeric_limits;



///POLYFUNCTION IMPLEMENTATION

//Constructor Implementation - PolyFunction
PolyFunction::PolyFunction(double a, double b, double c, double d) : a_(a), b_(b), c_(c), d_(d) {}

//Class Implementation - PolyFunction
double PolyFunction::operator()(double x) const
{
    return a_*x*x*x*x*x + b_*x*x*x + c_*x + d_;
}





////MIXFUNCTION IMPLEMENTATON

//Constructor Implementation - MixFunction
MixFunction::MixFunction(double a, double b, double c) :a_(a), b_(b), c_(c) {}

//Class Implementation - MixFunction
double MixFunction::operator()(double x) const
{
    if (x==0)
    {
        return numeric_limits<double>::quiet_NaN();
    }
    
    else
    {
        return (x*x + sin(a_*x + b_))/x + c_;
    }
}

//SECANT FUNCTION IMPLEMENTATION

double secant(const RealFunction& RealF, double x0, double x1, double tol, int maxIter)
{
    double fx0 = RealF(x0);
    double fx1 = RealF(x1);
    double x2 =0;
    
    
    for(int i=0; i < maxIter; ++i)
    
    {
        x2 = x1 - fx1*(x1 - x0)/(fx1 - fx0);
        if (std::abs(RealF(x2)) <= tol)
        {
            cout << "The answer is " << x2 << endl;
            return x2;
        }
        else
        {
            fx0 = fx1;
            fx1 = RealF(x2);
            x0 = x1;
            x1 = x2;
        }
    }
    
    cout << "Root is Not A Number" << endl;
    cout << RealF(x2) << endl;
    return numeric_limits<double>::quiet_NaN();
    //return RealF(2);
}


