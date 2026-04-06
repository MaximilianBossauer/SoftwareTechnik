#include "fms.h"

const Coordinate HamburgLatitude = {53, 37, 49};
const Coordinate HamburgLongitude = {9, 59, 18};
const Coordinate MunichLatitude = {48, 21, 14};
const Coordinate MunichLongitude = {11, 47, 10};
const Coordinate FrankfurtLatitude = {50, 1, 59};
const Coordinate FrankfurtLongitude = {8, 34, 14};
const Coordinate BerlinLatitude = {52, 21, 44};
const Coordinate BerlinLongitude = {13, 30, 2};
const Coordinate DusseldorfLatitude = {51, 16, 51};
const Coordinate DusseldorfLongitude = {6, 45, 26};
const Coordinate CologneLatitude = {50, 51, 57};
const Coordinate CologneLongitude = {7, 8, 34};
const Coordinate StuttgartLatitude = {48, 41, 24};
const Coordinate StuttgartLongitude = {9, 13, 19};

Airport Hamburg = {"EDDH", "HAM", HamburgLatitude, HamburgLongitude, 16};
Airport Munich = {"EDDM", "MUC", MunichLatitude, MunichLongitude, 453};
Airport Frankfurt = {"EDDF", "FRA", FrankfurtLatitude, FrankfurtLongitude, 111};
Airport Berlin = {"EDDB", "BER", BerlinLatitude, BerlinLongitude, 47};
Airport Dusseldorf = {"EDDL", "DUS", DusseldorfLatitude, DusseldorfLongitude, 45};
Airport Cologne = {"EDDK", "CGN", CologneLatitude, CologneLongitude, 92};
Airport Stuttgart = {"EDDS", "STR", StuttgartLatitude, StuttgartLongitude, 389};

FlightPath LufthansaFlightPaths[5] = {
    {"LH 2147", &Munich, &Dusseldorf, {11, 30}, {14, 30}},
    {"LH 2147", &Dusseldorf, &Berlin, {15, 30}, {16, 30}},
    {"LH 2147", &Berlin, &Cologne, {18, 30}, {20, 30}},
    {"LH 2147", &Cologne, &Munich, {20, 45}, {22, 00}},
    {"LH 2147", &Munich, &Dusseldorf, {22, 30}, {23, 30}}};

FlightPath EuroWingsFlightPaths[5] = {
    {"EW 5953", &Hamburg, &Stuttgart, {8, 00}, {10, 00}},
    {"EW 5953", &Stuttgart, &Berlin, {10, 15}, {13, 00}},
    {"EW 5953", &Berlin, &Frankfurt, {13, 10}, {15, 00}},
    {"EW 5953", &Frankfurt, &Hamburg, {15, 12}, {17, 00}},
    {"EW 5953", &Hamburg, &Frankfurt, {22, 00}, {24, 00}},
};

FlightPath TuiFlightPaths[5] = {
    {"X3 2174", &Hamburg, &Stuttgart, {8, 00}, {10, 00}},
    {"X3 2174", &Stuttgart, &Berlin, {10, 15}, {13, 00}},
    {"X3 2174", &Berlin, &Frankfurt, {13, 10}, {15, 00}},
    {"X3 2174", &Frankfurt, &Hamburg, {15, 12}, {17, 00}},
    {"X3 2174", &Hamburg, &Frankfurt, {22, 00}, {24, 00}},
};

Airplane A380 = {"A380", "D-AIMA", LufthansaFlightPaths, sizeof(LufthansaFlightPaths) / sizeof(FlightPath)};
Airplane A320 = {"A320", "D-AIAB", EuroWingsFlightPaths, sizeof(EuroWingsFlightPaths) / sizeof(FlightPath)};
Airplane B747 = {"B747", "D-ABCD", TuiFlightPaths, sizeof(TuiFlightPaths) / sizeof(FlightPath)};

const Airline Lufthansa = {"Lufthansa", &A380, 1};
const Airline Eurowings = {"Eurowings", &A320, 1};
const Airline TUIFly = {"TUIFly", &B747, 1};

Airline airlines[3] = {Lufthansa, Eurowings, TUIFly};

FMS BLABLA = {airlines, 3};