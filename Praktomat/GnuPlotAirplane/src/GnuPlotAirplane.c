#include <stdio.h>
#include <math.h>
#include "gnuplot.h"

void AirplanePlot(void);

int main(void)
{
    AirplanePlot();
    return 0;
}

void AirplanePlot(void)
{
    GnuPlotOpen("airplane plot", "airplane_function");
    float i = 0;
    float ValueX, ValueY;
    while (i <= 10)
    {
        ValueX = i;
        ValueY = 1 - exp(-i);
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    }
    i = 10;
    while (i <= 18)
    {
        ValueX = i;
        ValueY = 20 - (ValueX - 14) * (ValueX - 14);
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    }
    i = 18;
    while (i <= 23)
    {
        ValueX = i;
        ValueY = 1 - exp(-(30 - ValueX));
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    }
    i = 23;
    while (i <= 25)
    {
        ValueX = i;
        ValueY = 2 * ValueX - 45;
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    }
    i = 25;
    while (i <= 27)
    {
        ValueX = i;
        ValueY = 5;
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    }
    i = 27;
    while (i <= 28)
    {
        ValueX = i;
        ValueY = -4.2 * ValueX + 118.4;
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    }
    i=28;
       while (i <= 30){
        ValueX = i;
        ValueY = 1 - exp(-(30-ValueX));
        GnuPlotValue(ValueX, ValueY);
        i = i + 0.1;
    };
    while(i>=28){
         ValueX = i;
        ValueY = -1 + exp(-(30-ValueX));
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
    while (i>= 27)
    {
          ValueX = i;
        ValueY = 4.2 * ValueX - 118.4;
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
    while (i >= 25)
    {
        ValueX = i;
        ValueY = -5;
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
        while (i >= 23)
    {
        ValueX = i;
        ValueY = -2 * ValueX + 45;
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
        while (i >= 18)
    {
        ValueX = i;
        ValueY = -1 + exp(-(30 - ValueX));
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
      while (i >= 10)
    {
        ValueX = i;
        ValueY = -20 + (ValueX - 14) * (ValueX - 14);
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
        while (i >= 0)
    {
        ValueX = i;
        ValueY = -1 + exp(-i);
        GnuPlotValue(ValueX, ValueY);
        i = i - 0.1;
    }
    GnuPlotClose();
}