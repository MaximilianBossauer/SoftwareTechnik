#include <stdlib.h>
#include <stdio.h>

int FibonacciCalculator(int FibonacciNumbers[], int Input, int Count);
int UserInput(int Input);

int main(void)
{
    int sum;
    int Input = UserInput(Input);
    int Count = Input;
    int FibonacciNumbers[Input];
    FibonacciCalculator(FibonacciNumbers, Input, Count);
    for (Count = 1; Count < Input; Count++)
    {
        printf("%d\n", FibonacciNumbers[Count]);
        sum += FibonacciNumbers[Count];
        int NextNumber = FibonacciNumbers[Count] + FibonacciNumbers[Count - 1];
        if (NextNumber > Input)
        {
            break;
        }
    }
    printf("%d", sum);
    return (EXIT_SUCCESS);
}

int UserInput(int Input)
{
    printf("Please enter the max value for calculating the even- and uneven sum of fibonaccinumbers: ");
    scanf("%d", &Input);
    return Input;
}
int FibonacciCalculator(int FibonacciNumbers[], int Input, int Count)
{
    if (Input > 0)
    {
        FibonacciNumbers[0] = 0;
    }
    if (Input > 1)
    {
        FibonacciNumbers[1] = 1;
    }

    for (Count = 2; Count < Input; Count++)
    {
        FibonacciNumbers[Count] = FibonacciNumbers[Count - 1] + FibonacciNumbers[Count - 2];
        int NextNumber = FibonacciNumbers[Count] + FibonacciNumbers[Count - 1];
        if (NextNumber > Input)
        {
            break;
        }
    }
    return Count;
}
