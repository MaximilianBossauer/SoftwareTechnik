#include <stdlib.h>
#include <stdio.h>

void UserInput (char *message);

void main(void){
    char message;
    UserInput(&message);
}

void UserInput(char *message){
printf("Please enter the receiver can message: ");
scanf("%s", &message);
printf("%s \n",&message);
}

