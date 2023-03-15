#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"

#define PRINT_GMTIME(stream)                                                                      \
    {                                                                                             \
        std::time_t t = std::time(NULL);                                                          \
        std::tm *utc_now = std::gmtime(&t);                                                       \
        fprintf(stream, "[%02d:%02d:%02d] ", utc_now->tm_hour, utc_now->tm_min, utc_now->tm_sec); \
    }

#define LOG_ERROR(...)                           \
    {                                            \
        fprintf(stdout, KRED);                   \
        PRINT_GMTIME(stdout);                    \
        fprintf(stdout, "ERROR - " __VA_ARGS__); \
        fprintf(stdout, KNRM "\n");              \
    }

#define LOG_INFO(...)                           \
    {                                           \
        fprintf(stdout, KGRN);                  \
        PRINT_GMTIME(stdout);                   \
        fprintf(stdout, "INFO - " __VA_ARGS__); \
        fprintf(stdout, KNRM "\n");             \
    }

#ifdef DEBUG
#define LOG_DEBUG(...)                           \
    {                                            \
        fprintf(stdout, KYEL);                   \
        PRINT_GMTIME(stdout);                    \
        fprintf(stdout, "DEBUG - " __VA_ARGS__); \
        fprintf(stdout, KNRM "\n");              \
    }

#define ASSERT(expression)                                              \
    {                                                                   \
        if (!expression) {                                              \
            LOG_ERROR("Failed assertion at %s:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
    }

#include <cerrno>
#define LOG_ERRNO LOG_DEBUG("(%s)", strerror(errno));
#else  // NDEBUG
#define LOG_DEBUG(...) \
    {}
#define ASSERT(expression) \
    {}
#define LOG_ERRNO \
    {}
#endif  // DEBUG

#endif  // _LOGGER_HPP_
