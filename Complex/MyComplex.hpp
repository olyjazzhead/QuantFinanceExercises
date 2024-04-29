//
//  MyComplex.hpp
//  HW 2
//
//  Created by Christopher Alpert on 7/14/22.
//

#ifndef MyComplex_hpp
#define MyComplex_hpp

#include <stdio.h>

//HEADER FILE

class MyComplex
{
public:
    //Constructor taking in two double arguments - real & imag
    MyComplex(double x, double y);
    
    //Default Constructor
    MyComplex();
    
    //Print Function that prints the complex number
    void print() const;
    
    //Accessors
    double real() const;
    double imag() const;
    double radius() const;
    double theta() const;
    
    //Mutators
    void reset(double x, double y);
    
    //Addition overloaded operator
    MyComplex operator +(const MyComplex& comp_numb) const;
    
private:
    //private calcpPolar function
    void calcPolar_();
    //real valued private members
    double real_;
    double imag_;
    double radius_;
    double theta_;
};


#endif /* MyComplex_hpp */
