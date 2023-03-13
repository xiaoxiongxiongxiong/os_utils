#ifndef _OS_UTILS_DIRECTORY_H_
#define _OS_UTILS_DIRECTORY_H_

#include "os_utils.h"

OS_API_BEGIN

/*
* os_directory_running
* @brief   获取程序工作路径
* @param   path     工作路径存放地址
* @param   len      缓冲长度
* @return  运行路径
*/
OS_UTILS_API const char * os_directory_running(char * path, size_t len);

/*
* os_directory_exist
* @brief   判断文件夹是否存在
* @param   path     文件夹名
* @return  0-存在 -1-不存在
*/
OS_UTILS_API int os_directory_exist(const char * path);

/*
* os_directroy_empty
* @brief   判断文件夹是否为空
* @param   path     文件夹名
* @return  0-空 -1-不空
*/
OS_UTILS_API int os_directroy_empty(const char * path);

/*
* os_directory_remove
* @brief   删除文件夹
* @param   path     文件夹名
* @return  0-成功 -1-失败
*/
OS_UTILS_API int os_directory_remove(const char * path);

/*
* os_directory_create
* @brief   创建文件夹
* @param   path     文件夹名
* @return  0-成功 -1-失败
*/
OS_UTILS_API int os_directory_create(const char * path);

OS_API_END

#endif
