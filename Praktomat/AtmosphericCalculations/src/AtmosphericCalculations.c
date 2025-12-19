#include <stdio.h>
#include <stdlib.h>

#define Gravity 9.81
#define GasConstant 287
#define PolytropicExponent 1.235
#define TempStandardTrop 288.15
#define PhiStandardTrop 1.225
#define KelvinConvert 273.15

typedef struct
{
    const char *name;
    int latitude;
    int longitude;
    int height;
} Airport;

const Airport *GetAirports(int *count);

int main(void)
{
    int AirportCount;
    const Airport *airports = GetAirports(&AirportCount);
    printf("%s \n %d", airports[2].name, airports[3].height);
}

const Airport *GetAirports(int *AirportCount)
{
    static Airport airports[] = {
        {"Stuttgart", 48, 9, 388},
        {"Berlin", 52, 13, 37},
        {"Munich", 48, 11, 453},
        {"Frankfurt", 50, 8, 110}
    };
    *AirportCount = sizeof(airports) / sizeof(airports[0]);
    return airports;
}