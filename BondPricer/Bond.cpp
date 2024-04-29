//
//  Bond.cpp
//  HW 7
//
//  Created by Christopher Alpert on 8/29/22.
//

#include "Bond.hpp"
#include "DayCounts.h"
#include "ChronoDate.h"
#include <numeric>
#include <iterator>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;



//Initalize Constructor
Bond::Bond(double cpn_pmt, double face_value, const std::vector<ChronoDate>& pmt_dates, Thirty360 dc): cpn_pmt_{cpn_pmt}, face_value_{face_value}, pmt_dates_{pmt_dates}, dc_{dc} {}

//price(.) public member function
double Bond::price(const ChronoDate& sett_date, const std::vector<double>& spot_rates)

{
    std::vector<double> disc_cpn_pmts;  //Create vector disc_cpn_pmts
    disc_cpn_pmts.reserve(spot_rates.size());   //Adjusts size to accomodate spot_rates if necessary
    
    auto calc_df = [this, &sett_date](double rate, const ChronoDate& pmt_date)
    {
        return exp(-rate * (dc_.year_fraction(sett_date, pmt_date)));
    };
    
    auto iter = pmt_dates_.begin();
    int i = 0;
    for (auto& rate : spot_rates)
    {
        disc_cpn_pmts.push_back(cpn_pmt_ * calc_df(rate, *iter));
        cout << "payment " << i +1 << " is "  << disc_cpn_pmts[i] << endl;
        ++iter;
        ++i;
        
    }
    double bond_price = std::accumulate(disc_cpn_pmts.begin(), disc_cpn_pmts.end(),0.0);
    
    cout << "bond price before face value " << bond_price << endl;
    
    bond_price += face_value_ * calc_df(spot_rates[6], pmt_dates_[6]);
    
    cout << "bond price of face value " << face_value_ * calc_df(spot_rates[6], pmt_dates_[6]) << endl;
    
    return bond_price;
    

}
