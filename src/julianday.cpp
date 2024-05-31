/*
 * julianday.cpp
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */


#include "julianday.h"



julianday::julianday(int _year, short _month, float _day, short _hour, short _minute, float _second, bool _verbose) :
           timestamp(_year, _month, _day, _hour, _minute, _second, _verbose)
{
	jd_verbose = _verbose;

	jd_FLOATWIDTH		= 25;
	jd_FLOATPRECISION	= 9;

	jd_calculateJulianDay();

	return;
}
