# 🌟 Custom-Language2  
*A C Interpreter written in C with a recursive-descent parser that converts code to bytecode for execution.*

## ✨ Features  
- Uses a **recursive-descent parser**  
- Converts code to **bytecode** and executes it  
- Implements a **stack-based virtual machine (VM)**  
- Supports basic **data types, function calls, and operations**  

---

## 🏗️ Data Type Representation  

Only **one** data type exists: `val`.  

```c
typedef struct val {
  long type;
  long data;
} val;

type: Defines the underlying primitive type.
data: Stores the actual value (directly for integers, as a pointer for other types).

---

## 🛠️ Supported Types
Type Code	Type Name	Description
0	None Type	Default type
1	Integer Type	Stores integer values
2	String Type	Stores string values
3	List Type	Represents lists
4	Pointer Type	Stores memory addresses
5	Function Type	Represents functions
For more details, see globals.h.

---


##🏗️ Virtual Machine (VM) Architecture
###📌 Stack
The interpreter operates using two stacks:

Stack Type	Purpose
Operations Stack	Used for all VM operations, stores operands of type val
Call Stack	Stores return addresses and manages function scopes
⚙️ Registers
Register	Purpose
sp	Stack top pointer
ax	Auxiliary register (val type)
cs_sp	Call stack top pointer
cs_bp	Call stack base pointer
