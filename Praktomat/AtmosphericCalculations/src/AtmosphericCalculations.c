#include <stdio.h>
#include <stdlib.h>

#define Gravity 9.81
#define GasConstant 287
#define PolytropicExponent 1.235
#define TempStandardTrop 288.15
#define RhoStandardTrop 1.225
#define KelvinConvert 273.15

typedef struct
{
    const char *name;
    int latitude;
    int longitude;
    int height;
} Airport;

const Airport *GetAirports(int *count);
void UserInput(int *latitude, int *longitude, int *UserPressure, int *UserTemp);
void ConvertValues(double *KelvinTemp, int *PaPressure, int UserPressure, int UserTemp);
void TotalValues(double *TotalTemp, double *TotalPressure, double KelvinTemp, int PaPressure);

int main(void)
{
    int AirportCount, latitude, longitude, UserPressure, UserTemp, PaPressure;
    double KelvinTemp, TotalTemp, TotalPressure;
    const Airport *airports = GetAirports(&AirportCount);
    UserInput(&latitude, &longitude, &UserPressure, &UserTemp);
    printf("%d %d %d %d", latitude, longitude, UserTemp, UserPressure);
    ConvertValues(&KelvinTemp, &TotalPressure, UserPressure, UserTemp);
    TotalValues(&TotalTemp, &TotalPressure, KelvinTemp, PaPressure);
    return 0;
}

const Airport *GetAirports(int *AirportCount)
{
    static Airport airports[] = {
        {"Stuttgart", 48, 9, 388},
        {"Berlin", 52, 13, 37},
        {"Munich", 48, 11, 453},
        {"Frankfurt", 50, 8, 110}};
    *AirportCount = sizeof(airports) / sizeof(airports[0]);
    return airports;
}

void UserInput(int *latitude, int *longitude, int *UserPressure, int *UserTemp)
{
    printf("Please enter latitude, longitude, UserTemp and UserPressure for the airport:");
    scanf("%d %d %d %d", latitude, longitude, UserTemp, UserPressure);
}

void ConvertValues(double *KelvinTemp, int *PaPressure, int UserPressure, int UserTemp)
{
    *KelvinTemp = UserTemp + KelvinConvert;
    *PaPressure = UserPressure * 100;
}

void TotalValues(double *TotalTemp, double *TotalPressure, double KelvinTemp, int PaPressure)
{
    *TotalTemp = KelvinTemp + ((PolytropicExponent - 1) / PolytropicExponent) * (Gravity / GasConstant);
    *TotalPressure = PaPressure / (GasConstant / *TotalTemp);
}