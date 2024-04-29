//
//  main.cpp
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


//Templated Print Function
template<class T>
void print(const T& t)
{
    std::cout << t << "" <<endl;
};


void testQuadraticAlgos()
{
    vector<double> data_1(15);
    iota(data_1.begin(), data_1.end(), -10);
    vector<double> data_2(15);
    iota(data_2.begin(), data_2.end(),1.75);
    Quadratic Quad(-2,-4,2);
    VectorAlgos valgo1(move(data_1), move(Quad));
    VectorAlgos valgo2(move(data_2), move(Quad));
    std::map<CalcType, double> res1 = valgo1.results();
    std::map<CalcType, double> res2 = valgo2.results();
    
    auto display_results = [] (std::map<CalcType, double> Results)
    {
            cout << "Results: " << endl << endl;
            cout << "Mean = " << Results.at(CalcType::MEAN) << endl;
            cout << "Std Dev = " << Results.at(CalcType::STD_DEV) << endl;
            cout << "Norm = " << Results.at(CalcType::NORM) << endl;
            cout << "Min = " << Results.at(CalcType::MIN) << endl;
            cout << "Max = " << Results.at(CalcType::MAX) << endl;
            cout << endl;
        
        //looped iterator....how to display results nicely?
        /*for (const auto& elem : Results)
        {
        cout << "key = " << static_cast<unsigned>(elem.first)
        << ", value = " << elem.second << endl;
        }
        cout << endl << endl;*/
        
    };
    display_results(res1);
    display_results(res2);

    
}

int main ()
{
   
    testQuadraticAlgos();
    
    return 0;
}




