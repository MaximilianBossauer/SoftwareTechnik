#include <stdio.h>
#include <stdlib.h>

int UserInput();
void Extract(int UserNumber, int *hundrets, int *tens, int *ones);
int ConvertandOutput(int UserNumber,int hundrets, int tens, int ones, char *words[]);



int main(void)
{
   char *words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
   int UserNumber;
   int hundrets, tens, ones;
   UserNumber = UserInput();
   Extract(UserNumber, &hundrets, &tens, &ones);
   ConvertandOutput(UserNumber, hundrets, tens, ones, words);
   return (EXIT_SUCCESS);
}

int UserInput(void)
{
   int UserNumber;
   printf("Please enter a number between 0 and 999: ");
   scanf("%d", &UserNumber);
   if (UserNumber < 0 || UserNumber > 999)
   {
      printf("INVALID, NUMBER MUST BE BETWEEN  0 and 999\nTry again\n");
      exit(EXIT_SUCCESS);
   }
   return UserNumber;
}

void Extract(int UserNumber, int *hundrets, int *tens, int *ones)
{
   *hundrets = UserNumber / 100;
   *tens = (UserNumber - *hundrets * 100) / 10;
   *ones = UserNumber - *hundrets * 100 - *tens * 10;
}

int ConvertandOutput(int UserNumber, int hundrets, int tens, int ones, char *words[])
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
