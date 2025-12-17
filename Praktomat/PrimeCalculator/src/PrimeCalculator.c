#include <stdio.h>
#include <stdlib.h>

long long UserInput(void);
void PrimeFactors(long long Input);

int main(void)
{
    long long Input = UserInput();
    printf("%lld", Input);
    PrimeFactors(Input);
    
}

long long UserInput(void)
{
    long long Input = 0;
    printf("Please enter the number which should be factorized: ");
    scanf("%lld", &Input);
    return Input;
}

void PrimeFactors(long long Input)
{
    int HighestPrim = 0;
    long long Number = Input;
    while (Number % 2 == 0) /*If User entered an even Number, which cant be a Prime, divide it by two until it isnt even anymore*/
    {
        Number = Number / 2;
    }
    printf("\nug %lld", Number);
    for (int n = 3; n * n <= Number; n = n + 2)
    {
        while (Number % n == 0)
        {
            HighestPrim = n;
            Number = Number / n;
        }
    }
if (Number > 2){
    HighestPrim = Number;
}
    printf("\nfer %lld", HighestPrim);
}