//
//  main.cpp
//  HW 3.2
//
//  Created by Christopher Alpert on 7/26/22.
//

#include <iostream>
#include "Functions.hpp"
int main()
{
    double first_guess = -1;
    double second_guess = 1;
    double a = 25;
    double b = 57;
    double c = 4;
    double d = -1;
    
    PolyFunction poly_first_iter(a,b,c,d);
    //MixFunction mix_first_iter(a,b,c);
    secant(poly_first_iter, first_guess, second_guess, .00001, 100);
    //secant(mix_first_iter, first_guess, second_guess, .00001, 100);
    return 0;
}
