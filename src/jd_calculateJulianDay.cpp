/*
 * jd_calculateJulianDay.cpp
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */

#include <math.h>		// floor()
#include <iostream>		// std::cout
#include <iomanip>		// precision formatters


#include "julianday.h"



void julianday::jd_calculateJulianDay(void)
{
	int		B, M, Y;

	M = ts_getMonth();
	Y = ts_getYear();



	if((M == 1) || (M == 2) ){
		M += 12;
		Y--;
	}

	//	Different algorithms based on which calendar is used, Gregorian or Julian
	//
	if(!ts_getGregorianDate()){
		if(jd_verbose)
			std::cout << "Perform Meeus calculations based on Julian date..." << std::endl;
		//A	=	floor(jdnYear/100);
		B	=	0;
	}
	else if(ts_getGregorianDate()){
		if(jd_verbose)
			std::cout << "Perform Meeus calculations based on Gregorian date..." << std::endl;

		//	The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998.
		//A	=	floor(JDYear/100);
		//int B	=	2 - A + floor(A/4);
		B	=	2 - (floor(ts_getYear()/100.)) + floor((floor(ts_getYear()/100.))/4.);

	}

	//
	//	Calculate the jdn according to p.61 (7.1) in Jean Meeus Astronomical Algorithms Second Edition published in 1998.
	//	I keep a separate variable, jdnJdnNoon, for the start of the jdn. I believe it will be useful for calculating
	//	sunrise and sunsets later in the project.
	//
	jd_julianDay =		floor(365.25 * (Y + 4716.))
					+	floor(30.6001 * (M + 1.))
					+	ts_getDay() + B - 1524.5;

	//jdnJdnNoon += 0.5;

	if(jd_verbose)
		std::cout << "      Julian Day (JD): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDay << std::endl;

/*
	//
	// Calculate the fraction of the day
	//
	jdnJulianDay += (((jdnHour - jdnTz) + (jdnMinute / 60.) + (jdnSecond / 3600.) ) / 24.);

	//if(jdnVerbose)
		//cout	<< "      Julian Day Number (jdn): " << setw(30) << setprecision(15) << setfill(' ') << jdnGetJdnJulianDay() << endl;

	//
	// Calculating Julian Century according to p.163 in Jean Meeus Astronomical Algorithms Second Edition published in 1998.
	//
	jdnJulianCentury		= ((jdnJulianDay - jdnJ2000) / 36525.);
	jdnJulianCenturyNoon	= ((jdnJdnNoon - jdnJ2000) / 36525.);

	jdnJulianMillennia		= ((jdnJulianDay - jdnJ2000) / 365250.);
	jdnJulianMillenniaNoon	= ((jdnJdnNoon - jdnJ2000) / 365250.);

	*/

	return;
}
