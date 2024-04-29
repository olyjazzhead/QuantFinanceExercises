//
//  Vector.cpp
//  HW 5
//
//  Created by Christopher Alpert on 8/17/22.
//
#include <iostream>
#include "Vector.hpp"
#include "Quadratic.h"
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>


using std::vector;
using std::map;
using std::transform;
using std::back_inserter;
using std::cout;
using std::endl;
using std::accumulate;
using std::move;


//// Print Template
template<class T>
void print(const T& t)
{
    cout << t << "" << endl;
};

//Constructor Initialization
VectorAlgos::VectorAlgos(std::vector<double>&& data, Quadratic&& quad) : data_(data), quad_(quad)
{
    map<CalcType, double> results_;
    runCalculations_();
    results();
    resetCalc(move(data_), move(quad_));
    
}



//map<CalcType, double> results;

void VectorAlgos::runCalculations_()
{
    transform(data_.begin(), data_.end(), back_inserter(image_), quad_);
    calcMeanAndStdDev_();
    calcNorm_();
    calcMaxAndMin_();
}
    

void VectorAlgos::calcMeanAndStdDev_()
{
    //Calculate Mean
    double sum = (accumulate(image_.begin(), image_.end(), 0));
    auto mean = sum/image_.size();
    //cout << "mean is " << mean << endl;
    results_.emplace(CalcType::MEAN, mean);
    
    
    //Calculate StdDev
    
    
    auto sdElem =  [mean] (double x)    //Lambda function returns (x - mean)^2
    {
        return (x - mean) * (x - mean);
    };
    vector<double> sdElems(image_.size());  // initate a vector sdElems of size image_size
    transform(image_.begin(), image_.end(), sdElems.begin(), sdElem);   //populate sdElems with value of lambda
    double StdDev = sqrt((accumulate(sdElems.begin(), sdElems.end(), 0.0))/image_.size());  //compute stdDev
    //cout << "StdDev is " << StdDev << endl;
    results_.emplace(CalcType::STD_DEV, StdDev);
}

void VectorAlgos :: calcNorm_()
{
    double norm = sqrt(inner_product(image_.begin(), image_.end(), image_.begin(), 0.0));
    //cout << "norm is " << norm << endl;
    results_.emplace(CalcType::NORM, norm);
}

void VectorAlgos :: calcMaxAndMin_()
{
    auto min = min_element(image_.begin(), image_.end());
    auto max = max_element(image_.begin(), image_.end());
    //cout << "Min and Max are " << *min << " and " << *max << endl;
    results_.emplace(CalcType::MAX, *max);
    results_.emplace(CalcType::MIN, *min);
}

std::map<CalcType, double> VectorAlgos::results()
{
   
    return results_;
}

void VectorAlgos::resetCalc(vector<double>&& data_, Quadratic&& quad_)
{
    data_.clear();
    quad_ = Quadratic(0,0,0);
}

/*Chairpushedin = false(julian = sad)
chairpushedin = (leverdown: : standup<pushin>)
Chairpushedin = true = Julian happy

Juliantummy(McChicken) = false
Juliantummy(McChicken) = False(false) = happy
Julian Tummy Happy = Clean Car?!?!*/

/*{CalcType::MEAN, Results.at(0)},
{CalcType::NORM, Results.at(1)},
{CalcType::MAX, Results.at(2)},
{CalcType::MIN, Results.at(3)},
{CalcType::STD_DEV, Results.at(4)},*/
