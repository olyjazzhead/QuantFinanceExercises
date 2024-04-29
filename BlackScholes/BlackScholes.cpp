//
//  Functions.cpp
//  HW 1
//
//  Created by Christopher Alpert on 7/9/22.
//

#include "BlackScholes.hpp"
#include <algorithm>

//Norm CDF Function
double norm_cdf(double x)
{
    double value_of_cdf  = (1 + erf(x/sqrt_two))/2; //cdf expressed in terms
                                                    //of erf
    return value_of_cdf;
}


//dee_functions
std::array<double,2> dee_fcns(double strike, double spot, double rate, double sigma, double year_frac)
{
    if (year_frac == 0)
    {
        double d12 = log(spot/strike);
        std::array<double,2> dee = {d12,d12};
        return dee;
    }
    
    else
    {
        double d1 = (log(spot/strike)+(rate*year_frac)+(.5*sigma*sigma*year_frac))/(sigma*sqrt(year_frac));
        double d2 = d1 - sigma * sqrt(year_frac);
        std::array<double,2> dee = {d1,d2};
        return dee;
    }
    
}

//Black-Scholes Function
double black_scholes_price(double strike, double spot, double rate, double sigma, double year_frac, int PayoffType, std::array<double,2> dee)
{
    if (strike && spot && rate && sigma && year_frac >= 0)
    {
        if (year_frac == 0)
        {
            double f0 = PayoffType*((spot * norm_cdf(PayoffType * dee[0]) - (strike * norm_cdf(PayoffType * dee[1]))));
            double option_price = std::max(0.0,f0);
            return option_price;
        }
        
        else
        {
            double f0 = exp(-rate*year_frac) * PayoffType * ((spot * exp(rate * year_frac) * norm_cdf(PayoffType * dee[0]) - (strike * norm_cdf(PayoffType * dee[1]))));
            double option_price = std::max(0.0,f0);
            return option_price;
        }
    }
    
    else
    {
        return std::nan("");
    }
}

//Black-Scholes Overloaded Function
void black_scholes_price(OptionData& option_data, int PayoffType, std::array<double,2> dee)
{
    black_scholes_price(option_data[0], option_data[1], option_data[2], option_data[3],option_data[4], PayoffType, dee);
}

    
    
    


