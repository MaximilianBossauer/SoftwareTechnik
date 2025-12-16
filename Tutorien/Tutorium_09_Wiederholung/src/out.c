#include <stdio.h>
#include "out.h"

void clrscr(void)  
{  
    printf("\x1B[2J");  
}  

void gotoxy(int x,int y)  
{  
    printf("\x1B[%d;%dH",x,y);  
} 
