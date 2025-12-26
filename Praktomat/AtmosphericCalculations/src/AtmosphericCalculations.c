#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Gravity 9.81
#define GasConstant 287
#define PolytropicExponent 1.235
#define TempStandardTrop 288.15
#define RhoStandardTrop 1.225
#define KelvinConvert 273.15 /* Definition of various constants to make the fomulas more readable*/

typedef struct /*Sturcture saving different keymarks of Airports, for easier Handling*/
{
    const char *name;
    int latitude;
    int longitude;
    int height;
} Airport;

const Airport *GetAirports(int *count);
void UserInput(int *latitude, int *longitude, int *UserPressure, int *UserTemp);
void ConvertValues(double *KelvinTemp, int *PaPressure, int UserPressure, int UserTemp);
void TotalValues(double *TotalTemp, double *TotalPressure, double KelvinTemp, int PaPressure, double AirportHeight);
void RealPressureCalc(double *RealPressure, double TotalPressure, double TotalTemp, int AirportHeight);
int UserAirportDefinition(int latitude, int longitude, int AirportCount, const Airport *airports);
void DensityHeight(double *HeightDensity, double RealPressure);
void Output(double TotalTemp, double TotalPressure, double RealPressure, double HeightDensity);

int main(void)
{
    int AirportCount, latitude, longitude, UserPressure, UserTemp, PaPressure, AirportHeight;
    double KelvinTemp, TotalTemp, TotalPressure, RealPressure, HeightDensity;
    const Airport *airports = GetAirports(&AirportCount);
    UserInput(&latitude, &longitude, &UserPressure, &UserTemp);
    AirportHeight = UserAirportDefinition(latitude, longitude, AirportCount, airports);
    ConvertValues(&KelvinTemp, &PaPressure, UserPressure, UserTemp);
    TotalValues(&TotalTemp, &TotalPressure, KelvinTemp, PaPressure, AirportHeight);
    RealPressureCalc(&RealPressure, TotalPressure, TotalTemp, AirportHeight);
    DensityHeight(&HeightDensity, RealPressure);
    void Output(TotalTemp, TotalPressure, RealPressure, HeightDensity);
    return 0;
}

const Airport *GetAirports(int *AirportCount) /*"Database" in which different airports can be saved with their keymarks*/
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
    printf("Please enter latitude, longitude, temperature and pressure for the airport: ");
    scanf("%d %d %d %d", latitude, longitude, UserTemp, UserPressure);
}

int UserAirportDefinition(int latitude, int longitude, int AirportCount, const Airport *airports)
{
    for (int i = 0; i < AirportCount; i++) /*Case distinction deciding which Airport th Plane is on according to given airport and User DAta*/
    {
        if (airports[i].latitude == latitude && airports[i].longitude == longitude)
        {
            return airports[i].height;
        }
    }
    printf("Wrong coordinates entered!"); /*When no database match is found exit the Program*/
    exit(1);
}
void ConvertValues(double *KelvinTemp, int *PaPressure, int UserPressure, int UserTemp)
{    *KelvinTemp = UserTemp + KelvinConvert;
    *PaPressure = UserPressure * 100;
}

void TotalValues(double *TotalTemp, double *TotalPressure, double KelvinTemp, int PaPressure, double AirportHeight)
{
    *TotalTemp = KelvinTemp + ((PolytropicExponent - 1) / PolytropicExponent) * (Gravity / GasConstant) * AirportHeight;
    *TotalPressure = PaPressure / (GasConstant * *TotalTemp);
}

void RealPressureCalc(double *RealPressure, double TotalPressure, double TotalTemp, int AirportHeight)
{
    double exponent = 1.0 / (PolytropicExponent - 1.0);
    *RealPressure = TotalPressure * pow((1 - ((PolytropicExponent - 1) / PolytropicExponent) * (Gravity / (GasConstant * TotalTemp)) * AirportHeight), (exponent));
}
void DensityHeight(double *HeightDensity, double RealPressure)
{
    *HeightDensity = (pow(RealPressure / RhoStandardTrop, (PolytropicExponent - 1)) - 1) * ((-1 * PolytropicExponent) / (PolytropicExponent - 1) * ((GasConstant * TempStandardTrop) / Gravity));
}

void Output(double TotalTemp, double TotalPressure, double RealPressure, double HeightDensity)
{
    printf("T_0 = %.3fK, rho_0 = %.3fkg/m³, rho = %.3fkg/m³, H = %.2fm", TotalTemp, TotalPressure, RealPressure, HeightDensity);
}