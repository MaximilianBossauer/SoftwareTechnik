#include "fms.h"
void Generate_Time_Table(FMS * pFMS)
{
    printf("%-10s|%-10s|%-4s|%-4s|%-9s|%-8s|%-8s\n",
           "Airline", "Flight", "No.", "from", "to", "Departure", "Arrival");

Airline *a = &pFMS->pAirline[0];
Airplane *plane = a->pAirplane;

printf("Anzahl FlightPaths: %d\n", plane->cntFlightPath);



}
