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
{
    long long Input;
    printf("Please enter the highest value, which will be selected:");
    scanf("%lld", &Input);
    return Input;
}

long long Calculation(long long Input)
{
    long long sum = 0;
    if (Input <= 14)
    {
        for (int Count = 1; Count <= Input; Count++)
        {
            sum += PowerOf(Count, Count);
        }
        sum = sum % 100000000;
        return sum;
    }
    else
    {
        {
            for (int Count = 1; Count <= Input; Count++)
            {
                sum += PowerMod(Count, Count);
            }
        }
        sum = sum % 100000000;
        return sum;
    }
}

long long PowerOf(long long Base, long long Exponent)
{
    long long Result = 1;
    for (int i = 0; i < Exponent; i++)
    {
        Result *= Base;
    }
    return Result;
}
long long PowerMod(long long Base, long long Exponent)
{
    long long Result = 1;
    for (int i = 0; i < Exponent; i++)
    {
        Result *= Base;
        Result = Result % 100000000;
    }
    return Result;
}

void Output(long long sum)
{
    printf("The last digits of the series are %lld", sum);
}