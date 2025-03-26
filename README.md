# customC-Interpreter 
*A C Interpreter written in C with a recursive-descent parser that converts code to bytecode for execution.*

## How to run?
1. Compile using `make`
2. Run using `./main`
```
make
./main
```

---

## Resources Used

1. https://github.com/rswier/c4
2. https://github.com/lotabout/write-a-C-interpreter
3. https://github.com/tlaceby/guide-to-interpreters-series


---
## Features  
- Uses a **recursive-descent parser**  
- Converts code to **bytecode** and executes it  
- Implements a **stack-based virtual machine (VM)**  
- Supports basic **data types, function calls, and operations**  

---

## Data Type Representation  

Only **one** data type exists: `val`.  

```c
typedef struct val {
  long type;
  long data;
} val;
 ```
`type`: Defines the underlying primitive type.
`data`: Stores the actual value (directly for integers, as a pointer for other types).

---
## Project structure
|File |Description|
| --- | --- |
| `main.c` | Entry point of the interpreter |
| `globals.h` | Global variables, tokens, VM instructions, and data structures |
| `parser.h` | Recursive-descent parser for C code |
| `token.h` | Tokenizer implementation |
| `virtual.h` | Code for the stack-based VM operation as defined in `operations.h`|
| `operations.h` | Bytecode operations and their implementations |


---

##  Supported Types
-	**None Type**:Default type  
- **Integer Type**:Stores integer values  
- **String Type**:Stores string value  
- **List Type**:Represents lists  
- **Pointer Type**:Stores memory addresses  
- **Function Type**:Represents functions  
For more details, see `globals.h`.

---


## Virtual Machine Architecture  
As described in virtual.h  
### Stack  
The interpreter operates using two stacks:  

1. **Operations Stack**	:  Used for all VM operations, stores operands of type val  
2. **Call Stack	Stores** : return addresses and manages function scopes  

### Registers
1.`sp`: Stack top pointer  
2.`ax`:Auxiliary register (val type)  
3.`cs_sp`:Call stack top pointer  
4.`cs_bp`:Call stack base pointer  

---

# ByteCode Operations

## Bytecode Instructions

### **Control Flow Instructions**
| Opcode  | Description |
|---------|------------|
| `IMM`   | Load an immediate value into the `ax` register. |
| `JMP`   | Jump to the specified address. |
| `CALL`  | Call a function (push current instruction pointer onto the call stack and jump to function). |
| `JZ`    | Jump to a specific address if `ax == 0`. |
| `JNZ`   | Jump to a specific address if `ax != 0`. |

### **Function Call Instructions**
| Opcode  | Description |
|---------|------------|
| `ENT`   | Enter a new function scope (allocate stack space). |
| `ADJ`   | Adjust the stack pointer for local variables. |
| `LEV`   | Leave function scope and return to caller. |


### **Logical & Comparison Instructions**
| Opcode  | Description |
|---------|------------|
| `OR`    | Bitwise OR (`ax = stack_top or ax `). |
| `XOR`   | Bitwise XOR (`ax = stack_top ^ ax`). |
| `AND`   | Bitwise AND (`ax = stack_top & ax`). |
| `EQ`    | Check if equal (`ax = (stack_top == ax)`). |
| `NE`    | Check if not equal (`ax = (stack_top != ax)`). |
| `LT`    | Check if less than (`ax = (stack_top < ax)`). |
| `GT`    | Check if greater than (`ax = (stack_top > ax)`). |
| `LE`    | Check if less than or equal (`ax = (stack_top <= ax)`). |
| `GE`    | Check if greater than or equal (`ax = (stack_top >= ax)`). |
| `SHL`   | Bitwise shift left (`ax = stack_top << ax`). |
| `SHR`   | Bitwise shift right (`ax = stack_top >> ax`). |

### **Arithmetic Instructions**
| Opcode  | Description |
|---------|------------|
| `ADD`   | Addition (`ax = stack_top + ax`). |
| `SUB`   | Subtraction (`ax = stack_top - ax`). |
| `MUL`   | Multiplication (`ax = stack_top * ax`). |
| `DIV`   | Division (`ax = stack_top / ax`). |
| `MOD`   | Modulo (`ax = stack_top % ax`). |


### **Exit Instruction**
| Opcode  | Description |
|---------|------------|
| `EXIT`  | Terminate the program execution. |

---
# Grammar
1. program → statement  
2. statement → { statement } | if | while | func | return | expression  
3. if → "if" '(' expression ')' statement else 
4. else → ε | "else" statement  
5. while → "while" '(' expression ')' statement  
6. func → "func" id '(' ')' statement  
7. expression → var | math_op  
8. var → id "=" type  
9. type → list | string | num | id  
10. list → '[' list_entry ']'  
11. list_entry → type | type ',' list_entry  
12. string → *    
13. num → [0-9]*  
14. id → [a-zA-Z0-9_]*


