//
//  Contaminated_Normal.hpp
//  HW 6
//
//  Created by Christopher Alpert on 8/23/22.
//

#ifndef CONTAMINATED_NORMAL_H
#define CONTAMINATED_NORMAL_H

#include<vector>
#include<exception>
#include<string>

class ContaminatedNormal
{
public:
    ContaminatedNormal(double mean, double sd_one, double sd_two, double alpha, int seed, int num_variates);    //Constructor
    ContaminatedNormal();    //Public member function - allows reset of variables

    

    double operator [](int k) const;
    int num_of_variates() const;    //returns total number of variants
    void generate();
    void generate(double mean, double sd_one, double sd_two, double alpha, int seed, int num_variates);

private:
    void check_volatilities_() const;     //Check volatilities, throw exception if needed
    double mean_, sd_one_, sd_two_;
    double alpha_;
    int seed_, num_variates_;
    std::vector<double> cont_norm_variates_;
    

};



#endif // !    CONTAMINATED_NORMAL_H
