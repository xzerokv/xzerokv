#include <xzkv.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void
xzkv_panic_(const char *file, int line, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);

    char buff[256];
    vsnprintf(BUFFSZ(buff), fmt, va);

    perror(buff);
    exit(-1);
}
