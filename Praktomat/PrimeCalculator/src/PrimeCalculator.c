#include <stdio.h>
#include <stdlib.h>

int UserInput(void);

int main(void)
{
    UserInput();
}

int UserInput(void)
{
    int Input = 0;
    printf("Please enter the number which should be factorized: ");
    scanf("%d", &Input);
}