#ifndef OP_H_INCLUDED
#define OP_H_INCLUDED

#include "tree.h"
#include "link.h"
#include "fileop.h"


bool print_head(pOperate &OP);
pCmm get_command(pOperate &OP);
bool operate_init(pOperate &OP);
unsigned int count_char(char*str,char ch);
unsigned int str_to_int(char*str);
bool cmd_init(pCmm &cmd);
bool show_cmd_msg(pCmm &cmd);

///²Ù×÷
bool open_file(pOperate &OP,pCmm &cmd);


#include "op.cpp"

#endif // OP_H_INCLUDED
