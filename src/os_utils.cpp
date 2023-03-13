#include "os_utils.h"

#ifdef __linux__
#include <cstring>
#include <unistd.h>
#include <libgen.h>
#include <sys/syscall.h>
#else
#include <windows.h>
#endif

static const char * g_utils_version = "v1.0.0";

const char * os_utils_version()
{
    return g_utils_version;
}

long os_utils_tid()
{
#ifdef __linux__
    return syscall(SYS_gettid);
#else
    return static_cast<long>(GetCurrentThreadId());
#endif
}

const char * os_utils_file_name(const char * path, char * file, size_t len)
{
    if (nullptr == path || nullptr == file || '\0' == path[0])
        return nullptr;

#ifdef __linux__
    char * file_name = basename((char *)path);
    strncpy(file, file_name, len);
#else
    char tmp[OS_UTILS_FILE_MAX] = { 0 };
    char ext[OS_UTILS_FILE_MAX] = { 0 };
    _splitpath(path, NULL, NULL, tmp, ext);
    snprintf(file, len, "%s%s", tmp, ext);
#endif
    return file;
}
