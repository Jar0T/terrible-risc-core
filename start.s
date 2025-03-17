.section .text
.global _start

.global callConstructors
.extern callConstructors

_start:
    la sp, _sstack
    call callConstructors
    call main
    j .
