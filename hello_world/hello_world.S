.global _start
.align 2

_start:
    mov X0, #1
    adr X1, helloWorld
    mov X2, #13
    mov X16, #4
    svc 0

    mov X0, #0
    mov X16, #1

    svc 0


helloWorld: .ascii "Hello world"