#include <stdio.h>
#include <stdlib.h>

long long UserInput(void);
long long PrimeFactors(long long Input);
void Output(long long HighestPrim, long long Input);

int main(void)
{
    long long Input = UserInput();
    long long HighestPrim = PrimeFactors(Input);
    Output(HighestPrim, Input);
}

long long UserInput(void)
{
    long long Input = 0;
    printf("Please enter the number which should be factorized: ");
    scanf("%lld", &Input);
    if (Input <= 3)
    {
        printf("The entered number is invalid!");
        exit(0);
    }
    return Input;
}

long long PrimeFactors(long long Input)
{
    long long HighestPrim;
    long long Number = Input;
    while (Number % 2 == 0) /*If User entered an even Number, which cant be a Prime, divide it by two until it isnt even anymore*/
    {
        Number = Number / 2;
    }
    for (int n = 3; n * n <= Number; n = n + 2)
    {
        while (Number % n == 0)
        {
            HighestPrim = n;
            Number = Number / n;
        }
    }
    if (Number > 2)
    {
        HighestPrim = Number;
    }
    return HighestPrim;
}

void Output(long long HighestPrim, long long Input)
{
    printf("Highest prime factor of %lld is %lld", Input, HighestPrim);
}