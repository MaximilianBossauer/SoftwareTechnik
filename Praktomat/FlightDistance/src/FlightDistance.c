#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void UserInput(void);
double DegreeCalculation(double Degree, double Minutes, double Seconds);

int main(void)
{
    double Degree;
     double Minutes;
      double Seconds;
      double deplatDecimal,deplongDecimal,arrlatDecimal,arrlatDecimal;
    UserInput();
    DegreeCalculation(Degree, Minutes, Seconds);
    printf("%lf",deplatDecimal);
}

void UserInput(void)
{
    struct Coordinate
    {
        double Degree;
        double Minutes;
        double Seconds;
    };
    char Symbols[16];
    printf("Please enter latitude in ° ' '' and longitude in ° ' '' for departure and arrival:");
    struct Coordinate deplat, deplong, arrlat, arrlong;
    scanf("%lf%c%lf%c%lf%c%c%lf%c%lf%c%lf%c%c%lf%c%lf%c%lf%c%c%lf%c%lf%c%lf%c%c",
          &deplat.Degree, &Symbols[0],
          &deplat.Minutes, &Symbols[1],
          &deplat.Seconds, &Symbols[2], &Symbols[12],
          &deplong.Degree, &Symbols[3],
          &deplong.Minutes, &Symbols[4],
          &deplong.Seconds, &Symbols[5], &Symbols[13],
          &arrlat.Degree, &Symbols[6],
          &arrlat.Minutes, &Symbols[7],
          &arrlat.Seconds, &Symbols[8], &Symbols[14],
          &arrlong.Degree, &Symbols[9],
          &arrlong.Minutes, &Symbols[10],
          &arrlong.Seconds, &Symbols[11], &Symbols[15]);
    double deplatDecimal = DegreeCalculation(deplat.Degree, deplat.Minutes, deplat.Seconds);
    double deplongDecimal = DegreeCalculation(deplong.Degree, deplong.Minutes, deplong.Seconds);
    double arrlatDecimal = DegreeCalculation(arrlat.Degree, arrlat.Minutes, arrlat.Seconds);
    double arrlongDecimal = DegreeCalculation(arrlong.Degree, arrlong.Minutes, arrlong.Seconds);
return deplatDecimal,deplongDecimal,arrlatDecimal,arrlongDecimal;
}

double DegreeCalculation(double Degree, double Minutes, double Seconds)
{
    return Degree + Minutes / 60 + Seconds / 3600;
}