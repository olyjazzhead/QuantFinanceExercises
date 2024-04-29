//
//  Vector.hpp
//  HW 5
//
//  Created by Christopher Alpert on 8/17/22.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <vector>
#include "Quadratic.h"
#include <map>

enum class CalcType
{
    MEAN,
    NORM,
    MAX,
    MIN,
    STD_DEV
};

class VectorAlgos
{
public:
    VectorAlgos(std::vector<double>&& data, Quadratic&& quad); //Constructor
    
    //public member functions
    std::map<CalcType, double> results();//, double norm, double min, double max, double StdDev) const;
    void resetCalc(std::vector<double>&& data, Quadratic&& quad);
    
    
private:
    //private member variables
    std::vector<double> data_;
    std::vector<double> image_;
    Quadratic quad_;
    std::map<CalcType, double> results_;
    
    
    //private member functions
    
    void calcMeanAndStdDev_();
    void calcNorm_();
    void calcMaxAndMin_();
    void runCalculations_();
};

void test();


#endif /* Vector_hpp */
