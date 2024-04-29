//
//  BlackScholes.hpp
//  HW 1
//
//  Created by Christopher Alpert on 7/9/22.
//

#ifndef BlackScholes_hpp
#define BlackScholes_hpp

#include <array>
#include <cmath>

//Define an alias named OptionData
using OptionData = std::array<double,5>;


enum PayoffType //Explicitly set phi = +1 or -1
{
    PUT = 1,
    CALL = -1,
};

//Define Black_Scholes Formula
double black_scholes_price(double strike, double spot, double rate, double sigma, double year_frac, int PayoffType, std::array<double,2> dee);

//Define dee_fcns
std::array<double,2> dee_fcns(double strike, double spot, double rate, double sigma, double year_frac);

//Define a function  norm_cdf
double norm_cdf(double x);
const double sqrt_two = std::sqrt(2); //define a constant sqrt(2)



//Define an overloaded black_scholes_price function
void black_scholes_price(OptionData& option_data, PayoffType, std::array<double,2> dee);


#endif
