



#include <iostream>		// for cout
#include <stdlib.h>		// for exit()

#include "timestamp.h"



timestamp::timestamp(int _year, short _month, float _day, short _hour, short _minute, float _second, bool _verbose)
{
	ts_year 	= _year;
	ts_month	= _month;
	ts_hour		= _hour;
	ts_minute	= _minute;
	ts_day		= _day;
	ts_second	= _second;
	ts_verbose	= _verbose;

	ts_parseDate();

	return;
}




void timestamp::ts_parseDate(void)
{
	//	We assume a valid Gregorian date, otherwise this is changed in the below switch{...}/if{...}-statements
	ts_validDate		= true;
	ts_gregorianDate	= true;


	//	Default is no leap year
	ts_isLeap	= false;
	if(ts_year > 1582){
		if( ((ts_year % 4) == 0) && (((ts_year % 100) != 0) || ((ts_year % 400) == 0))){
			if(ts_verbose)
				std::cout << ts_year << " is a Leap year :-)" << std::endl;

			ts_isLeap	= true;
		}
		else{
			if(ts_verbose)
				std::cout << ts_year << " is not Leap year!" << std::endl;

			ts_isLeap	= false;
		}
	}


	//	If we're in 1582, check for valid date. There are ten missing dates this year as we went from
	//	using the Julian calendar to be using the Gregorian calendar.
	if(ts_year == 1582 && ts_month == 10){
		switch((int)ts_day){
		case 1:
		case 2:
		case 3:
		case 4:		ts_gregorianDate = false;
					break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:	std::cout << std::endl << "No such date!\n Exiting..." << std::endl;
					ts_validDate = false;
					exit(-1);
					break;
		default:	break;
		}
	}
	else if(ts_year == 1582 && ts_month < 10){
		ts_gregorianDate = false;

		if(ts_verbose)
			std::cout << std::endl << "Year == 1582 and month is less than 10." << std::endl;
	}
	else if(ts_year < 1582){
		ts_gregorianDate = false;

		if(ts_verbose)
			std::cout << std::endl << "Year is less than 1582." << std::endl;
	}

	//calendar_types{proleptic_julian, julian, gregorian};

	if(ts_gregorianDate){
		ts_calendar_type = calendar_types::gregorian;

		std::cout << "Gregorian" << std::endl;
	}

	else if(!ts_gregorianDate && ts_year >= 4 && ts_month >= 3){
		ts_calendar_type = calendar_types::julian;
		std::cout << "Julian" << std::endl;
	}

	else{
		ts_calendar_type = calendar_types::proleptic_julian;
		std::cout << "Proleptic julian" << std::endl;
	}


}



void timestamp::ts_calculateWeekday(void)
{
	//ts_weekday = weekdays::monday;
}
