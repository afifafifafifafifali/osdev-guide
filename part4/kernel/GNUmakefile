# Nuke built-in rules and variables.
override MAKEFLAGS += -rR

CC = /usr/local/cross-compiler/bin/x86_64-elf-gcc
LD = /usr/local/cross-compiler/bin/x86_64-elf-ld
# This is the name that our final kernel executable will have.
# Change as needed.
override KERNEL := kernel.elf

# Convenience macro to reliably declare user overridable variables.
define DEFAULT_VAR =
    ifeq ($(origin $1),default)
        override $(1) := $(2)
    endif
    ifeq ($(origin $1),undefined)
        override $(1) := $(2)
    endif
endef

# It is highly recommended to use a custom built cross toolchain to build a kernel.
# We are only using "cc" as a placeholder here. It may work by using
# the host system's toolchain, but this is not guaranteed.
$(eval $(call $(CC)))

# Same thing for "ld" (the linker).
$(eval $(call $(LD)))

# User controllable C flags.
$(eval $(call $(CC),CFLAGS,-g -O2 -pipe -Wall -Wextra))

# User controllable C preprocessor flags. We set none by default.
$(eval $(call $(CC),CPPFLAGS,))

# User controllable nasm flags.
$(eval $(call DEFAULT_VAR,NASMFLAGS,-F dwarf -g))

# User controllable linker flags. We set none by default.
$(eval $(call $(LD),LDFLAGS,))

# Internal C flags that should not be changed by the user.
override CFLAGS += \
    -std=gnu11 \
    -ffreestanding \
    -fno-stack-protector \
    -fno-stack-check \
    -fno-lto \
    -fno-pie \
    -fno-pic \
    -m64 \
    -march=x86-64 \
    -mabi=sysv \
    -mno-80387 \
    -mno-mmx \
    -mno-sse \
    -mno-sse2 \
    -mno-red-zone \
    -mcmodel=kernel

# Internal C preprocessor flags that should not be changed by the user.
override CPPFLAGS := \
    -I. \
    $(CPPFLAGS) \
    -MMD \
    -MP

# Internal linker flags that should not be changed by the user.
override LDFLAGS += \
    -nostdlib \
    -static \
     \
    -z max-page-size=0x1000 \
    -T linker.ld

# Check if the linker supports -no-pie and enable it if it does.

# Internal nasm flags that should not be changed by the user.
override NASMFLAGS += \
    -f elf64

# Use "find" to glob all *.c, *.S, and *.asm files in the tree and obtain the
# object and header dependency file names.
override CFILES := $(shell find -L . -type f -name '*.c')
override ASFILES := $(shell find -L . -type f -name '*.S')
override NASMFILES := $(shell find -L . -type f -name '*.asm')
override OBJ := $(CFILES:.c=.o) $(ASFILES:.S=.o) $(NASMFILES:.asm=.o)
override HEADER_DEPS := $(CFILES:.c=.d) $(ASFILES:.S=.d)

# Default target.
.PHONY: all
all: $(KERNEL)

limine.h:
	curl -Lo $@ https://github.com/limine-bootloader/limine/raw/trunk/limine.h

# Link rules for the final kernel executable.
$(KERNEL): $(OBJ)
	sudo $(LD) $(OBJ) $(LDFLAGS) -o $@

# Include header dependencies.
-include $(HEADER_DEPS)

# Compilation rules for *.c files.
%.o: %.c limine.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilation rules for *.S files.
%.o: %.S limine.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilation rules for *.asm (nasm) files.
%.o: %.asm
	nasm $(NASMFLAGS) $< -o $@

.PHONY: debug
debug: $(KERNEL)

%.o: %.c limine.h
	$(CC) $(CFLAGS) -g $(INTERNALCFLAGS) -c $< -o $@

# Remove object files and the final executable.
.PHONY: clean
clean:
	rm -rf $(KERNEL) $(OBJ) $(HEADER_DEPS)

.PHONY: distclean
distclean: clean
	rm -f limine.h
