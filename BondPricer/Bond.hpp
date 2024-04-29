//
//  Bond.hpp
//  HW 7
//
//  Created by Christopher Alpert on 8/29/22.
//

#ifndef Bond_hpp
#define Bond_hpp

#include <stdio.h>
#include "ChronoDate.h"
#include "DayCounts.h"

#include <vector>


class Bond
{
public:
    //pmt_dates is the vector of coupon payment dates
    //The DaCount object is stored polymprphically
    Bond(double cpn_pmt, double face_value, const std::vector<ChronoDate>& pmt_dates, Thirty360 dc);
    
    //sett_date is the day the bond is exchanged for cash.
    //spot_rates are the market spot yield rates at each payment date
        //as seen as of the settlement date.
    double price(const ChronoDate& sett_date, const std::vector<double>& spot_rates); //*** Enter const or not const?
    
private:
    double cpn_pmt_, face_value_;
    std::vector<ChronoDate> pmt_dates_;
    Thirty360 dc_;   //Choose appropriate day count class
};

#endif /* Bond_hpp */
