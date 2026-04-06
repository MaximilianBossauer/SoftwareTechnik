#ifndef fms_h
#define fms_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846             /*Redefinition of Pi since my math.h wasnt working correctly*/
static const double EARTH_RAD = 6378.388;

typedef struct Coordinate
{
    double degree;
    double minute;
    double second;
}Coordinate;

typedef struct Airport
{
    char icao[5];
    char iata[4];
    Coordinate latitude;
    Coordinate longitude;
    float heightAMSL;
}Airport;

typedef struct Time
{
    unsigned char hour;
    unsigned char minute;
}Time;

typedef struct FlightPath
{
    char flightPathName[20];
    Airport *pDepartureAirport;
    Airport *pArrivalAirport;
    Time departure;
    Time arrival;
}FlightPath;

typedef struct Airplane
{
    char airplaneName[20];
    char airVehicleRegistration[20];
    struct FlightPath *pFlightPath;
    unsigned int cntFlightPath;
}Airplane;

typedef struct Airline
{
    char airlineName [20];
    Airplane *pAirplane;
    unsigned int cntAirplane;
}Airline;

typedef struct FMS
{
    Airline *pAirline;
    unsigned int cntAirline;
}FMS;

void Generate_Time_Table(FMS * pFMS);
void Generate_Distance_Table(FMS * pFMS);

#endif
