#include <stdio.h>
#include <stdlib.h>

int UserNumber;
int hundrets;
int tens;
int ones;
char *words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int UserInput(void)
{
   printf("Please enter a number between 0 and 999: ");
   scanf("%d", &UserNumber);
   if (UserNumber < 0 || UserNumber > 999)
   {
      printf("INVALID, NUMBER MUST BE BETWEEN  0 and 999\nTry again\n");
      exit(EXIT_SUCCESS);
   }
}

int Extract(void)
{
   hundrets = UserNumber / 100;
   tens = (UserNumber - hundrets * 100) / 10;
   ones = UserNumber - hundrets * 100 - tens * 10;
}

int ConvertandOuput(void)
{
   if (UserNumber >= 100)
   {
      printf("%s ", words[hundrets]);
   }
   if (UserNumber >= 10)

   {
      printf("%s ", words[tens]);
   }
   printf("%s ", words[ones]);
}

int main(void)
{
   UserInput();
   Extract();
   ConvertandOuput();
   return(EXIT_SUCCESS);
}
