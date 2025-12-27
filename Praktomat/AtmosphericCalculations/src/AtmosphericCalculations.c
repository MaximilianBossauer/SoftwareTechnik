#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Gravity 9.81
#define GasConstant 287
#define PolytropicExponent 1.235
#define TempStandardTrop 288.15
#define RhoStandardTrop 1.225
#define KelvinConvert 273.15 /* Definition of various constants to make the formulas more readable*/

typedef struct /*Sturcture saving different keymarks of Airports, for easier Handling*/
{
    const char *name;
    int latitude;
    int longitude;
    int height;
} Airport;

const Airport *GetAirports(int *count);
void UserInput(int *latitude, int *longitude, int *UserTemp, int *UserPressure);
void ConvertValues(double *KelvinTemp, int *PaPressure, int UserPressure, int UserTemp);
void TotalValues(double *TotalTemp, double *TotalDensity, double KelvinTemp, int PaPressure, int AirportHeight);
void RealDensityCalc(double *RealDensity, double TotalDensity, double TotalTemp, int AirportHeight);
int UserAirportDefinition(int latitude, int longitude, int AirportCount, const Airport *airports);
void DensityHeight(double *HeightDensity, double RealDensity);
void Output(double TotalTemp, double TotalDensity, double RealDensity, double HeightDensity);

int main(void)
{
    int AirportCount, latitude, longitude, UserPressure, UserTemp, PaPressure, AirportHeight;
    double KelvinTemp, TotalTemp, TotalDensity, RealDensity, HeightDensity;
    const Airport *airports = GetAirports(&AirportCount);
    UserInput(&latitude, &longitude, &UserTemp, &UserPressure);
    AirportHeight = UserAirportDefinition(latitude, longitude, AirportCount, airports);
    ConvertValues(&KelvinTemp, &PaPressure, UserPressure, UserTemp);
    TotalValues(&TotalTemp, &TotalDensity, KelvinTemp, PaPressure, AirportHeight);
    RealDensityCalc(&RealDensity, TotalDensity, TotalTemp, AirportHeight);
    DensityHeight(&HeightDensity, RealDensity);
    Output(TotalTemp, TotalDensity, RealDensity, HeightDensity);
    return 0;
}

const Airport *GetAirports(int *AirportCount)
 /*"Database" in which different airports can be saved with their keymarks*/
{
    static Airport airports[] = {
        {"Stuttgart", 48, 9, 388},
        {"Berlin", 52, 13, 37},
        {"Munich", 48, 11, 453},
        {"Frankfurt", 50, 8, 110}};
    *AirportCount = sizeof(airports) / sizeof(airports[0]);
    return airports;
}

void UserInput(int *latitude, int *longitude, int *UserTemp, int *UserPressure)
/*Reads Pressure, Temperature. latitude and longitude of the Airport the Plane is stationed*/
{
    printf("Please enter latitude, longitude, temperature and pressure for the airport: ");
    scanf("%d %d %d %d", latitude, longitude, UserTemp, UserPressure);
}

int UserAirportDefinition(int latitude, int longitude, int AirportCount, const Airport *airports)
/*Makes a case distinction to clarify on which airport the user is*/
{
    for (int i = 0; i < AirportCount; i++) /*Case distinction deciding which airport the plane is on according to given airport and user data*/
    {
        if (airports[i].latitude == latitude && airports[i].longitude == longitude)
        {
            return airports[i].height;
        }
    }
    printf("Wrong coordinates entered!"); /*When no database match is found exit the program*/
    exit(1);
}
void ConvertValues(double *KelvinTemp, int *PaPressure, int UserPressure, int UserTemp)
/*Converts the temperature from degree celcius to kelvin and the pressure from hPa to Pa*/
{    *KelvinTemp = UserTemp + KelvinConvert;
    *PaPressure = UserPressure * 100;
}

void TotalValues(double *TotalTemp, double *TotalDensity, double KelvinTemp, int PaPressure, int AirportHeight)
/*Calculates the total temperature and the total density*/
{
    *TotalTemp = KelvinTemp + ((PolytropicExponent - 1) / PolytropicExponent) * (Gravity / GasConstant) * AirportHeight;
    *TotalDensity = PaPressure / (GasConstant * *TotalTemp);
}

void RealDensityCalc(double *RealDensity, double TotalDensity, double TotalTemp, int AirportHeight)
/*Computes the real density out of the total density according to the formula*/
{
    double exponent = 1.0 / (PolytropicExponent - 1.0);
    *RealDensity = TotalDensity * pow((1 - ((PolytropicExponent - 1) / PolytropicExponent) * (Gravity / (GasConstant * TotalTemp)) * AirportHeight), (exponent));
}
void DensityHeight(double *HeightDensity, double RealDensity)
/*Calculates the Density of the height with the constants and the real density*/
{
    *HeightDensity = (pow(RealDensity / RhoStandardTrop, (PolytropicExponent - 1)) - 1) * ((-1 * PolytropicExponent) / (PolytropicExponent - 1) * ((GasConstant * TempStandardTrop) / Gravity));
}

void Output(double TotalTemp, double TotalDensity, double RealDensity, double HeightDensity)
/*Prints the total temperature, total pressure, real density and height density*/
{
    printf("T_0 = %.3fK, rho_0 = %.3fkg/m³, rho = %.3fkg/m³, H = %.2fm", TotalTemp, TotalDensity, RealDensity, HeightDensity);
}