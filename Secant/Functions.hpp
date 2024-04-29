//
//  Functions.hpp
//  HW 3.2
//
//  Created by Christopher Alpert on 7/26/22.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <iostream>
#include <limits>
#include <cmath>
//DECLARE PURE ABSTRACT BASE CLASS

class RealFunction
{
public:
    //virtual operator functor - returns the value of the function
    virtual double operator()(double x) const = 0;
    //Default Constructor
    virtual ~RealFunction() = default;
    
    
};


//POLYFUNCTION DERIVED CLASS

class PolyFunction : public RealFunction //PolyFunction is scoped within RealFunction
{
public:
    //Declare PolyFunction
    PolyFunction(double a, double b, double c, double d);
    virtual double operator()(double x) const override;
    
   
    
private:
    //Declare private member variables
    double a_;
    double b_;
    double c_;
    double d_;
    
};

//MIXFUNCTION DERIVED CLASS

class MixFunction : public RealFunction //MixFunction is scoped within RealFunction
{
public:
    //Declare MixFunction
    MixFunction(double a, double b, double c);
    virtual double operator()(double x) const override;
    
   
private:
    //Declare private member variables
    double a_;
    double b_;
    double c_;
    const double zero_ = std::sqrt(std::numeric_limits<double>::epsilon());
};

//DECLARE SECANT FUNCTION
double secant(const RealFunction& RealF, double x0, double x1, double tol, int maxIter);





#endif /* Functions_hpp */
