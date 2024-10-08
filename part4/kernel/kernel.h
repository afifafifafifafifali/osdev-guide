#ifndef KERNEL_H
#define KERNEL_H

#include <stddef.h>
#include "limine.h"




extern void term_write(const char *string, size_t length);
extern void term_clear(void);

#endif
