#include "funcall.h"
int date_allowed(char *date)
{
    int day,month,year;
    struct tm chosen={0},today={0};
    time_t now=time(NULL),chosen_time,today_time;
    double difference;

    if(sscanf(date,"%d-%d-%d",&day,&month,&year)!=3)
    {
        return 0;
    }
    chosen.tm_mday=day;
    chosen.tm_mon=month-1;
    chosen.tm_year=year-1900;
    chosen.tm_hour=12;
    chosen.tm_isdst=-1;
    chosen_time=mktime(&chosen);
    if(chosen_time==(time_t)-1 || chosen.tm_mday!=day || chosen.tm_mon!=month-1 || chosen.tm_year!=year-1900)
        return 0;
        struct tm *local=localtime(&now);
        if(local==NULL) 
	{
		return 0;
	}
        today=*local;
    today.tm_hour=12;
    today.tm_min=0;
    today.tm_sec=0;
    today_time=mktime(&today);
    difference=difftime(chosen_time,today_time)/86400.0;
    return difference>=0 && difference<3;
}
