//
//  Contaminated_Normal.cpp
//  HW 6
//
//  Created by Christopher Alpert on 8/23/22.
//

#include "Contaminated_Normal.hpp"
#include "VolatilitiesException.h"
#include "OperatorException.hpp"

#include <vector>
#include <random>
#include <iostream>


using std::mt19937_64;
using std::normal_distribution;
using std::cout;
using std::endl;
using std::vector;

template<class T>
void print(const T& t)
{
       std::cout << t << " ";
};

//Main Constructor
ContaminatedNormal::ContaminatedNormal(double mean, double sd_one, double sd_two, double alpha, int seed, int num_variates) : mean_(mean), sd_one_(sd_one), sd_two_(sd_two), alpha_(alpha), seed_(seed), num_variates_(num_variates)
{
    check_volatilities_();
    generate(mean_, sd_one_, sd_two_, alpha_, seed_, num_variates_);
    //num_of_variates();
    
}

//Default Constructor

ContaminatedNormal::ContaminatedNormal() : mean_(0), sd_one_(0), sd_two_(0), alpha_(0), seed_(0), num_variates_(0)
{
    generate();
    cout << "All numbers set to zero" << endl;
}

int ContaminatedNormal::num_of_variates() const
{
    //cout<< endl << "num of variates = " << num_variates_ << endl;
    return num_variates_;
}

double ContaminatedNormal::operator [] (int k) const
{
    if (k < 0)
    {
        throw OperatorException();
    }
    return cont_norm_variates_.at(k);
}

void ContaminatedNormal :: generate(double mean, double sd_one, double sd_two, double alpha, int seed, int num_variates)
{
    check_volatilities_();


    mt19937_64 mtre(seed);    //Initiate seed with engine. Random number generation
    //cout << "Look at 1st few numbers in MT sequence: " << endl;
    //cout << mtre() << " " << mtre() << " " << mtre() << endl;

    normal_distribution<> nsNormal1(mean_, sd_one_);     //Generate normal distribution using mtre w/ mean and sigma one
    //cout << "Look at 1st few numbers in standard normal 1 sequence: " << endl;
    //cout << nsNormal1(mtre) << " " << nsNormal1(mtre) << " " << nsNormal1(mtre) << endl;
    
    normal_distribution<> nsNormal2(mean_, sd_two_);     //Generate normal distribution using mtre w/ mean and sigma one
    //cout << "Look at 1st few numbers in standard normal 2 sequence: " << endl;
    //cout << nsNormal2(mtre) << " " << nsNormal2(mtre) << " " << nsNormal2(mtre) << endl;
    
    vector<double> ns1NormalVariates;
    vector<double> ns2NormalVariates;
    //vector<double> cont_norm_variates_;
    int numDraws = num_variates_;
    for(int i=0; i<numDraws; ++i)
    {
        ns1NormalVariates.push_back(nsNormal1(mtre));
        ns2NormalVariates.push_back(nsNormal2(mtre));
        cont_norm_variates_.push_back((1-alpha_)*ns1NormalVariates.at(i) + alpha_*ns2NormalVariates.at(i));
        

    }
    cout << "Numbers in standard contNormal sequence: " << endl;
    for (auto& elem : cont_norm_variates_)
    {
        print(elem);
    }
    
    
}
  
//Reset variables
void ContaminatedNormal :: generate()
    {
    mean_ = 0;
    sd_one_=0;
    sd_two_=0;
    alpha_=0;
    seed_=0;
    num_variates_=0;
    cont_norm_variates_.clear();
    }
    
    
void ContaminatedNormal :: check_volatilities_() const
{
    
    if (sd_one_  < 0 || sd_two_ < 0)
    {
       throw VolatilitiesException();
    }
    
    else if (sd_one_ == sd_two_)
    {
        throw VolatilitiesException();
    }
    
    
}


