#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define int long long // to work with 64bit address

// Global variables
extern int debug;    // print the executed instructions
extern int assembly; // print out the assembly and source
extern int token;    // current token

// Instructions
enum { LEA ,IMM ,JMP ,CALL,JZ  ,JNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PUSH,
    OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
    OPEN,READ,CLOS,PRTF,MALC,MSET,MCMP,EXIT };

// Tokens and classes (operators last and in precedence order)
enum {Num = 128, Fun, Sys, Glo, Loc, Id,
    Char, Else, Enum, If, Int, Return, Sizeof, While,
    Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak};

// Fields of identifier
enum { Token, Hash, Name, Type, Class, Value, BType, BClass, BValue, IdSize };

// Types of variable/function
enum { CHAR, INT, PTR };

// Type of declaration
enum { Global, Local };

// Global pointers and variables
extern int *text;       // text segment
extern int *stack;      // stack
extern int *old_text;   // for dump text segment
extern char *data;      // data segment
extern int *idmain;

extern char *src;       // pointer to source code string
extern char *old_src;   // old source code string

extern int poolsize;    // default size of text/data/stack
extern int *pc, *bp, *stk, ax, cycle; // virtual machine registers

extern int *current_id; // current parsed ID
extern int *symbols;    // symbol table
extern int line;        // line number of source code
extern int token_val;   // value of current token (mainly for number)

extern int basetype;    // the type of a declaration, make it global for convenience
extern int expr_type;   // the type of an expression
extern int index_of_bp; // index of bp pointer on stack

#endif // GLOBALS_H