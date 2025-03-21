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

## 🛠️ Supported Types
-	**None Type**:Default type  
-**Integer Type**:Stores integer values  
-**String Type**:Stores string value  
-**List Type**:Represents lists  
-**Pointer Type**:Stores memory addresses  
-**Function Type**:Represents functions  
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
| `LEA`   | Load effective address (not implemented). |
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

### **Memory Load/Store Instructions**
| Opcode  | Description |
|---------|------------|
| `LI`    | Load an integer from memory into `ax` (not implemented). |
| `LC`    | Load a character from memory into `ax` (not implemented). |
| `SI`    | Store an integer from `ax` into memory (not implemented). |
| `SC`    | Store a character from `ax` into memory (not implemented). |
| `PUSH`  | Push `ax` onto the stack. |

### **Logical & Comparison Instructions**
| Opcode  | Description |
|---------|------------|
| `OR`    | Bitwise OR (`ax = stack_top | ax`). |
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

### **File & Memory Management Instructions**
| Opcode  | Description |
|---------|------------|
| `OPEN`  | Open a file (not implemented). |
| `READ`  | Read from a file (not implemented). |
| `CLOS`  | Close a file (not implemented). |
| `PRTF`  | Print formatted output (not implemented). |
| `MALC`  | Allocate memory dynamically (not implemented). |
| `MSET`  | Set memory (not implemented). |
| `MCMP`  | Compare memory (not implemented). |

### **Exit Instruction**
| Opcode  | Description |
|---------|------------|
| `EXIT`  | Terminate the program execution. |


