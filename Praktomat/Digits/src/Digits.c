#include <stdio.h>
#include <stdlib.h>

long long UserInput(long long Input);
long long Calculation(long long Input, long long sum);

long long main (void){
    long long sum = 0;
    long long Input = UserInput(Input);
    sum = Calculation (Input, sum);
    printf ("%d\n", Input);
    printf ("%d",sum);
}

long long UserInput(long long Input)
{
    printf ("Please enter the highest value, which will be selected:");
    scanf("%d", &Input);
    return Input;
}

long long Calculation (long long Input, long long sum){
    long long sumhelp;
    for (long long count = 1; count <= Input; count ++){
        sumhelp = count ;
        sum += sumhelp;
    }
    return sum;
}