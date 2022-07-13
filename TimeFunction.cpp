#include "TimeFunction.h"

TimeFunction::TimeFunction()
{

}

TimeFunction::~TimeFunction()
{

}

void TimeFunction::get_time_ms(QString *timeOut)
{
    struct timeval tv;
    struct tm* ptm;
    char time_string[40];
    char time_string2[40];
    long milliseconds;

    gettimeofday(&tv, NULL);
    ptm = localtime (&(tv.tv_sec));
    milliseconds = tv.tv_usec / 1000;
    strftime (time_string, sizeof(time_string), "%Y_%m_%d_%H_%M_%S", ptm);
    snprintf (time_string2, sizeof(time_string2), "%s_%03ld", time_string, milliseconds);
    (*timeOut)=QString(QLatin1String(time_string2));
}
