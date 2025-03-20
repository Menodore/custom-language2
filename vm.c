#include "globals.h"

// Initialize global variables
int debug = 0;
int assembly = 0;
int token = 0;

int *text = NULL;
int *stack = NULL;
int *old_text = NULL;
char *data = NULL;
int *idmain = NULL;

char *src = NULL;
char *old_src = NULL;

int poolsize = 0;
int *pc = NULL, *bp = NULL, *stk = NULL, ax = 0, cycle = 0;

int *current_id = NULL;
int *symbols = NULL;
int line = 0;
int token_val = 0;

int basetype = 0;
int expr_type = 0;
int index_of_bp = 0;