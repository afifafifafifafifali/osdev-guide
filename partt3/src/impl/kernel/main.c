#include "print.h"
/*#include <stdarg.h>
#include <stddef.h>*/
#include "types.h"

void kernel_main() {
    
    int x = 6;
    int y = 3;
    int o = x * y;

    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_LIGHT_GREEN);
    print_str("Welcome to our 64-bit kernel!\n");
    print_str("This is the FAT FILE SYSTEM\n");
   // print_str(name);
   //printf("this is a %c\n", name);
   //print_int(ma);
   printf("output %d", o);
}
