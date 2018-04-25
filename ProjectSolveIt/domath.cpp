/**
    This file contains all return functions based on the mathematical calculations

    Created by Jordaine Gayle

    All mathematics was done in this file and the values returned to a void function in another file.
**/
#include "includes.h"
DoMath::DoMath()
{
    //constructor
}
//these are all return functions
float DoMath::AreaOf4SidedFigure(float side1, float side2, string shape){ // this function is responsible for calculating area of two 4 sided figure

    if(shape == "square"){
        return pow(side1,2); // return statement based on the if function
    }

    return side1 * side2; // return state executes the if - statement above evaluates to false

}

float DoMath::AreaOfTrapizium(float side1, float side2, float side3){ // this function is responsible for calculating area of trapezium

    return ((side1 + side2)/2) * side3; // returns a single value
}

float DoMath::PerimeterOf4SidedFigure(float side1, float side2, string shape){// this function does the calculation as it relates to the perimeter of three dimensional shapes
    if(shape == "square"){ // runs if the value that the developer entered is square
        return side1 * 4;
    }

    return 2 * (side1 + side2);//return state executes the if - statement above evaluates to false
}

float DoMath::volumeCalculator(float a1, float a2, string shape){ //calculates the volume of all 3D shapes based on the shape parameter

    if(shape == "cube"){ // calculates the volume if the parameter the developer entered is cube
        temp = pow(a1,3);
        return temp;
    }else if(shape == "sp"){ // calculates the volume if the parameter the developer entered is sp
        temp = pow(a1,2) * (a2/3);
        return temp;
    }else if(shape == "cyl"){ // calculates the volume if the parameter the developer entered is cyl
        temp = PI * pow(a1,2)*a2;
        return temp;
    }else{ // calculates the volume if the parameter the developer entered is anything apart from the above

        temp =  1.33333333333 * PI * pow(a1,3);
        return temp;
    }
}

float DoMath::area3dCalculator(float a1, float a2, string shape){ //calculates the area of all 3D shapes based on the shape parameter
if(shape == "cube"){ // calculates the area if the parameter the developer entered is cube
        temp = 6*(pow(a1,2));
        return temp;
    }else if(shape == "sp"){ // calculates the volume if the parameter the developer entered is sp
        float r = pow(a1,2)/4;
        temp = pow(a1,2) + (2*a1) * sqrt(r+pow(a2,2));
        return temp;
    }else if(shape == "cyl"){ // calculates the volume if the parameter the developer entered is cyl
        temp = (2*PI*a1*a2) + (2*PI*(pow(a1,2)));
        return temp;
    }else{ // calculates the volume if the parameter the developer entered is anything apart from the above
        temp = 4*PI*pow(a1,2);
        return temp;
    }
}
