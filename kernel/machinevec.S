//----------------------------------------------------------------
//
//  4190.307 Operating Systems (Spring 2026)
//
//  Project #2: System calls
//
//  March 19, 2026
//
//  Jin-Soo Kim (jinsoo.kim@snu.ac.kr)
//  Systems Software & Architecture Laboratory
//  Dept. of Computer Science and Engineering
//  Seoul National University
//
//----------------------------------------------------------------

.globl machinevec
.align 4
machinevec:
        // if a7 == 1, misa, else if a7 == 2, reset.
        li t0, 1
        beq a7, t0, misa_service
        li t0, 2
        beq a7, t0, reset_service

        // else, return -1 for unknown service
        li a0, -1
        j done

misa_service:
        csrr a0, misa
        j done

reset_service:
        li t0, 0x100000
        li t1, 0x7777
        sw t1, 0(t0)
        // if we reach here, reset failed
        li a0, -1
        j done

done:
        // advance mepc past the ecall instruction (4 bytes)
        csrr t0, mepc
        addi t0, t0, 4
        csrw mepc, t0
        mret
