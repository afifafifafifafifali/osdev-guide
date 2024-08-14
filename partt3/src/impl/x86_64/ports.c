#include <stdint.h>

// Read a byte from the specified port
static inline uint8_t inportb(uint16_t port) {
    uint8_t result;
    __asm__ volatile ("inb %1, %0" : "=a"(result) : "dN"(port)); // we don't care asm code AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaaaaaaaa
    return result;
}

// Write a byte to the specified port
static inline void outportb(uint16_t port, uint8_t data) {
    __asm__ volatile ("outb %0, %1" : : "a"(data), "dN"(port));
}
