#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846 /*Redefinition of Pi since my math.h wasnt working correctly*/
#define EARTH_RAD 6378.388          /*Definition of earth radius for easier handling later*/

/*Test Coordinates: 53°37'49''9°59'18''48°21'14''11°47'10'' , Distance: 600.69 Km */

void InputConvert(double *deplatDecimal, double *deplongDecimal, double *arrlatDecimal, double *arrlongDecimal);
double DegreeCalculation(double Degree, double Minutes, double Seconds);
void SinCosCalculation(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal, double *sinArrLat, double *sinDepLat, double *cosArrLat, double *cosDepLat, double *cosDepArrLong);
double sinDeg(double degrees);
double cosDeg(double degrees);
void DistanceCalculation(double sinArrLat, double sinDepLat, double cosArrLat, double cosDepLat, double cosDepArrLong, double *Distance);
void Output(double Distance);

int main(void)
{
    double deplatDecimal, deplongDecimal, arrlatDecimal, arrlongDecimal, sinArrLat, sinDepLat, cosArrLat, cosDepLat, cosDepArrLong, Distance;
    InputConvert(&deplatDecimal, &deplongDecimal, &arrlatDecimal, &arrlongDecimal);
    SinCosCalculation(deplatDecimal, deplongDecimal, arrlatDecimal, arrlongDecimal, &sinArrLat, &sinDepLat, &cosArrLat, &cosDepLat, &cosDepArrLong);
    DistanceCalculation(sinArrLat, sinDepLat, cosArrLat, cosDepLat, cosDepArrLong, &Distance);
    Output(Distance);
}
void InputConvert(double *deplatDecimal, double *deplongDecimal, double *arrlatDecimal, double *arrlongDecimal)
{
    struct Coordinate /*Structure for the individual values of the user inserted Coordinates.*/
    {
        double Degree;
        double Minutes;
        double Seconds;
    };
    char Symbols[16]; /*Empty char to save the given Symbols*/
    printf("Please enter latitude in ° ' '' and longitude in ° ' '' for departure and arrival:");
    struct Coordinate deplat, deplong, arrlat, arrlong; /*Different variants of the struct for every Coordinate given*/
    scanf("%lf%c%lf%c%lf%c%c%lf%c%lf%c%lf%c%c%lf%c%lf%c%lf%c%c%lf%c%lf%c%lf%c%c",
          &deplat.Degree, &Symbols[0],
          &deplat.Minutes, &Symbols[1],
          &deplat.Seconds, &Symbols[2], &Symbols[3],
          &deplong.Degree, &Symbols[4],
          &deplong.Minutes, &Symbols[5],
          &deplong.Seconds, &Symbols[6], &Symbols[7],
          &arrlat.Degree, &Symbols[8],
          &arrlat.Minutes, &Symbols[9],
          &arrlat.Seconds, &Symbols[10], &Symbols[11],
          &arrlong.Degree, &Symbols[12],
          &arrlong.Minutes, &Symbols[13],
          &arrlong.Seconds, &Symbols[14], &Symbols[15]); /*The different symbol-scans dont have any direct function later, just to read the input correctly*/

    *deplatDecimal = DegreeCalculation(deplat.Degree, deplat.Minutes, deplat.Seconds); /*Call of new function to directly convert the entered Coordinates, for easier Handling of just 4 values and not 12*/
    *deplongDecimal = DegreeCalculation(deplong.Degree, deplong.Minutes, deplong.Seconds);
    *arrlatDecimal = DegreeCalculation(arrlat.Degree, arrlat.Minutes, arrlat.Seconds);
    *arrlongDecimal = DegreeCalculation(arrlong.Degree, arrlong.Minutes, arrlong.Seconds);
}

double DegreeCalculation(double Degree, double Minutes, double Seconds)
{
    return Degree + Minutes / 60 + Seconds / 3600; /*Formula of coordinate-conversion to decimal*/
}

void SinCosCalculation(double deplatDecimal, double deplongDecimal, double arrlatDecimal, double arrlongDecimal, double *sinArrLat, double *sinDepLat, double *cosArrLat, double *cosDepLat, double *cosDepArrLong)
{
    *sinArrLat = sinDeg(arrlatDecimal); /*Calculation of Sine and Cosine of the Decimal Coordinates as needed in the Distance Formula later*/
    *sinDepLat = sinDeg(deplatDecimal);
    *cosArrLat = cosDeg(arrlatDecimal);
    *cosDepLat = cosDeg(deplatDecimal);
    *cosDepArrLong = cosDeg((arrlongDecimal - deplongDecimal));
}

double sinDeg(double degrees) /*Specific Function for the sine*/
{
    double radiant = degrees * M_PI / 180; /*Decimal to radiant conversion*/
    return sin(radiant);
}
double cosDeg(double degrees) /*Specific function for the cosine*/
{
    double radiant = degrees * M_PI / 180; /*Decimal to radiant conversion*/
    return cos(radiant);
}

void DistanceCalculation(double sinArrLat, double sinDepLat, double cosArrLat, double cosDepLat, double cosDepArrLong, double *Distance)
{
    *Distance = EARTH_RAD * acos(sinArrLat * sinDepLat + cosArrLat * cosDepLat * cosDepArrLong); /*Calculation of the distance between the given Coordinates according to the formula*/
}

void Output(double Distance)
{
    printf("Flight Distance in km is %.2f", Distance);
}
