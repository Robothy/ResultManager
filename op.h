#ifndef OP_H_INCLUDED
#define OP_H_INCLUDED

#include "fileop.h"


bool print_head(pOperate &OP);
pCmm get_command(pOperate &OP);
bool operate_init(pOperate &OP);
unsigned int count_char(char*str,char ch);
unsigned int str_to_int(char*str);
bool cmd_init(pCmm &cmd);
bool show_cmd_msg(pCmm &cmd);

bool open_file(pOperate &OP,pCmm &cmd);
bool rm_a_score(pOperate &OP,pCmm &cmd);
bool save_file(pOperate &OP,pCmm &cmd);
bool rm_some_score(pOperate &OP,pCmm &cmd);
void rm_a_stu_score(pOperate &OP,pCmm &cmd);
bool remove_file(pOperate &OP,pCmm &cmd);
bool rm_a_student(pOperate &OP,pCmm &cmd);
bool find_a_score(pOperate &OP,pCmm &cmd);
bool find_some_score(pOperate &OP,pCmm &cmd);
bool find_a_stu_score(pOperate &OP,pCmm &cmd);
bool find_a_student(pOperate &OP,pCmm &cmd);
bool insert_a_score(pOperate &OP,pCmm &cmd);
bool insert_a_stu_score(pOperate &OP,pCmm &cmd);

void print_welcome(void);

#include "op.cpp"

#endif // OP_H_INCLUDED
