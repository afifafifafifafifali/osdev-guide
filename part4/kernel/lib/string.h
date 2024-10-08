#ifndef STRING_H
#define STRING_H
#include <stdbool.h>

#include <stddef.h>

size_t strlen(const char* s);
char* strcpy(char* destination, const char* source);
int strcmp(const char* str1, const char* str2);
void* reverse(char* s);
void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* ptr, int value, size_t num);

bool strEql(char *ch1, char *ch2);

#endif 
