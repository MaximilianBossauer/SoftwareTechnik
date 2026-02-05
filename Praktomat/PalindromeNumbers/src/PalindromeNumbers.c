#include <stdio.h>
#include <stdlib.h>

void UserInput(int *Number1, int *Number2);
void SortingAndMultiplying(int *BigNumber, int *SmallNumber, int Number1, int Number2);

int main(void)
{
    int Number1, Number2, BigNumber, SmallNumber;
    UserInput(&Number1, &Number2);
    printf("%d %d", Number1, Number2);
    SortingAndMultiplying(&BigNumber, &SmallNumber, Number1, Number2);
}

void UserInput(int *Number1, int *Number2)
{
    printf("Please enter the range of numbers - multiplied with each other - to get the highest palindrome:");
    scanf("%d %d", Number1, Number2);
    if ((*Number1 < 100 || *Number1 > 999) || (*Number2 < 100 || *Number2 > 999))
    {
        printf("Wrong Input");
        exit(EXIT_SUCCESS);
    }
}
void AortingAndMultiplying(int *BigNumber, int *SmallNumber, int Number1, int Number2)
{
    int help, count;
    if (Number1 > Number2)
    {
        help = Number1;
        Number1 = Number2;
        Number2 = help;
    }


}