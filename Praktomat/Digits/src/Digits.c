#include <stdio.h>
#include <stdlib.h>

long long UserInput(long long Input);
long long PowerOf(long long Base, long long Exponent);
long long Calculation(long long Input, long long sum);

long long main(void)
{
    long long sum = 0, Base, Exponent;
    long long Input = UserInput(Input);
    sum = Calculation(Input, sum);
    printf("%lld\n", Input);
    printf("%lld", sum);
    return 0;
}

long long UserInput(long long Input)
{
    printf("Please enter the highest value, which will be selected:");
    scanf("%lld", &Input);
    return Input;
}

long long Calculation(long long Input, long long sum)
{
    long long sumhelp;
    for (int Count = 1; Count <= Input; Count++)
    {
        sum += PowerOf(Count, Count);
    }
    return sum;
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