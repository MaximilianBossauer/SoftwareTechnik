#include <stdio.h>
#include <stdlib.h>

long long UserInput(void);
long long PrimeFactors(long long Input);
void Output(long long HighestPrim, long long Input);

int main(void)
{
    long long Input = UserInput(); /*Usage of long longh if User enters very big numbers*/
    long long HighestPrim = PrimeFactors(Input);
    Output(HighestPrim, Input);
}

long long UserInput(void)
{
    long long Input = 0;
    printf("Please enter the number which should be factorized: ");
    scanf("%lld", &Input);
    if (Input <= 3) /*Entered Number must be bigger than 3 since all numbers smaller 3 dont consist of any prime-factors*/
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
    for (int n = 3; n * n <= Number; n = n + 2) /*for-loop beginning with 3, so it can cycle through every possible prime-number, as all of them can be described by n = n+2.*/
    {
        while (Number % n == 0) /*while-loop dividing the left part of the number with the actual divider given throught the for-loop until it isnt possible to divide clean*/
        {
            HighestPrim = n; /*Saving the used divider as highest primeefactor*/
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