#include "globals.h"

// Define global variables
int *pc = NULL;       // program counter
int *bp = NULL;       // base pointer
int *stk = NULL;      // stack pointer
int ax = 0;           // accumulator
int cycle = 0;        // cycle counter

// Other global variables
int *text = NULL;     // text segment
int *old_text = NULL; // for dump text segment
char *data = NULL;    // data segment
char *src = NULL;     // pointer to source code string
char *old_src = NULL; // old source code string
int poolsize = 0;     // default size of text/data/stack
int line = 1;         // line number of source code
int token_val = 0;    // value of current token
int basetype = 0;     // the type of a declaration
int expr_type = 0;    // the type of an expression
int index_of_bp = 0;  // index of bp pointer on stack
int *current_id = NULL; // current parsed ID
int *symbols = NULL;  // symbol table
int debug = 0;        // print the executed instructions
int assembly = 0;     // print out the assembly and source
int token = 0;        // current token
