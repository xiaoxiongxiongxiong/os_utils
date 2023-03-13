#ifndef _OS_UTILS_H_
#define _OS_UTILS_H_

#include <stdio.h>

#ifdef __linux__
#define OS_UTILS_FILE_MAX 256   // 文件名最大长度
#define OS_UTILS_PATH_MAX 4096  // 文件路径最大长度
#define OS_UTILS_DISK_SEP '/'   // 路径分隔符
#else
#define OS_UTILS_FILE_MAX 260   // 文件名最大长度
#define OS_UTILS_PATH_MAX 260   // 文件路径最大长度
#define OS_UTILS_DISK_SEP '\\'  // 路径分隔符
#endif

#if defined(WIN32) || defined(_WIN32)
#if defined(OS_UTILS_API_EXPORT)
#define OS_UTILS_API __declspec(dllexport)
#else
#define OS_UTILS_API __declspec(dllimport)
#endif
#else
#define OS_UTILS_API
#endif

#ifdef __cplusplus
#define OS_API_BEGIN extern "C" {
#define OS_API_END }
#else
#define OS_API_BEGIN
#define OS_API_END
#endif

OS_API_BEGIN

/*
* os_utils_version
* @brief   获取版本号
* @return  版本号
*/
OS_UTILS_API const char * os_utils_version();

/*
* os_utils_tid
* @brief   获取当前线程id
* @return  线程id
*/
OS_UTILS_API long os_utils_tid();

/*
* os_utils_file_name
* @brief   获取文件名
* @param   path  完整路径名
* @param   file  输出文件名
* @param   len   输出文件名长度
* @return  文件名
*/
OS_UTILS_API const char * os_utils_file_name(const char * path, char * file, size_t len);

OS_API_END

#endif
