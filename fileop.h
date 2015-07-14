#ifndef FILEOP_H_INCLUDED
#define FILEOP_H_INCLUDED

#include "stdio.h"
#include "stack.h"
#include "tree.h"


bool get_file_name(char*&file_name,char *file_na);
bool open_report_card(pBSTree &BST,char *file_na);
bool save_report_card(pBSTree &BST,char *file_na);



#include "fileop.cpp"
#endif // FILEOP_H_INCLUDED
