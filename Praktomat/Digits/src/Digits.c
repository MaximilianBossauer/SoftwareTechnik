#include <stdio.h>
#include <stdlib.h>

int UserInput(int Input);


int main (void){
    int Input = UserInput(Input);
    printf("%d", Input);
}

int UserInput(int Input)
{
    printf("Please enter the highest value, which will be selected:");
    scanf("%d", &Input);
    return Input;
}