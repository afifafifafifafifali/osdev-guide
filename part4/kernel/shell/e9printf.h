#pragma once

#include <stdarg.h>
#include <stddef.h>

#define printfch e9_putc
void e9_putc(char c);
void e9_print(const char *msg);
void e9_puts(const char *msg);
void e9_printf(const char *format, ...);