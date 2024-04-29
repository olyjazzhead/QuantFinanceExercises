//
//  main.cpp
//  HW 2
//
//  Created by Christopher Alpert on 7/12/22.
//




//MAIN FILE

#include <iostream>
#include "MyComplex.hpp"



int main()
{
    MyComplex cn1(4,5);
    MyComplex cn2(3,2);
    MyComplex cn3;
    cn3 = cn1 + cn2;
    cn1.print();
    cn2.print();
    cn3.print();
    std::cout << "radius is " << cn3.radius() << std::endl;
    std::cout << "theta is " << cn3.theta() << std::endl;
    std::cout << "real part is " << cn3.real() << std::endl;
    std::cout << "imaginary part is " << cn3.imag() << std::endl;
    std::cout << "Polar coordinates are " << cn3.radius() << " , " << cn3.theta() << std::endl;
    return 0;
    
}



