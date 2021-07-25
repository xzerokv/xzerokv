#define  XZKV_LOG_C
#include <xzkv.h>

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define XZKV_LOG_BUFF_SIZE  16 MiB
#define XZKV_TIME_BUFF_SIZE 32 B

static char
xzkv_log_buff[XZKV_LOG_BUFF_SIZE] = {0};

static char
xzkv_time_buff[XZKV_TIME_BUFF_SIZE] = {0};

#define ZKV_LOG_TIME_FMT "%Y-%m-%d %H:%M:%S"

static FILE *
xzkv_log_file = NULL;

void
xzkv_log_init()
{
    //TODO: config
    xzkv_log_file = stderr;
}

void
xzkv_write_log_(const char *level, const char *fmt, ...)
{
    assert(level && fmt);

    va_list va;
    va_start(va, fmt);

    vsnprintf(BUFFSZ(xzkv_log_buff), fmt, va);
    va_end(va);

    if (xzkv_log_file)
    {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        strftime(BUFFSZ(xzkv_time_buff), ZKV_LOG_TIME_FMT, tm_info);

        fprintf(xzkv_log_file, "%s [ %zd ] %s %s\n",
                xzkv_time_buff, xzkv_get_pid(), level, xzkv_log_buff);
    }
    else
        xzkv_panic("not implemented");
}
