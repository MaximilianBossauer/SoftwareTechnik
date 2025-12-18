#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*30°20'10'25°20'34''67°89'32''48°30'00''*/

void InputConvert(double* deplatDecimal, double* deplongDecimal, double* arrlatDecimal, double* arrlongDecimal);
double DegreeCalculation(double Degree, double Minutes, double Seconds);
void RadiantCalculation(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal);
double sinDeg(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal);
double cosDeg(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal);

int main(void)
{
    double deplatDecimal, deplongDecimal, arrlatDecimal, arrlongDecimal;
    InputConvert(&deplatDecimal, &deplongDecimal, &arrlatDecimal, &arrlongDecimal);
    RadiantCalculation(deplatDecimal, deplongDecimal, arrlatDecimal, arrlongDecimal);
}
void InputConvert(double* deplatDecimal, double* deplongDecimal, double* arrlatDecimal, double* arrlongDecimal)
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

    *deplatDecimal = DegreeCalculation(deplat.Degree, deplat.Minutes, deplat.Seconds);
    *deplongDecimal = DegreeCalculation(deplong.Degree, deplong.Minutes, deplong.Seconds);
    *arrlatDecimal = DegreeCalculation(arrlat.Degree, arrlat.Minutes, arrlat.Seconds);
    *arrlongDecimal = DegreeCalculation(arrlong.Degree, arrlong.Minutes, arrlong.Seconds);
    }



double DegreeCalculation(double Degree, double Minutes, double Seconds)
{
    return Degree + Minutes / 60 + Seconds / 3600;
}

void RadiantCalculation(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal){


}

double sinDeg(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal){

}
double cosDeg(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal){
    
}