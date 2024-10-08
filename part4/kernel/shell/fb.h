#pragma once
#include <stdint.h>
#include <stddef.h>
#include "../limine.h"
// Framebuffer information structure
struct framebuffer_info {
    uint32_t *address;
    uint64_t width;
    uint64_t height;
    uint64_t pitch;
    uint16_t bpp;
};

// Limine framebuffer request structure
extern struct limine_framebuffer_request framebuffer_request;

// Function declarations
void fb_init();                        // Initializes the framebuffer
void fb_clear(uint32_t color);         // Clears the framebuffer with a given color
void fb_draw_pixel(uint64_t x, uint64_t y, uint32_t color);  // Draws a pixel at (x, y)
void fb_draw_rect(uint64_t x, uint64_t y, uint64_t w, uint64_t h, uint32_t color);  // Draws a rectangle
void fb_draw_line(int x0, int y0, int x1, int y1, uint32_t color);  // Draws a line between two points
void fb_draw_gradient(uint32_t base_color, int factor);  // Draws a gradient using math functions
