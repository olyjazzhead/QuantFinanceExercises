//
//  Functions.cpp
//  HW 1
//
//  Created by Christopher Alpert on 7/4/22.
//

#include <iostream>
#include "Functions.h"

double norm_cdf(double x)
{
    double value_of_cdf  = (1 + erf(x/sqrt_two))/2; //cdf expressed in terms
                                                    //of erf
    return value_of_cdf;
}


