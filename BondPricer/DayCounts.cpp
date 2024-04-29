#include "DayCounts.h"

// *** Class Thirty360 ***
	// This is the **ISDA** 30/360  daycount.
	// See https://www.iso20022.org/15022/uhb/mt565-16-field-22f.htm and
	// http://kalotay.com/SupportingDocumentation/BondOAS/daycounts.html (30/360 ISDA)

double Thirty360::year_fraction(const ChronoDate& date1, const ChronoDate& date2) const
{
	return static_cast<double>(dateDiff_(date1, date2)) / 360.0;
}

unsigned Thirty360::dateDiff_(const ChronoDate& date1, const ChronoDate& date2) const
{
	unsigned d1, d2;
	d1 = date1.day();
	d2 = date2.day();

	if (d1 == 31) d1 = 30;

	// Actual rule is conditioned on d1 being 30 *or* 31,
	// but the case of 31 was already adjusted in the previous command
	if ((d2 == 31) && (d1 == 30)) d2 = 30;

	return 360 * (date2.year() - date1.year()) + 30 * (date2.month() - date1.month()) + d2 - d1;
}

// *** Class Act365 ***
double Act365::year_fraction(const ChronoDate& date1, const ChronoDate& date2) const
{
	return (date2 - date1) / 365.0;
}
