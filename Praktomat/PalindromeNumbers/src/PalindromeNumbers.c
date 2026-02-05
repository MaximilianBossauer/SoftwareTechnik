#include <stdio.h>
#include <stdlib.h>

void UserInput(int *Number1, int *Number2);
void SortingAndMultiplying(int *BigNumber, int *SmallNumber, int *Palindrome, int Number1, int Number2);
int Extract(int Multiplied);
int PalindromeCheckerSmall(int TenThousands, int Thousands, int Hundreds, int Tens, int Ones);
int PalindromeCheckerBig(int HundredThousands, int TenThousands, int Thousands, int Hundreds, int Tens, int Ones);

int main(void)
{
    int Number1, Number2, BigNumber, SmallNumber, Palindrome;
    UserInput(&Number1, &Number2);
    printf("%d %d", Number1, Number2);
    SortingAndMultiplying(&BigNumber, &SmallNumber, &Palindrome, Number1, Number2);
    printf("%d", Palindrome);
}

void UserInput(int *Number1, int *Number2)
{
    printf("Please enter the range of numbers - multiplied with each other - to get the highest palindrome:");
    scanf("%d %d", Number1, Number2);
    if ((*Number1 < 100 || *Number1 > 999) || (*Number2 < 100 || *Number2 > 999))
    {
        printf("Wrong Input");
        exit(EXIT_SUCCESS);
    }
}
void SortingAndMultiplying(int *BigNumber, int *SmallNumber, int *Palindrome, int Number1, int Number2)
{
    int Multiplied = 0;
    int BiggestPalindrome = 0;
    if (Number1 > Number2)
    {

        *SmallNumber = Number2;
        *BigNumber = Number1;
    }
    else
    {
        *BigNumber = Number2;
        *SmallNumber = Number1;
    }
    int Count1 = *SmallNumber;
    while (Count1 <= *BigNumber)
    {
        int Count2 = *SmallNumber;
        while (Count2 <= *BigNumber)
        {
            Multiplied = Count1 * Count2;
            printf("%d * %d\n", Count1, Count2);
            Count2++;
            *Palindrome = Extract(Multiplied);
            if (*Palindrome != 0 && BiggestPalindrome < *Palindrome)
            {
                BiggestPalindrome = *Palindrome;
            }
        }
        Count1++;
    }
    *Palindrome = BiggestPalindrome;
}

int Extract(int Multiplied)
{
    int YAsss = 0;
    int HundredThousands, TenThousands, Thousands, Hundreds, Tens, Ones;
    if (Multiplied <= 100000)
    {
        TenThousands = Multiplied / 10000;
        Thousands = (Multiplied - TenThousands * 10000) / 1000;
        Hundreds = (Multiplied - TenThousands * 10000 - Thousands * 1000) / 100;
        Tens = (Multiplied - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100) / 10;
        Ones = Multiplied - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100 - Tens * 10;
        YAsss = PalindromeCheckerSmall(TenThousands, Thousands, Hundreds, Tens, Ones);
        if (YAsss == 1)
        {
            return Multiplied;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        HundredThousands = Multiplied / 100000;
        TenThousands = (Multiplied - HundredThousands * 100000) / 10000;
        Thousands = (Multiplied - HundredThousands * 100000 - TenThousands * 10000) / 1000;
        Hundreds = (Multiplied - HundredThousands * 100000 - TenThousands * 10000 - Thousands * 1000) / 100;
        Tens = (Multiplied - HundredThousands * 100000 - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100) / 10;
        Ones = Multiplied - HundredThousands * 100000 - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100 - Tens * 10;
        YAsss = PalindromeCheckerBig(HundredThousands, TenThousands, Thousands, Hundreds, Tens, Ones);
        if (YAsss == 1)
        {
            return Multiplied;
        }
        else
        {
            return 0;
        }
    }
}

int PalindromeCheckerSmall(int TenThousands, int Thousands, int Hundreds, int Tens, int Ones)
{
    if ((TenThousands == Ones) && (Thousands == Tens))
        return 1;
    else
    {
        return 0;
    }
}
int PalindromeCheckerBig(int HundredThousands, int TenThousands, int Thousands, int Hundreds, int Tens, int Ones)
{
    if ((HundredThousands == Ones) && (TenThousands == Tens) && (Thousands == Hundreds))
        return 1;
    else
    {
        return 0;
    }
}