
MEMORY {
    BOOT (rx) : ORIGIN = 0x00000000, LENGTH = 2K
    RAM (rwx) : ORIGIN = 0x00000800, LENGTH = 62K
}

SECTIONS {
    .text : {
        *(.text)
        *(.text*)
    } > RAM
    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > RAM
    .data : {
        *(.data)
        *(.data*)
    } > RAM
    .bss : {
        *(.bss)
        *(.bss*)
    } > RAM
    .ctors : {
        __ctors_start = .;
        KEEP(*(.ctors))
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        __ctors_end = .;
    } > RAM
    .dtors : {
        KEEP(*(.dtors))
    } > RAM

    . = ORIGIN(RAM) + LENGTH(RAM);
    _sstack = .;
    _estack = . - 4K;
}