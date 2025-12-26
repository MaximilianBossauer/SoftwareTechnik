#include <stdio.h>
#include <stdlib.h>

int UserInput();
void Extract(int UserNumber, int *hundreds, int *tens, int *ones);
void ConvertandOutput(int UserNumber, int hundreds, int tens, int ones, char *words[]);

int main(void)
{
   char *words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; /*Char for easy call and efficient use*/
   int UserNumber;
   int hundreds, tens, ones;
   UserNumber = UserInput();
   Extract(UserNumber, &hundreds, &tens, &ones);
   ConvertandOutput(UserNumber, hundreds, tens, ones, words);
   return (EXIT_SUCCESS);
}

int UserInput(void)
/*Reads the given number and checks if its in the given range 0-999*/
{
   int UserNumber;
   printf("Please enter a number between 0 and 999: ");
   scanf("%d", &UserNumber);
   if (UserNumber < 0 || UserNumber > 999) /*If-statement to check if wrong Input was entered*/
   {
      printf("INVALID, NUMBER MUST BE BETWEEN  0 and 999\nTry again\n");
      exit(EXIT_SUCCESS);
   }
   return UserNumber;
}

void Extract(int UserNumber, int *hundreds, int *tens, int *ones) 
/*Splits the given Number into its hundreds, tens and ones digits*/
{
   *hundreds = UserNumber / 100; 
   *tens = (UserNumber - *hundreds * 100) / 10; 
   *ones = UserNumber - *hundreds * 100 - *tens * 10;
}

void ConvertandOutput(int UserNumber, int hundreds, int tens, int ones, char *words[])
/*Converting the singular Digits into words and printing them into the terminal*/
{
   if (UserNumber >= 100)
   {
      printf("%s ", words[hundreds]);
   }
   if (UserNumber >= 10)

   {
      printf("%s ", words[tens]);
   }
   printf("%s ", words[ones]);
}
