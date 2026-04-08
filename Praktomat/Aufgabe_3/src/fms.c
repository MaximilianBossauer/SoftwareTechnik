#include "fms.h"
double DurationCalculation(Time *DepartureTime, Time *ArrivalTime);
double DistanceCalculation(Airport *departureAirport, Airport *ArrivalAirport);
double calculateDegree(Coordinate Coordinates);
double sinDeg(double degree);
double cosDeg(double degree);

void Generate_Time_Table(FMS *pFMS)
{
    printf("%10s|%10s|%4s|%4s|%9s|%8s|%8s\n",
           "Airline", "Flight No.", "from", "to", "Departure", "Arrival", "Airplane");
    printf("----------|----------|----|----|---------|--------|--------\n");

    for (int AirlineCounter = 0; AirlineCounter < pFMS->cntAirline; AirlineCounter++)
    {
        Airline *airline = &pFMS->pAirline[AirlineCounter];

        for (int AirplaneCounter = 0; AirplaneCounter < airline->cntAirplane; AirplaneCounter++)
        {
            Airplane *airplane = &airline->pAirplane[AirplaneCounter];

            for (int FlightpathCounter = 0; FlightpathCounter < airplane->cntFlightPath; FlightpathCounter++)
            {
                FlightPath *flightpath = &airplane->pFlightPath[FlightpathCounter];
                printf("%10s|%10s|%4s|%4s|    %02d:%02d|   %02d:%02d|%8s\n",
                       airline->airlineName,
                       flightpath->flightPathName,
                       flightpath->pDepartureAirport->iata,
                       flightpath->pArrivalAirport->iata,
                       flightpath->departure.hour,
                       flightpath->departure.minute,
                       flightpath->arrival.hour,
                       flightpath->arrival.minute,
                       airplane->airVehicleRegistration);
            }
        }
    }
}

void Generate_Duration_Table(FMS *pFMS)
{
    for (int AirlineCounter = 0; AirlineCounter < pFMS->cntAirline; AirlineCounter++)
    {
        printf("%10s|%10s|%4s|%4s|%8s\n",
               "Airline", "Flight No.", "from", "to", "Duration");
        printf("----------|----------|----|----|--------\n");
        Airline *airline = &pFMS->pAirline[AirlineCounter];

        for (int AirplaneCounter = 0; AirplaneCounter < airline->cntAirplane; AirplaneCounter++)
        {
            int TotalHours = 0;
            int TotalMinutes = 0;
            Airplane *airplane = &airline->pAirplane[AirplaneCounter];

            for (int FlightPathCounter = 0; FlightPathCounter < airplane->cntFlightPath; FlightPathCounter++)
            {
                FlightPath *flightpath = &airplane->pFlightPath[FlightPathCounter];
                Time *DepartureTime = &flightpath->departure;
                Time *ArrivalTime = &flightpath->arrival;
                int FlightTotalMinutes = DurationCalculation(DepartureTime, ArrivalTime);
                int FlightHours = FlightTotalMinutes / 60;
                int FlightMinutes = FlightTotalMinutes % 60;
                TotalHours = FlightHours + TotalHours;
                TotalMinutes = FlightMinutes + TotalMinutes;

                printf("%10s|%10s|%4s|%4s|  %02d:%02d\n",
                       airline->airlineName,
                       flightpath->flightPathName,
                       flightpath->pDepartureAirport->iata,
                       flightpath->pArrivalAirport->iata,
                       FlightHours,
                       FlightMinutes);
            }
            /*Normalisation of total flight hours and printing for each separate Aircraft*/
            TotalHours = TotalHours + TotalMinutes / 60;
            TotalMinutes = TotalMinutes % 60;
            printf("Total flight Time for %s %s is %02d:%02d\n", airline->airlineName, airplane->airplaneName, TotalHours, TotalMinutes);
        }
    }
}

double DurationCalculation(Time *DepartureTime, Time *ArrivalTime)
{
    int FlightTotalMinutes = 0;
    int DepartureMinutes = DepartureTime->hour * 60 + DepartureTime->minute;
    int ArrivalMinutes = ArrivalTime->hour * 60 + ArrivalTime->minute;

    if (ArrivalMinutes > DepartureMinutes)
    /*Checks whether the flight crosses midnight as the calculation is different then*/
    {
        FlightTotalMinutes = ArrivalMinutes - DepartureMinutes;
    }
    else
    {
        FlightTotalMinutes = ArrivalMinutes + 24 - DepartureMinutes;
    }

    return FlightTotalMinutes;
}

void Generate_Distance_Table(FMS *pFMS)
{

    for (int AirlineCounter = 0; AirlineCounter < pFMS->cntAirline; AirlineCounter++)
    {
        printf("%10s|%10s|%4s|%4s|%8s\n",
               "Airline", "Flight No.", "from", "to", "Distance");
        printf("----------|----------|----|----|--------\n");
        Airline *airline = &pFMS->pAirline[AirlineCounter];

        for (int AirplaneCounter = 0; AirplaneCounter < airline->cntAirplane; AirplaneCounter++)
        {
            Airplane *airplane = &airline->pAirplane[AirplaneCounter];
            double TotalDistance = 0;

            for (int FlightPathCounter = 0; FlightPathCounter < airplane->cntFlightPath; FlightPathCounter++)
            {

                FlightPath *flightpath = &airplane->pFlightPath[FlightPathCounter];
                Airport *DepartureAirport = flightpath->pDepartureAirport;
                Airport *ArrivalAirport = flightpath->pArrivalAirport;
                double Distance = DistanceCalculation(DepartureAirport, ArrivalAirport);
                TotalDistance = TotalDistance + Distance;
                printf("%10s|%10s|%4s|%4s|%7.2f\n",
                       airline->airlineName,
                       flightpath->flightPathName,
                       flightpath->pDepartureAirport->iata,
                       flightpath->pArrivalAirport->iata,
                       Distance);
            }
            
            /*Prints the total flight time for each aircraft seperately*/
            printf("Total flight distance for %s %s is %.2f\n", airline->airlineName, airplane->airplaneName, TotalDistance);
        }
    }
}
double DistanceCalculation(Airport *departureAirport, Airport *ArrivalAirport)
/*Calculation of Flight Distance using the formula of the curvature of the earth*/
{
    double deplat = calculateDegree(departureAirport->latitude);
    double deplon = calculateDegree(departureAirport->longitude);
    double arrlat = calculateDegree(ArrivalAirport->latitude);
    double arrlon = calculateDegree(ArrivalAirport->longitude);

    double distance = EARTH_RAD * acos(sinDeg(arrlat) * sinDeg(deplat) + cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));

    return distance;
}
double calculateDegree(Coordinate Coordinates)
{
    return Coordinates.degree + Coordinates.minute / 60.0 + Coordinates.second / 3600.0;
}

double sinDeg(double degree)
{
    return sin(degree * M_PI / 180.0);
}

double cosDeg(double degree)
{
    return cos(degree * M_PI / 180.0);
}
