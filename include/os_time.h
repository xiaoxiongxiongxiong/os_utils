#ifndef _OS_UTILS_TIME_H_
#define _OS_UTILS_TIME_H_

#include "os_utils.h"
#include <stdint.h>

// 系统时间
typedef struct _os_time_t
{
    int year;        // 年
    int month;       // 月
    int day;         // 日
    int hour;        // 时
    int minute;      // 分
    int second;      // 秒
    int millisecond; // 毫秒
} os_time_t;

OS_API_BEGIN

/*
* os_time_us
* @brief  获取时间,精确到微秒
* @return 微秒
*/
OS_UTILS_API int64_t os_time_us();

/*
* os_time_ms
* @brief  获取时间,精确到ms
* @return 时间戳
*/
OS_UTILS_API int64_t os_time_ms();

/*
* os_time_by_ms
* @brief  通过毫秒获取标准时间格式
* @param  ms  时间戳
* @return 标准时间格式
*/
OS_UTILS_API os_time_t os_time_by_ms(int64_t ms);

OS_API_END

#endif
