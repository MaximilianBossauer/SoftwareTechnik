#include <stdlib.h>
#include <stdio.h>

int FibonacciCalculator(int FibonacciNumbers[], int Input);
int UserInput(int Input);
int Output(int FibonacciNumbers[], int Input);

int main(void)
{
    int SumEven;
    int SumUneven;
    int Input = UserInput(Input);
    int FibonacciNumbers[Input];
    FibonacciCalculator(FibonacciNumbers, Input);

    Output(FibonacciNumbers, Input);
}

int UserInput(int Input)
{
    printf("Please enter the max value for calculating the even- and uneven sum of fibonaccinumbers: ");
    scanf("%d", &Input);
    return Input;
}
int FibonacciCalculator(int FibonacciNumbers[], int Input)
{
    int NextNumber = 0;
    FibonacciNumbers[0] = 0;
    FibonacciNumbers[1] = 1;

    for (int Count = 2; NextNumber <= Input; Count++)
    {
        FibonacciNumbers[Count] = FibonacciNumbers[Count - 1] + FibonacciNumbers[Count - 2];
        NextNumber = FibonacciNumbers[Count] + FibonacciNumbers[Count - 1];
        if (NextNumber > Input)
        {
            break;
        }
    }
}

int Output(int FibonacciNumbers[], int Input)
{
    int NextNumber = 0;
    int i = 2;
    int SumEven = 0;
    int SumUneven = 0;
    while (NextNumber <= Input)
    {
        if ((FibonacciNumbers[i] % 2) == 1)
        {
            SumUneven += FibonacciNumbers[i];
        }
        else
        {
            SumEven += FibonacciNumbers[i];
        }
        NextNumber = FibonacciNumbers[i] + FibonacciNumbers[i - 1];
        i++;
    }
    printf("The sum of all Fibonacci-numbers not exceeding the entered max of %d is %d (even) "
           "and %d (odd)",
           Input, SumEven, SumUneven);
}