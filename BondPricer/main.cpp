//
//  main.cpp
//  HW 7
//
//  Created by Christopher Alpert on 8/29/22.
//

#include <iostream>
#include <vector>
#include "ChronoDate.h"
#include "DayCounts.h"
#include "Bond.hpp"
#include <algorithm>
#include <iterator>
using std::transform;
using std::back_inserter;

using std::cout;
using std::endl;




void example()
{
    std::vector<ChronoDate> pmt_dates(7);
    const ChronoDate first_pmt_date{2022, 11, 14};
    unsigned i=0;
    cout << "Raw dates in schedule: " << endl;
    for (auto& date : pmt_dates)
    {
        ChronoDate pmt_date = first_pmt_date;
        pmt_dates[i] = (pmt_date.add_months(i*6));
        cout << date << " ";
        ++i;
    }
    
    cout << endl;
    
    std::transform(pmt_dates.begin(), pmt_dates.end(), pmt_dates.begin(),[](ChronoDate pmt_date){return pmt_date.weekend_roll();});
    
    
    cout << "Rolled dates: " << endl;
    for (auto& date : pmt_dates)
    {
        cout << date << " ";
        
    }
    cout << endl;
    
    auto day_count = Thirty360();

    Bond bond{50.0, 1000.0, pmt_dates, day_count };
    
    ChronoDate sett_date{2022, 9, 1};
    std::vector<double> rates{0.01, 0.015, 0.02, 0.025, 0.03, 0.035, 0.04};
    
    double bond_price = bond.price(sett_date, rates);
    cout << endl << "Total bond price = " << bond_price << endl;
}

int main()
{
    example();
    return 0;
}
