// Solivan Hiep
// HiepSolivan@csu.fullerton.edu
// @HiepSolivan
// Partners: @Kaleb16

//
// Program to calculate the date between two Gregorian dates.
//

#include "datediff_functions.h"

// Convert a Gregorian calendar date to a Julian day number
//
// Given a date of the form YYYY/MM/DD such as 12/25/2021, convert the
// Gregorian date to a Julian day number. The Julian day is the continuous
// count of days since the beginning of the Julian period, January 1, 4713 BCE.
// See https://en.wikipedia.org/wiki/Julian_day for more information.
//
// \param day The day of the month, valid values are 1-31
// \param month The month of the year, valid values are 1-12
// \param year The year, valid values are -4713 through 2436204
// returns the Julian day number
int JulianDay(int month, int day, int year) {
  // Fliegel & Van Flandern's algorithm is restated on the Wikipedia page with
  // some slight modifications. Below is a modestly modified line of code from
  // the US Naval Obervatory's NOVAS source code which calculates a Julian day
  // from a Gregorian date.
  // (See https://github.com/indigo-astronomy/novas/blob/master/src/lib/novas.c,
  // line 9200)
  // DONE: Update the return to return the calculated Julian Day.

  int julian_day = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
                   367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
                   3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  return julian_day;
}

// Return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  // DONE: Given two dates, find each date's Julian day using the JulianDay()
  // function. Return the difference between the end date and the start date.
  int start_julian_day{JulianDay(start_month, start_day, start_year)};
  int end_julian_day{JulianDay(end_month, end_day, end_year)};
  int julian_difference{end_julian_day - start_julian_day};

  return julian_difference;
}

void PrintDate(int month, int day, int year) {
  // DONE: Using std::cout, display the integers passed to the function
  // as a formatted date such as mm/dd/yyyy where mm is the month,
  // dd is the day, and yyyy is the year such as 12/25/2023.
  std::cout << month << "/" << day << "/" << year;
}
