#!/bin/bash

set -e
# Ensure the script is run as root
if [ "$EUID" -ne 0 ]; then
    echo "Please run as root"
    exit 1
fi

show_menu() {
    echo "Select an operation:"
    echo "1) make only"
    echo "2)  run only"
    echo "3) hdd run"
   echo "5) build toolschain"
    echo "4) Exit"
}

# Main script execution
while true; do
    show_menu
    read -p "Enter choice [1-4]: " choice

    case $choice in
        1)
            make clean && make 2<&1 | tee makebuild.log
            ;;
        2)
            make run shitos.iso
            ;;
        3)
            make run shitos.hdd
            ;;
        4)
            echo "BYE EEEEEEEEEEEEEEEEEEEEEEEE"
            exit 0
            ;;
        5) 
            echo "Downloading built-in toolchain"
            cd /usr/local/
            wget https://newos.org/toolchains/x86_64-elf-7.1.0-Linux-x86_64.tar.xz
            echo "Extracting..."
            tar -xvf x86_64-elf-7.1.0-Linux-x86_64.tar.xz
            mv x86_64-elf-7.1.0-Linux-x86_64 cross-compiler
            echo "tools That are in the compiler:
            x86_64-elf-addr2line  x86_64-elf-elfedit    x86_64-elf-gcc-ranlib  x86_64-elf-ld       x86_64-elf-readelf
    x86_64-elf-ar         x86_64-elf-g++        x86_64-elf-gcov        x86_64-elf-ld.bfd   x86_64-elf-size
    x86_64-elf-as         x86_64-elf-gcc        x86_64-elf-gcov-dump   x86_64-elf-nm       x86_64-elf-strings
    x86_64-elf-c++        x86_64-elf-gcc-7.1.0  x86_64-elf-gcov-tool   x86_64-elf-objcopy  x86_64-elf-strip
    x86_64-elf-c++filt    x86_64-elf-gcc-ar     x86_64-elf-gdb         x86_64-elf-objdump
    x86_64-elf-cpp        x86_64-elf-gcc-nm     x86_64-elf-gprof       x86_64-elf-ranlib"
        ;;
        *)
            echo "Invalid option"
            ;;

    esac
done