#include "windows.h"

void str_msg(char *str)
{
	int i=0;
	MessageBox (NULL, TEXT (str), TEXT ("message"), 0) ;
}
