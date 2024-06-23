#include "print.h"

void kernel_main() {
    // print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_LIGHT_GREEN);
    print_str("Welcome to our 64-bit kernel!\n");
    print_str("This is the FAT FILE SYSTEM");
}
