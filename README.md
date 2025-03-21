# customC-Interpreter 
*A C Interpreter written in C with a recursive-descent parser that converts code to bytecode for execution.*

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

