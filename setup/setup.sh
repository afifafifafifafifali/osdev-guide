# nasm and qemu
sudo apt-get install nasm
sudo apt-get install qemu
sudo apt-get install qemu-kvm
sudo apt-get install grub-pc
sudo apt-get install grub-common
sudo apt-get install xorriso

# GCC cross compiler for i386 systems (might take quite some time, prepare food)

sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install bison
sudo apt-get install flex
sudo apt-get install libgmp3-dev
sudo apt-get install libmpc-dev
sudo apt-get install libmpfr-dev
sudo apt-get install texinfo

#cURL (needed to clone some required files)
sudo apt-get install curl

export PREFIX="/usr/local/64elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"

mkdir /tmp/src
cd /tmp/src
curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.39.tar.gz
tar xf binutils-2.39.tar.gz
mkdir binutils-build
cd binutils-build
../binutils-2.39/configure --target=$TARGET  --with-sysroot --disable-nls --disable-werror --prefix=$PREFIX 
sudo make all install 2>&1 | tee make.log

cd /tmp/src
curl -O https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.gz
tar xf gcc-12.2.0.tar.gz
mkdir gcc-build
cd gcc-build
echo Configure: . . . . . . .
../gcc-12.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-language=c,c++ --without-headers
echo MAKE ALL-GCC:
sudo make all-gcc
echo MAKE ALL-TARGET-LIBGCC:
sudo make all-target-libgcc
echo MAKE INSTALL-GCC:
sudo make install-gcc
echo MAKE INSTALL-TARGET-LIBGCC:
sudo make install-target-libgcc
echo HERE U GO MAYBE:
ls /usr/local/i386elfgcc/bin
export PATH="$PATH:/usr/local/i386elfgcc/bin"
