#include <time.h>

int year(){
    time_t tm;
	time(&tm);

	struct tm *date = localtime(&tm);

    int year = date->tm_year + 1900;

    return year;
}

int month(){
    time_t tm;
    time(&tm);

    struct tm *date = localtime(&tm);

    int month = date->tm_mon + 1;

    return month;
}

int day(){
    time_t tm;
    time(&tm);

    struct tm *date = localtime(&tm);

    int day = date->tm_mday;

    return day;
}
