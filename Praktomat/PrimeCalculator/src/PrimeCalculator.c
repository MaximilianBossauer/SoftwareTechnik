#include <stdio.h>
#include <stdlib.h>

long long UserInput(void);
long long PrimeFactors(long long Input);
void Output(long long HighestPrim, long long Input);

int main(void)
{
    long long Input = UserInput(); /*Usage of long long to support very large user inputs*/
    long long HighestPrim = PrimeFactors(Input);
    Output(HighestPrim, Input);
}

long long UserInput(void)
/*Reads the user input and makes sure if its greater than 3*/
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
/*Computes the greatest prime factor of the Input it can find*/
{
    long long HighestPrim;
    long long Number = Input;
    while (Number % 2 == 0) /*Divide with 2 repeteadly until division with 2 isnt possible anymore*/
    {
        Number = Number / 2;
    }
    for (int n = 3; n * n <= Number; n = n + 2) /*loop cyclong though all prime factors, described with n+2 starting with 3 up to the square root of Number*/
    {
        while (Number % n == 0) /*while-loop dividing dividing out the current factor as it divides the number*/
        {
            HighestPrim = n; /*Saving the used factor as highest primefactor*/
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
/*prints the largesr prime factor and the result*/
{
    printf("Highest prime factor of %lld is %lld", Input, HighestPrim);
}