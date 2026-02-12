#include <stdio.h>
#include <stdlib.h>

void UserInput(int *Number1, int *Number2);
void SortingAndMultiplying(int *BigNumber, int *SmallNumber, int *Factor1, int *Factor2, int *PalindromeNumber, int Number1, int Number2);
int ExtractDigits(int MultipliedNumbers);
int PalindromeCheckerSmall(int TenThousands, int Thousands, int Hundreds, int Tens, int Ones);
int PalindromeCheckerBig(int HundredThousands, int TenThousands, int Thousands, int Hundreds, int Tens, int Ones);
void Output(int PalindromeNumber, int Factor1, int Factor2);
void NoPalindrome(void);
int main(void)
{
    int Number1, Number2, BigNumber, SmallNumber, PalindromeNumber, Factor1, Factor2;
    UserInput(&Number1, &Number2);
    SortingAndMultiplying(&BigNumber, &SmallNumber, &PalindromeNumber, &Factor1, &Factor2, Number1, Number2);
    Output(PalindromeNumber, Factor1, Factor2);
}

void UserInput(int *Number1, int *Number2)
{
    printf("Please enter the range of numbers - multiplied with each other - to get the highest palindrome: ");
    scanf("%d %d", Number1, Number2);
    if ((*Number1 < 100 || *Number1 > 999) || (*Number2 < 100 || *Number2 > 999))
    {
        printf("Wrong input!");
        exit(EXIT_SUCCESS);
    }
}
void SortingAndMultiplying(int *BigNumber, int *SmallNumber, int *PalindromeNumber, int *Factor1, int *Factor2, int Number1, int Number2)
{
    int MultipliedNumbers = 0;
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
    /*While loop that counts through the smaller number*/
    {
        int Count2 = *SmallNumber;
        while (Count2 <= *BigNumber)
        /*While loop that counts through until bigger number and multiplies them with the smaller number*/
        {
            MultipliedNumbers = Count1 * Count2;

            *PalindromeNumber = ExtractDigits(MultipliedNumbers);
            if (*PalindromeNumber != 0 && BiggestPalindrome < *PalindromeNumber)
            /*Compares current found Palindrome with the biggest found Palindrome and remembers both factors if a bigger Palindrome is found*/
            {
                BiggestPalindrome = *PalindromeNumber;
                *Factor1 = Count1;
                *Factor2 = Count2;
            }
            Count2++;
        }
        Count1++;
    }
    if (BiggestPalindrome == 0)
    {
        NoPalindrome();
        exit(EXIT_SUCCESS);
    }
    else
    {
        *PalindromeNumber = BiggestPalindrome;
    }
}

int ExtractDigits(int MultipliedNumbers)
{
    int CheckerVariable = 0;
    int HundredThousands, TenThousands, Thousands, Hundreds, Tens, Ones;
    if (MultipliedNumbers <= 100000)
    {
        TenThousands = MultipliedNumbers / 10000;
        Thousands = (MultipliedNumbers - TenThousands * 10000) / 1000;
        Hundreds = (MultipliedNumbers - TenThousands * 10000 - Thousands * 1000) / 100;
        Tens = (MultipliedNumbers - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100) / 10;
        Ones = MultipliedNumbers - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100 - Tens * 10;
        CheckerVariable = PalindromeCheckerSmall(TenThousands, Thousands, Hundreds, Tens, Ones);
        if (CheckerVariable == 1)
        {
            return MultipliedNumbers;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        HundredThousands = MultipliedNumbers / 100000;
        TenThousands = (MultipliedNumbers - HundredThousands * 100000) / 10000;
        Thousands = (MultipliedNumbers - HundredThousands * 100000 - TenThousands * 10000) / 1000;
        Hundreds = (MultipliedNumbers - HundredThousands * 100000 - TenThousands * 10000 - Thousands * 1000) / 100;
        Tens = (MultipliedNumbers - HundredThousands * 100000 - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100) / 10;
        Ones = MultipliedNumbers - HundredThousands * 100000 - TenThousands * 10000 - Thousands * 1000 - Hundreds * 100 - Tens * 10;
        CheckerVariable = PalindromeCheckerBig(HundredThousands, TenThousands, Thousands, Hundreds, Tens, Ones);
        if (CheckerVariable == 1)
        {
            return MultipliedNumbers;
        }
        else
        {
            return 0;
        }
    }
}

int PalindromeCheckerSmall(int TenThousands, int Thousands, int Hundreds, int Tens, int Ones)
/*Checks for Palindromes in Numbers with 5 digits*/
{
    if ((TenThousands == Ones) && (Thousands == Tens))
        return 1;
    else
    {
        return 0;
    }
}
int PalindromeCheckerBig(int HundredThousands, int TenThousands, int Thousands, int Hundreds, int Tens, int Ones)
/*Checks for Palindromes in Numbers with 6 digits*/
{
    if ((HundredThousands == Ones) && (TenThousands == Tens) && (Thousands == Hundreds))
        return 1;
    else
    {
        return 0;
    }
}
void NoPalindrome(void)
{
    printf("No palindrome found!");
    exit(EXIT_SUCCESS);
}
void Output(int PalindromeNumber, int Factor1, int Factor2)
{
    printf("The highest palindrome as a product of %d and %d is %d", Factor1, Factor2, PalindromeNumber);
}