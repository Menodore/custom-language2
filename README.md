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
