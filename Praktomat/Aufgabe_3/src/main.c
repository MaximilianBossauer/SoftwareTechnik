#include "fms.h"



int main(void)
{
    extern FMS FlightManagementSystem;
    Generate_Time_Table(&FlightManagementSystem);
    Generate_Duration_Table(&FlightManagementSystem);
    Generate_Distance_Table(&FlightManagementSystem);

    return EXIT_SUCCESS;
}
