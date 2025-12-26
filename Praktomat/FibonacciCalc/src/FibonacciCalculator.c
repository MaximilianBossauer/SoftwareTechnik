#include <stdlib.h>
#include <stdio.h>

void FibonacciCalculator(long long FibonacciNumbers[], long long Input);
long long UserInput(void);
void SumCalculation(long long FibonacciNumbers[], long long Input, long long *SumEven, long long *SumOdd);
void Output(long long SumEven, long long Sumodd, long long Input);
int main(void)
{
    long long SumEven, SumOdd;
    long long Input = UserInput();
    long long FibonacciNumbers[Input];
    FibonacciCalculator(FibonacciNumbers, Input);
    SumCalculation(FibonacciNumbers, Input, &SumEven, &SumOdd);
    Output(SumEven, SumOdd, Input);
}

long long UserInput(void)
/*Reads the maxim allowed fibonacci value the user wants*/
{
    long long Input;
    printf("Please enter the max value for calculating the even- and uneven sum of fibonaccinumbers: ");
    scanf("%lld", &Input);
    return Input;
}
void FibonacciCalculator(long long FibonacciNumbers[], long long Input)
/*Generates the fibonacci numbers starting with 0 and stpos when they exceed the user input*/
{
    long long NextNumber = 0;
    FibonacciNumbers[0] = 0;
    FibonacciNumbers[1] = 1;

    for (long long Count = 2; NextNumber <= Input; Count++) /*for-loop to calculating fibonacci numbers until they exceed the user input*/
    {
        FibonacciNumbers[Count] = FibonacciNumbers[Count - 1] + FibonacciNumbers[Count - 2];
        NextNumber = FibonacciNumbers[Count] + FibonacciNumbers[Count - 1]; /*Calculation of following fibonacci-number for the break condition*/
        if (NextNumber > Input)                                             /*Break condition of the Loop to save computing power if the next fibonacci-number would exceed the Input*/
        {
            break;
        }
    }
}

void SumCalculation(long long FibonacciNumbers[], long long Input, long long *SumEven, long long *SumOdd)
/*Differentiates between odd and even fibonacci numbers and calculates the sum of each*/
{
    long long NextNumber = 0;
    long long i = 1;
    *SumEven = 0;
    *SumOdd = 0;
    while (NextNumber <= Input) /*While-loop cycling through all previously calculated fibonacci-numbers*/
    {
        if ((FibonacciNumbers[i] % 2) == 1) /*Check if the specific number is even or odd*/
        {
            *SumOdd += FibonacciNumbers[i]; /*Addition of all odd numbers*/
        }
        else
        {
            *SumEven += FibonacciNumbers[i]; /*Addition of all even numbers*/
        }
        NextNumber = FibonacciNumbers[i] + FibonacciNumbers[i - 1]; /*Calculation of the following fibonacci-number to use in the while as break condition*/
        i++;
    }
}

void Output(long long SumEven, long long SumOdd, long long Input)
/*Prints out the calculated sums and the input*/
{

    printf("The sum of all Fibonacci-numbers not exceeding the entered max of %lld is %lld (even) "
           "and %lld (odd)",
           Input, SumEven, SumOdd);
}