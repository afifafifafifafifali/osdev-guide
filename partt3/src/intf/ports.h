#include <stdint.h>

// Read a byte from the specified port
static inline uint8_t inportb(uint16_t port);
// Write a byte to the specified port
static inline void outportb(uint16_t port, uint8_t data);