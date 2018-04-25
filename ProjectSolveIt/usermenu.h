/**
    This Class Header file is inked to the Class Cpp file usermenu.h -> usermenu.cpp

    This Class is to solely control all user menus

    Developed By: Jordaine Gayle

**/
#ifndef USERMENU_H
#define USERMENU_H
#include "includes.h"//This is a manual header file that has all included headers that we will be using through the software
using namespace std;
class UserMenu // Name Of the Class
{
    public:

        UserMenu(); // This is the class Constructor function the function that gets called automatically// see more at the usermenu.cpp
        //Main Menu Functions Starts here
        void  SelectDimen(); // This function is to help to user to select weather they want to calculate for 2D shapes or 3D// see more at the usermenu.cpp
        void Select2DShape(); // This function shows all 2D shapes and collect an input // see more at the usermenu.cpp file
        void Select3DShape();// This function show all 3D shapes and collect an input // see more at the usermenu.cpp
        void SelectMetric();// This function displays the user metric so that one can select the appropriate value or metric
        void Select2DCal();//this function controls the different calculations that happens based on the shape selected and the calculation method
        void Select3DCal();//this function controls the different calculations that happens based on the shape selected and the calculation method
        //main menu functions Ends here

        //2D Calculations Starts here
        void AreaOfSquare();//this functions simply collect input to and calls a next function to calculate and further show results
        void AreaOfRectPara(string shape1,string shape2, string shape);//this functions simply collect input to and calls a next function to calculate and further show results
        void AreaOfTrap();//this functions simply collect input to and calls a next function to calculate and further show results
        void PeriOf4SidedFigure(string shape);//this functions simply collect input to and calls a next function to calculate and further show results
        void PeriOfTrap();//this functions simply collect input to and calls a next function to calculate and further show results
         //2D Calculations ends here

        //3D Calculations Starts here
        void volAreaMath(string type, int calType);//this functions simply collect input to and calls a next function to calculate and further show results
        //3D Calculations ends here

        //Secondary Menus
        void ShowMetricMenu();
        void NewUserLogin();//Help to user to logout
        void NavOptions(int y);//Helps with the choosing of the different navigational menus
        void ExitProgram();//Solely to end the program from any where
        void MenuControl(int s1, int s2, int s3);//solely to navigate through the 3 above secondary menus
        //Secondary Menus end

        string Unit = "";//blanks variables which holds the metric unit
        string Shapeopt = "";//hold the shape selected
        string dimen = "";//hold the dimension selected
        string Shape2D = "";//holds the shape calculation method
        string Shape3D = "";//holds the shape calculation method
        string UnitsArray[8] = {"mm","cm","ml","m","dam","hm","km","dm"};//an array of the different units the program can read

        int metricUnit;//holds the value of the option selected

        float result = 0,side1 = 0,side2 = 0,side3 = 0, side4 = 0;//all temporary variables past into some return functions in the DoMath Class

        static const char cu = 252; //the character representation of cube
        static const char square = 253;//character representation of square

};

#endif // USERMENU_H
