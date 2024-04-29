#include "ChronoDate.h"

ChronoDate::ChronoDate(int year, unsigned month, unsigned day) :
	date_{ date::year{year} / date::month{month} / date::day{day} },
	serial_date_{ date::sys_days(date_).time_since_epoch().count() }
{
	if (!date_.ok())		// std::chrono member function to check if valid date
	{
		//std::exception e("ChronoDate constructor: Invalid date.");
		//throw e;
	}

	reset_serial_date_();
}

ChronoDate::ChronoDate(const Date& ymd) :date_{ ymd }
{
	if (!date_.ok())		// std::chrono member function to check if valid date
	{
		//std::exception e("ChronoDate constructor: Invalid year_month_day input.");
		//throw e;
	}

	reset_serial_date_();
}

ChronoDate::ChronoDate() :date_{ date::year(1970), date::month{1}, date::day{1} }
{
	reset_serial_date_();
}

// chrono::year can be cast to int
// See https://en.cppreference.com/w/cpp/chrono/year/operator_int
int ChronoDate::year() const
{
	return static_cast<int>(date_.year());
}

// chrono::month can be cast to unsigned
// Note this is different from chrono::year (int)
// See https://en.cppreference.com/w/cpp/chrono/month/operator_unsigned
unsigned ChronoDate::month() const
{
	return static_cast<unsigned>(date_.month());
}

// chrono::day can be cast to unsigned
// Note this is different from chrono::year (int)
// See https://en.cppreference.com/w/cpp/chrono/day/operator_unsigned
unsigned ChronoDate::day() const
{
	return static_cast<unsigned>(date_.day());
}

int ChronoDate::serial_date() const
{
	//	return date::sys_days(date_).time_since_epoch().count();
	return serial_date_;
}

date::year_month_day ChronoDate::ymd() const
{
	return date_;
}

// START MODFICATIONS
// 
// MODIFIED ADD YEARS
// These now become the "production" versions:
ChronoDate& ChronoDate::add_years(int rhs_years)
{
	// Only last day of February is a problem
	date::year y{ static_cast<int>(date_.year()) + rhs_years };
	unsigned d = static_cast<unsigned>(date_.day());
	unsigned m = static_cast<unsigned>(date_.month());
	if (m == 2 && d == 29 && !y.is_leap()) d = 28;
	date_ = y / date::month(m) / date::day(d);

	// must be a valid date so no need to check for validity

	reset_serial_date_();

	return *this;
}

// MODIFIED ADD MONTHS
ChronoDate& ChronoDate::add_months(int rhs_months)
{
	if (rhs_months < 0)
		date_ -= date::months{ static_cast<unsigned>(-rhs_months) };
	else
		date_ += date::months{ static_cast<unsigned>(rhs_months) };

	unsigned d = static_cast<unsigned>(date_.day());
	if (d > 28)
	{
		switch (static_cast<unsigned>(date_.month()))
		{
		case 2: // February
			d = (date_.year()).is_leap() ? 29 : 28;
			break;
		case 4:  case 6: case 9: case 11: // Apr, Jun, Sep and Nov
			if (d == 31) d = 30;
			break;
		default:	// Jan, Mar, Jul, Aug, Oct and Dec: nothing to do
			break;
		}
	}
	date_ = date_.year() / date_.month() / date::day{ d };
	reset_serial_date_();

	return *this;
}

ChronoDate& ChronoDate::add_days(int rhs_days)
{
	// Note that adding days is handled differently, per Howard Hinnant.
	// See https://stackoverflow.com/questions/62734974/how-do-i-add-a-number-of-days-to-a-date-in-c20-chrono
	date_ = date::sys_days(date_) + date::days(rhs_days);

	if (!date_.ok())
	{
		//std::exception e("ChronoDate::ChronoDate::addDays(.): resulting date out of range.");
		//throw e;
	}

	reset_serial_date_();

	return *this;
}

// Iso_WEEKDAY
unsigned ChronoDate::iso_weekday() const
{
	date::weekday wd{ date::sys_days(date_) };
	return wd.iso_encoding(); // Mon =  1, ..., Sat = 6, Sun = 7
}

// ROLL OVER WEEKEND 
ChronoDate& ChronoDate::weekend_roll()
{
	date::weekday wd{ date::sys_days(date_) };
	date::month orig_mth{ date_.month() };

	unsigned wdn{ wd.iso_encoding() }; // Mon =  1, ..., Sat = 6, Sun = 7
	if (wdn > 5) date_ = date::sys_days(date_) + date::days(8 - wdn);

	// If eom, roll back:
	// Note: Need to handle January
	if (orig_mth < date_.month() || (orig_mth == date::December && date_.month() == date::January))
	{
		date_ = date::sys_days(date_) - date::days(3);
	}

	reset_serial_date_();	// must be a valid date so no need to check

	return *this;
}

unsigned ChronoDate::operator - (const ChronoDate& rhs) const
{
	//return (date::sys_days(date_).time_since_epoch()
	//	- date::sys_days(rhs.date_).time_since_epoch()).count();

	return this->serial_date_ - rhs.serial_date_;
}

// Not in date.h -- just use old operators
//std::strong_ordering ChronoDate::operator <=> (const ChronoDate& rhs) const
//{
//	return date_ <=> rhs.date_;
//}

bool ChronoDate::end_of_month() const
{
	return date_ == date_.year() / date_.month() / date::last;
}


int ChronoDate::days_in_month() const
{
	// See https://stackoverflow.com/questions/59418514/using-c20-chrono-how-to-compute-various-facts-about-a-date
	// Fact 5: Number of days in month (section)
	auto num_days_in_mth = date::sys_days{ date_.year() / date_.month() / date::last }
	- date::sys_days{ date_.year() / date_.month() / 1 } + date::days{ 1 };

	return num_days_in_mth.count();
}

bool ChronoDate::leap_year() const
{
	return date_.year().is_leap();
}

bool ChronoDate::operator == (const ChronoDate& rhs) const
{
	return serial_date_ == rhs.serial_date_;
}

bool ChronoDate::operator!=(const ChronoDate& rhs) const
{
	return serial_date_ != rhs.serial_date_;
}

bool ChronoDate::operator < (const ChronoDate& rhs) const
{
	return serial_date_ < rhs.serial_date_;
}

bool ChronoDate::operator > (const ChronoDate& rhs) const
{
	return serial_date_ > rhs.serial_date_;
}

bool ChronoDate::operator <= (const ChronoDate& rhs) const
{
	return serial_date_ <= rhs.serial_date_;
}

bool ChronoDate::operator >= (const ChronoDate& rhs) const
{
	return serial_date_ >= rhs.serial_date_;
}

void ChronoDate::reset_serial_date_()
{
	serial_date_ = date::sys_days(date_).time_since_epoch().count();
}


// This is a 'friend' of the ChronoDate class; also
// requires separate export keyword even though the 
// class declaration is export(ed).
std::ostream& operator << (std::ostream& os, const ChronoDate& rhs)
{
	os << rhs.ymd();
	return os;
}
