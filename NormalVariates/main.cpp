//
//  main.cpp
//  HW 6
//
//  Created by Christopher Alpert on 8/23/22.
//

#include <iostream>
#include "Contaminated_Normal.hpp"


void testContNormal()
{
    double mean = 8;
    double sd_one = .2;
    double sd_two = .1;
    double alpha = .5;
    int seed = 300;
    int num_variates = 10;
    int elem_to_test = 3;
    ContaminatedNormal test(mean, sd_one, sd_two, alpha, seed, num_variates);
    //ContaminatedNormal();
    std::cout << elem_to_test <<"th element is " << test[elem_to_test - 1] << std::endl;
    std::cout <<"There are " << test.num_of_variates() << " variates total" << std::endl;
}
int main()
{
    testContNormal();
    return 0;
    
}
