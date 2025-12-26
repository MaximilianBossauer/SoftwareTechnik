#include <stdlib.h>
#include <stdio.h>

void FibonacciCalculator(int FibonacciNumbers[], int Input);
int UserInput(int Input);
void SumCalculation(int FibonacciNumbers[], int Input, int *SumEven, int *SumOdd);
void Output (int SumEven, int Sumodd, int Input);

int main(void)
{
    int SumEven, SumOdd;
    int Input = UserInput(Input);
    int FibonacciNumbers[Input];
    FibonacciCalculator(FibonacciNumbers, Input);
    SumCalculation(FibonacciNumbers, Input, &SumEven, &SumOdd);
    Output(SumEven, SumOdd, Input);
}

int UserInput(int Input)
{
    printf("Please enter the max value for calculating the even- and uneven sum of fibonaccinumbers: ");
    scanf("%d", &Input);
    return Input;
}
void FibonacciCalculator(int FibonacciNumbers[], int Input)
{
    int NextNumber = 0;
    FibonacciNumbers[0] = 0;
    FibonacciNumbers[1] = 1;

    for (int Count = 2; NextNumber <= Input; Count++)  /*for-loop to calculate as many fibonacci-numbersn as the Input says*/
    {
        FibonacciNumbers[Count] = FibonacciNumbers[Count - 1] + FibonacciNumbers[Count - 2];
        NextNumber = FibonacciNumbers[Count] + FibonacciNumbers[Count - 1]; /*Calculation of following fibonacci-number*/
        if (NextNumber > Input) /*Break condition of the Loop to save computing power if the next fibonacci-number would exceed the Input*/
        {
            break;
        }
    }
}

void SumCalculation(int FibonacciNumbers[], int Input, int *SumEven, int *SumOdd)
{
    int NextNumber = 0;
    int i = 2;
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

void Output (int SumEven, int SumOdd, int Input){
    printf("The sum of all Fibonacci-numbers not exceeding the entered max of %d is %d (even) "
           "and %d (odd)",
           Input, SumEven, SumOdd);
}