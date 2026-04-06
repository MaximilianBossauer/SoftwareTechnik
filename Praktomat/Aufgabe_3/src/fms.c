#include "fms.h"
void Generate_Time_Table(FMS *pFMS)
{
    printf("%10s|%10s|%4s|%4s|%9s|%8s|%8s\n",
           "Airline", "Flight No.", "from", "to", "Departure", "Arrival", "Airplane");
    printf("----------|----------|----|----|---------|--------|--------\n");

    for (int i = 0; i < pFMS->cntAirline; i++)
    {
        Airline *airline = &pFMS->pAirline[i];
        for (int a = 0; a < airline->cntAirplane; a++)
        {
            Airplane *airplane = &airline->pAirplane[a];

            for (int b = 0; b < airplane->cntFlightPath; b++)
            {
                FlightPath *flightpath = &airplane->pFlightPath[b];
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

void Generate_Distance_Table(FMS *pFMS)
{
    printf("%10s|%10s|%4s|%4s|%8s\n",
           "Airline", "Flight No.", "from", "to", "Distance");
    printf("----------|----------|----|----|--------\n");
}
