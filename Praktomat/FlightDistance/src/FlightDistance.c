#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef EARTH_RAD
#define EARTH_RAD 6378.388
#endif

/*53°37'49''9°59'18''48°21'14''11°47'10''*/

void InputConvert(double *deplatDecimal, double *deplongDecimal, double *arrlatDecimal, double *arrlongDecimal);
double DegreeCalculation(double Degree, double Minutes, double Seconds);
void RadiantCalculation(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal, double *sinArrLat, double *sinDepLat, double *cosArrLat, double *cosDepLat, double *cosDepArrLong);
double sinDeg(double degrees);
double cosDeg(double degrees);
void DistanceCalculation(double sinArrLat, double sinDepLat, double cosArrLat, double cosDepLat, double cosDepArrLong, double *Distance);
void Output(double Distance);

int main(void)
{
    double deplatDecimal, deplongDecimal, arrlatDecimal, arrlongDecimal;
    double sinArrLat, sinDepLat, cosArrLat, cosDepLat, cosDepArrLong;
    double Distance;
    InputConvert(&deplatDecimal, &deplongDecimal, &arrlatDecimal, &arrlongDecimal);
    RadiantCalculation(deplatDecimal, deplongDecimal, arrlatDecimal, arrlongDecimal, &sinArrLat, &sinDepLat, &cosArrLat, &cosDepLat, &cosDepArrLong);
    DistanceCalculation(sinArrLat, sinDepLat, cosArrLat, cosDepLat, cosDepArrLong, &Distance);
    Output(Distance);
}
void InputConvert(double *deplatDecimal, double *deplongDecimal, double *arrlatDecimal, double *arrlongDecimal)
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

void RadiantCalculation(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal, double *sinArrLat, double *sinDepLat, double *cosArrLat, double *cosDepLat, double *cosDepArrLong)
{
    double help = arrlongDecimal - deplongDecimal;
    *sinArrLat = sinDeg(arrlatDecimal);
    *sinDepLat = sinDeg(deplatDecimal);
    *cosArrLat = cosDeg(arrlatDecimal);
    *cosDepLat = cosDeg(deplatDecimal);
    *cosDepArrLong = cosDeg(help);
}

double sinDeg(double degrees)
{
    double radiant = degrees * M_PI / 180;
    return sin(radiant);
}
double cosDeg(double degrees)
{
    double radiant = degrees * M_PI / 180;
    return cos(radiant);
}

void DistanceCalculation(double sinArrLat, double sinDepLat, double cosArrLat, double cosDepLat, double cosDepArrLong, double *Distance)
{
    *Distance = EARTH_RAD * acos(sinArrLat * sinDepLat + cosArrLat * cosDepLat * cosDepArrLong);
}

void Output(double Distance)
{
    printf("Flight Distance in km is %.2f", Distance);
}
