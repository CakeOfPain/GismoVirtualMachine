#ifndef GTYPES_h
#define GTYPES_h

#include <stdint.h>

union GValue;

typedef union GValue {
    uint64_t u;
    int64_t  i;
    double   f;
    
} GValue;

#endif