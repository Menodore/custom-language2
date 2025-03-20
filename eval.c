#include "globals.h"
#include "functions.h"


int eval() {
    int op, *tmp;
    cycle = 0;
    while (1) {
        cycle ++;
        op = *pc++; // get next operation code

        // print debug info
        if (debug) {
            printf("%lld> %.4s", cycle,
                   & "LEA ,IMM ,JMP ,CALL,JZ  ,JNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PUSH,"
                   "OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,"
                   "OPEN,READ,CLOS,PRTF,MALC,MSET,MCMP,EXIT"[op * 5]);
            if (op <= ADJ)
                printf(" %lld\n", *pc);
            else
                printf("\n");
        }
        if (op == IMM)       {ax = *pc++;}                                     // load immediate value to ax
        else if (op == LC)   {ax = *(char *)ax;}                               // load character to ax, address in ax
        else if (op == LI)   {ax = *(int *)ax;}                                // load integer to ax, address in ax
        else if (op == SC)   {ax = *(char *)*stk++ = ax;}                       // save character to address, value in ax, address on stack
        else if (op == SI)   {*(int *)*stk++ = ax;}                             // save integer to address, value in ax, address on stack
        else if (op == PUSH) {*--stk = ax;}                                     // push the value of ax onto the stack
        else if (op == JMP)  {pc = (int *)*pc;}                                // jump to the address
        else if (op == JZ)   {pc = ax ? pc + 1 : (int *)*pc;}                   // jump if ax is zero
        else if (op == JNZ)  {pc = ax ? (int *)*pc : pc + 1;}                   // jump if ax is not zero
        else if (op == CALL) {*--stk = (int)(pc+1); pc = (int *)*pc;}           // call subroutine
        //else if (op == RET)  {pc = (int *)*stk++;}                              // return from subroutine;
        else if (op == ENT)  {*--stk = (int)bp; bp = stk; stk = stk - *pc++;}      // make new stack frame
        else if (op == ADJ)  {stk = stk + *pc++;}                                // add esp, <size>
        else if (op == LEV)  {stk = bp; bp = (int *)*stk++; pc = (int *)*stk++;}  // restore call frame and PC
        else if (op == LEA)  {ax = (int)(bp + *pc++);}                         // load address for arguments.

        else if (op == OR)  ax = *stk++ | ax;
        else if (op == XOR) ax = *stk++ ^ ax;
        else if (op == AND) ax = *stk++ & ax;
        else if (op == EQ)  ax = *stk++ == ax;
        else if (op == NE)  ax = *stk++ != ax;
        else if (op == LT)  ax = *stk++ < ax;
        else if (op == LE)  ax = *stk++ <= ax;
        else if (op == GT)  ax = *stk++ >  ax;
        else if (op == GE)  ax = *stk++ >= ax;
        else if (op == SHL) ax = *stk++ << ax;
        else if (op == SHR) ax = *stk++ >> ax;
        else if (op == ADD) ax = *stk++ + ax;
        else if (op == SUB) ax = *stk++ - ax;
        else if (op == MUL) ax = *stk++ * ax;
        else if (op == DIV) ax = *stk++ / ax;
        else if (op == MOD) ax = *stk++ % ax;

        else if (op == EXIT) { printf("exit(%lld)", *stk); return *stk;}
        else if (op == OPEN) { ax = open((char *)stk[1], stk[0]); }
        else if (op == CLOS) { ax = close(*stk);}
        else if (op == READ) { ax = read(stk[2], (char *)stk[1], *stk); }
        else if (op == PRTF) { tmp = stk + pc[1]; ax = printf((char *)tmp[-1], tmp[-2], tmp[-3], tmp[-4], tmp[-5], tmp[-6]); }
        else if (op == MALC) { ax = (int)malloc(*stk);}
        else if (op == MSET) { ax = (int)memset((char *)stk[2], stk[1], *stk);}
        else if (op == MCMP) { ax = memcmp((char *)stk[2], (char *)stk[1], *stk);}
        else {
            printf("unknown instruction:%lld\n", op);
            return -1;
        }
    }
}

