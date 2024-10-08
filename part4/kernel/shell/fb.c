#include "fb.h"
#include "eeqlmc2.h"  // Include custom math library
#include "../limine.h"
#include <stddef.h>

// Global framebuffer info
struct framebuffer_info fb_info;


// Limine framebuffer request
struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

// Initialize framebuffer
void fb_init() {
    if (framebuffer_request.response == NULL || framebuffer_request.response->framebuffer_count < 1) {
        return; // Handle error if framebuffer isn't available
    }

    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];
    fb_info.address = (uint32_t *)framebuffer->address;
    fb_info.width = framebuffer->width;
    fb_info.height = framebuffer->height;
    fb_info.pitch = framebuffer->pitch;
    fb_info.bpp = framebuffer->bpp;
}

// Clear the screen with a specific color
void fb_clear(uint32_t color) {
    for (uint64_t y = 0; y < fb_info.height; y++) {
        for (uint64_t x = 0; x < fb_info.width; x++) {
            fb_draw_pixel(x, y, color);
        }
    }
}

// Draw a pixel at a specific location
void fb_draw_pixel(uint64_t x, uint64_t y, uint32_t color) {
    if (x >= fb_info.width || y >= fb_info.height) {
        return; // Bounds check
    }

    uint64_t index = y * (fb_info.pitch / sizeof(uint32_t)) + x;
    fb_info.address[index] = color;
}

// Draw a rectangle using (x, y) as the top-left corner
void fb_draw_rect(uint64_t x, uint64_t y, uint64_t w, uint64_t h, uint32_t color) {
    for (uint64_t i = 0; i < h; i++) {
        for (uint64_t j = 0; j < w; j++) {
            fb_draw_pixel(x + j, y + i, color);
        }
    }
}

// Draw a line using Bresenham's algorithm
void fb_draw_line(int x0, int y0, int x1, int y1, uint32_t color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    
    int sx = sign(x1 - x0);
    int sy = sign(y1 - y0);

    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        fb_draw_pixel(x0, y0, color);
        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// Draw a gradient based on a base color and a factor
void fb_draw_gradient(uint32_t base_color, int factor) {
    for (uint64_t y = 0; y < fb_info.height; y++) {
        for (uint64_t x = 0; x < fb_info.width; x++) {
            int intensity = pow(x % factor, 2);  // Example use of pow
            uint32_t color = (base_color & 0xFF) * intensity;  // Scale color by intensity
            fb_draw_pixel(x, y, color);
        }
    }
}
