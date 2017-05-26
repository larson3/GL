nasm -f elf -l hello.lst hello.asm
ld -o hello.out hello.o -melf_i386
