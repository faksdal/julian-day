




class timestamp{

	enum class calendar_types{proleptic_julian, julian, gregorian};

	int				ts_year;

	short			ts_month, ts_hour, ts_minute;

	float			ts_day, ts_second;

	bool			ts_isLeap;
	bool			ts_validDate, ts_gregorianDate;
	bool			ts_verbose;

	calendar_types	ts_calendar_type;


	void	ts_parseDate(void);
	void	ts_calculateWeekday(void);

protected:
	enum class weekdays	{sunday, monday, tuesday, wednesday, thursday, friday, saturday};

	weekdays			ts_weekday;


public:

	timestamp(void);
	timestamp(int _year, short _month, float _day, short _hour, short _minute, float _second, bool _verbose);

	int		ts_getYear(void)			{return ts_year;}
	short	ts_getMonth(void)			{return ts_month;}
	float	ts_getDay(void)				{return ts_day;}
	short	ts_getHour(void)			{return ts_hour;}
	short	ts_getMinute(void)			{return ts_minute;}
	float	ts_getSecond(void)			{return ts_second;}
	bool	ts_getLeap(void)			{return ts_isLeap;}
	bool	ts_getGregorianDate(void)	{return ts_gregorianDate;}

	calendar_types	ts_getCalendarType(void)	{return ts_calendar_type;}

};
