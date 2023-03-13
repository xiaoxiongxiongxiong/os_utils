#include "os_time.h"
#include <ctime>

#ifdef __linux__
#include <unistd.h>
#include <sys/time.h>
#else
#include <windows.h>
#endif

int64_t os_time_us()
{
#ifdef __linux__
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    return static_cast<int64_t>(tv.tv_sec * 1000000 + tv.tv_usec);
#else
    FILETIME ft;
    int64_t t;
    GetSystemTimeAsFileTime(&ft);
    t = (int64_t)ft.dwHighDateTime << 32 | ft.dwLowDateTime;
    return t / 10 - 11644473600000000; /* Jan 1, 1601 */
#endif
}

int64_t os_time_ms()
{
    return os_time_us() / 1000;
}

os_time_t os_time_by_ms(const int64_t ms)
{
    os_time_t otv = {};
    time_t t = static_cast<time_t>(ms / 1000);
    tm * tv = localtime(&t);
    if (nullptr != tv)
    {
        otv.year = tv->tm_year + 1900;
        otv.month = tv->tm_mon + 1;
        otv.day = tv->tm_mday;
        otv.hour = tv->tm_hour;
        otv.minute = tv->tm_min;
        otv.second = tv->tm_sec;
        otv.millisecond = static_cast<int>(ms % 1000LL);
    }

    return otv;
}
