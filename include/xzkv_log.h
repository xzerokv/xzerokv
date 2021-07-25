#ifndef XZKV_LOG_H
#define XZKV_LOG_H

#include <stdint.h>

typedef enum
{
    XZKV_LOG_DEBUG   = 1,
    XZKV_LOG_INFO    = 2,
    XZKV_LOG_WARNING = 3,
    XZKV_LOG_ERROR   = 4,
    XZKV_LOG_FATAL   = 5,
}
xzkv_log_level_t;

#ifndef XZKV_LOG_C
extern
#endif
xzkv_log_level_t xzkv_min_log_level
#ifdef XZKV_LOG_C
= XZKV_LOG_DEBUG
#endif
;

#define xzkv_write_log__(level, lstr, fmt, ...) \
    ({                                                 \
        if (level >= xzkv_min_log_level)               \
            xzkv_write_log_(lstr, fmt, ##__VA_ARGS__); \
    })

#define xzkv_write_log_fl__(level, lstr, fmt, ...) \
    ({                                                                                        \
        xzkv_write_log__(level, lstr, fmt " [%s:%d]", ##__VA_ARGS__, __FILE_REL__, __LINE__); \
    })

#define xzkv_log_d__(fn, fmt, ...) fn(XZKV_LOG_DEBUG,   "D", fmt, ##__VA_ARGS__)
#define xzkv_log_i__(fn, fmt, ...) fn(XZKV_LOG_INFO,    "I", fmt, ##__VA_ARGS__)
#define xzkv_log_w__(fn, fmt, ...) fn(XZKV_LOG_WARNING, "W", fmt, ##__VA_ARGS__)
#define xzkv_log_e__(fn, fmt, ...) fn(XZKV_LOG_ERROR,   "E", fmt, ##__VA_ARGS__)
#define xzkv_log_f__(fn, fmt, ...) fn(XZKV_LOG_FATAL,   "F", fmt, ##__VA_ARGS__)

#define xzkv_log_d(fmt, ...) xzkv_log_d__(xzkv_write_log__, fmt, ##__VA_ARGS__)
#define xzkv_log_i(fmt, ...) xzkv_log_i__(xzkv_write_log__, fmt, ##__VA_ARGS__)
#define xzkv_log_w(fmt, ...) xzkv_log_w__(xzkv_write_log__, fmt, ##__VA_ARGS__)
#define xzkv_log_e(fmt, ...) xzkv_log_e__(xzkv_write_log__, fmt, ##__VA_ARGS__)
#define xzkv_log_f(fmt, ...) xzkv_log_f__(xzkv_write_log__, fmt, ##__VA_ARGS__)

#define xzkv_log_dfl(fmt, ...) xzkv_log_d__(xzkv_write_log_fl__, fmt, ##__VA_ARGS__)
#define xzkv_log_ifl(fmt, ...) xzkv_log_i__(xzkv_write_log_fl__, fmt, ##__VA_ARGS__)
#define xzkv_log_wfl(fmt, ...) xzkv_log_w__(xzkv_write_log_fl__, fmt, ##__VA_ARGS__)
#define xzkv_log_efl(fmt, ...) xzkv_log_e__(xzkv_write_log_fl__, fmt, ##__VA_ARGS__)
#define xzkv_log_ffl(fmt, ...) xzkv_log_f__(xzkv_write_log_fl__, fmt, ##__VA_ARGS__)

void
xzkv_log_init();

void
xzkv_write_log_(const char *level, const char *fmt, ...);

#endif
