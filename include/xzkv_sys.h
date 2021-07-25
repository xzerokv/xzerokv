#ifndef ZKV_SYS_H
#define ZKV_SYS_H

#include <unistd.h>

static inline ssize_t
xzkv_get_pid(void)
{
    return (ssize_t)getpid();
}

#define xzkv_panic(fmt, ...) \
    ({ xzkv_panic_(__FILE_REL__, __LINE__, fmt, ##__VA_ARGS__); })

void
xzkv_panic_(const char *file, int line, const char *fmt, ...);

#endif
