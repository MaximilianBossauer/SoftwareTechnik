#include <stdio.h>
#include <stdlib.h>

long long UserInput(void);
long long PowerOf(long long Base, long long Exponent);
long long PowerMod(long long Base, long long Exponent);
long long Calculation(long long Input);
void Output(long long sum);

int main(void)
{
    long long Input = UserInput();
    long long sum = Calculation(Input);
    Output(sum);
    return 0;
}

long long UserInput(void)
/*Reads the user input*/
{
    long long Input;
    printf("Please enter the highest value, which will be selected:\n");
    scanf("%lld", &Input);
    return Input;
}

long long Calculation(long long Input)
/**/
{
    long long sum = 0;
    if (Input <= 14) /*below the number 15 the sum doesnt exceed the long long variable*/
    {
        for (int Count = 1; Count <= Input; Count++)
        {
            sum += PowerOf(Count, Count);
        }
        sum = sum % 100000000; /*Reducing the sum to the last 8 digits*/
        return sum;
    }
    else /*when the inserted number > 15, we would exceed long long, so we use a different function thats less precise*/
    {
        {
            for (int Count = 1; Count <= Input; Count++)
            {
                sum += PowerMod(Count, Count);
            }
        }
        sum = sum % 100000000; /*Reducing the sum to the last 8 digits*/
        return sum;
    }
}

long long PowerOf(long long Base, long long Exponent)
{
    long long Result = 1;
    for (int i = 0; i < Exponent; i++) /* for-loop calculating the k to the power of k*/
    {
        Result *= Base;
    }
    return Result;
}
long long PowerMod(long long Base, long long Exponent) 
{
    long long Result = 1;
    for (int i = 0; i < Exponent; i++) /*for loop calculating k to the power of k*/
    {
        Result *= Base;
        Result = Result % 100000000; /*Reduction to the last 8 digits, as the number would otherwise exceed the long long variable*/
    }
    return Result;
}

void Output(long long sum)
{
    printf("The last digits of the series are %lld", sum);
}