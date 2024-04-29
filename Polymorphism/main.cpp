//
//  main.cpp
//  HW4
//
//  Created by Christopher Alpert on 7/27/22.
//

#include <iostream>
#include <memory>
#include <utility>
#include <typeinfo>

#include "Shapes.hpp"
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

void shape_shifter_tests();


int main() {
    shape_shifter_tests();
    
    return 0;
}

void shape_shifter_tests()
{
    
    
    /*Circle unit_circle(1);
    Rectangle two_by_four(2,4);
    std::cout << "Area of circle is " << unit_circle() << std::endl;
    std::cout << "Area of rectangle is " << two_by_four() << std::endl;*/
    
    auto unit_cir = make_unique<Circle>(1);
    ShapeShifter circle_shift(std::move(unit_cir), 4);
    cout << "circle_shift(2.0) = " << circle_shift.multiplier(2) << endl;
    
    
    /*auto two_by_four = make_unique<Rectangle>(2,4);
    ShapeShifter rect_shift(std::move(two_by_four));
    cout << "rect_shift(2.0) = " << rect_shift.multiplier(2) << endl;*/
    
}
