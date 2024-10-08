#pragma once
#include <stddef.h>
#include <stdint.h>

// Struct to represent a point
struct point {
    size_t X;
    size_t Y;
};

// Function to compute power
int pow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

// Function to get the absolute value
int abs(int num) {
    return num < 0 ? -num : num;
}

// Function to get the sign of a number (-1 for negative, 0 for zero, 1 for positive)
int sign(int num) {
    return (num > 0) ? 1 : ((num < 0) ? -1 : 0);
}
