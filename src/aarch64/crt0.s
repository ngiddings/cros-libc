
.section .text
.extern uinit
.extern main
.type _start, "function"
.global _start
_start:
   stp x0, x1, [sp, #-16]!
   stp x2, x3, [sp, #-16]!
   bl    uinit
   ldp x2, x3, [sp], #16
   ldp x0, x1, [sp], #16
   bl    main
   mov x0, #4
   svc #0
_stop:
   b _stop

//char "/init\0"
init:
   .string "/uinit\0"


// argv {init, 0}
.p2align 2
argv:
   .long init
   .long 0

