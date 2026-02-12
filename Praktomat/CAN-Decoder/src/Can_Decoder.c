#include <stdlib.h>
#include <stdio.h>

void UserInput(int *message);
void ExtractAndPrint(int message, int *ID, int *DLC, int *Data1, int *Data2, int *Data3);

int main(void)
{
    int message, ID, DLC, Data1, Data2, Data3;
    UserInput(&message);
    ExtractAndPrint(message, &ID, &DLC, &Data1, &Data2, &Data3);
    return EXIT_SUCCESS;
}

void UserInput(int *message)
{
    printf("Please enter the received can message: ");
    scanf("%x", message);
}

void ExtractAndPrint(int message, int *ID, int *DLC, int *Data1, int *Data2, int *Data3)
/*Extracts the different bits by moving the hexadecimals and shortening them to the needed lenght */
{
    *ID = (message >> 26) & 0x3F;
    printf("ID: %d \n", *ID);
    *DLC = (message >> 24) & 0x03;
    printf("DLC: %d \n", *DLC);
    switch (*DLC)
    {
    case 1:
        *Data1 = message  & 0xFF;
    printf("Data 1: %d \n", *Data1);
        break;
           case 2:
    *Data1 = (message >> 16) & 0xFF;
    printf("Data 1: %d \n", *Data1);
    *Data2 = (message >> 8)  & 0xFF;
    printf("Data 2: %d \n", *Data2);
        break;
           case 3:
    *Data1 = (message >> 16) & 0xFF;
       printf("Data 1: %d \n", *Data1);
    *Data2 = (message >> 8) & 0xFF;
    printf("Data 2: %d \n", *Data2);
    *Data3 = message  & 0xFF;
    printf("Data 3: %d \n", *Data3);
        break;
    }

}
