/**
    This Class is too solely do all mathematic calculations and return the values.
**/
#ifndef DOMATH_H
#define DOMATH_H
#include "includes.h"
using namespace std;
class DoMath
{
    public:
        DoMath();
        float AreaOf4SidedFigure(float side1, float side2, string shape);//calculate the area of a 4 sided figure
        float AreaOfTrapizium(float side1,float side2, float side3);//calculates the are of the trapezium
        float PerimeterOfTrapizium(float side1, float side2, float side3, float side4);//PerimeterOftarapezium calculation
        float PerimeterOf4SidedFigure(float side1, float side2, string shape);//
        float volumeCalculator(float a1, float a2, string shape);
        float area3dCalculator(float a1, float a2, string shape);
        const float PI = 3.14;//value of Pi
        float temp  = 0;//a temporary variable tpp be returned
};

#endif // DOMATH_H
