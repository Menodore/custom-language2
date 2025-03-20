#ifndef NEXT_H
#define NEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>  // For open(), close(), read()

// Instruction set (copied from main.c)
enum { LEA ,IMM ,JMP ,CALL,JZ  ,JNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PUSH,
       OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
       OPEN,READ,CLOS,PRTF,MALC,MSET,MCMP,EXIT };

// Token classes (copied from main.c)
enum {
  Num = 128, Fun, Sys, Glo, Loc, Id,
  Char, Else, Enum, If, Int, Return, Sizeof, While,
  Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak
};

// Identifier fields
enum { Token, Hash, Name, Type, Class, Value, BType, BClass, BValue, IdSize };

// External global variables
extern int token;
extern char *src, *old_src;
extern int *symbols, *current_id, token_val;
extern int line, assembly, *old_text, *text;

extern char *data;
// Function prototype
void next();

#endif
