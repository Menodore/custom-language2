
#include "operations.h"


void eval()
{
  long op, *tmp;
  pc = orig;
  while(1)
  {
    op = *pc;++pc;
    /* Limited operations possible due to constraints*/
    //Flow control
     if (op == JMP) {pc = (long *)(*pc);}
    else if (op == JZ) {pc = (ax.data!=0) ? (long*)(pc+1) : (long*)*((long*)pc);}
    else if (op == JNZ) {pc = (ax.data!=0) ? (long*)*((long*)pc) : (long*)(pc+1) ;}
  
    else if (op == CALL) {op_call();} //function calls - not working yet
   
    else if (op == RET) {op_ret();} // working

    //Math operatpers - defined in operations.h
    else if (op == OR){ op_or(); }
    else if (op == XOR){ op_xor(); }
    else if (op == AND){ op_and(); }
    else if (op == EQ){ op_equal(); }
    else if (op == NE){ op_notequal(); }
    else if (op == LT){ op_lt(); }
    else if (op == LE){ op_le(); }
    else if (op == GT){ op_gt(); }
    else if (op == GE){ op_ge(); }
    else if (op == SHL){ op_shl(); }
    else if (op == SHR){ op_shr(); }
    else if (op == ADD){ op_add(); }
    else if (op == SUB){ op_sub(); }
    else if (op == MUL){ op_mul(); }
    else if (op == DIV){ op_div(); }
    else if (op == MOD){ op_mod(); }
    else if (op == GETELEM){ op_getelem(); }
    else if (op == SETELEM){ op_setelem(); }
    else if (op == ADDELEM){ op_addelem(); }
    
    else if (op == EXIT) // return; / exit; / break; 
    {
      if (opreq)
      {
        printf("\x1B[31mOut[%ld]:\x1B[37m ",line);
        view(&ax);
        puts("");
      }
      return;
    }
   /* unable to add open and closing operators as defined in enum so using vm*/
    else if (op == IMM)
    {
      ax.type = (long)*pc++;
      ax.data= (long)*pc++;
    }
    else if (op == PUSH)
    {
      --sp;
      val* tmp = sp;
      tmp->type = ax.type;
      tmp->data= ax.data;
    }
    else if (op == GET)
    {
      if (ax.type != PTR)
      {
        puts("ERROR: Invalid Access!");
        exit(-1);
      }
      st* temp = (st*)ax.data;
      ax.type = temp->value->type;
      ax.data = temp->value->data;
    }
    else if (op == SET)
    {
      val* temp = (val*)sp;
      if (temp->type != PTR)
      {
        puts("ERROR: Invalid Access!");
        exit(-1);
      }
      st* target = (st*)temp->data;
      sp++;
      target->value->type = ax.type;
      target->value->data = ax.data;
    }

  }
  return;
}
