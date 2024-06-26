#pragma once

/*
	Copyright 2022 Daniel Hanson and Kenneth J Adams (BSD-3)

	Redistribution and use in source and binary forms,
	with or without modification, are permitted provided that
	the following conditions are met:

	1. Redistributions of source code must retain the above
	   copyright notice, this list of conditions and the following
	   disclaimer.

	2. Redistributions in binary form must reproduce the above
	   copyright notice, this list of conditions and the following
	   disclaimer in the documentation and/or other materials
	   provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	   contributors  may be used to endorse or promote products
	   derived from this software without specific prior written
	   permission.

	 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
	 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
	 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
	 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
	 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
	 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
	 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
	 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
	 OF SUCH DAMAGE.

*/

// #include <chrono>
# include "date.h"
//namespace date = std::chrono;
using Date = date::year_month_day;

//#include <compare>
#include <exception>
#include <iostream>

#include <cmath>

class ChronoDate
{
public:
	ChronoDate(int year, unsigned month, unsigned day);
	ChronoDate(const Date& ymd);
	ChronoDate();

	// Accessors:
	int year() const;
	unsigned month() const;
	unsigned day() const;
	int serial_date() const;
	date::year_month_day ymd() const;

	// Modifying member functions:
	ChronoDate& add_years(int rhs_years);
	ChronoDate& add_months(int rhs_months);
	ChronoDate& add_days(int rhs_days);
	ChronoDate& weekend_roll();

	// Operators
	unsigned operator - (const ChronoDate& rhs) const;
	
	// Not available in date.h preview
	// std::strong_ordering operator <=> (const ChronoDate& rhs) const;

	// Check state:
	bool end_of_month() const;
	int days_in_month() const;
	bool leap_year() const;
	unsigned iso_weekday() const;

	bool operator == (const ChronoDate& rhs) const;
	bool operator != (const ChronoDate& rhs) const;
	bool operator < (const ChronoDate& rhs) const;
	bool operator > (const ChronoDate& rhs) const;
	bool operator <= (const ChronoDate& rhs) const;
	bool operator >= (const ChronoDate& rhs) const;

	// friend operator so that we can output date details with cout
	friend std::ostream& operator << (std::ostream& os, const ChronoDate& rhs);

private:
	date::year_month_day date_;
	int serial_date_;

	void reset_serial_date_();
};