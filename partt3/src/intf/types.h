#include <stdbool.h>
#include <stdint.h>

#ifndef TYPES_H
#define TYPES_H

typedef signed char   int8;
typedef unsigned char uint8;

typedef signed short   int16;
typedef unsigned short uint16;

typedef signed int   int32;
typedef unsigned int uint32;

typedef signed long long   int64;
typedef unsigned long long uint64;

typedef char *string; //cs50

//unsigned int size_t; error
typedef __SIZE_TYPE__ size_t;

//we dont care
// typedef int bool;

#define low_16(address) (uint16)((address) & 0xFFFF)
#define high_16(address) (uint16)(((address) >> 16) & 0xFFFF)



#endif