/**
    - Program Name: Geometric Calculator
    - Developer: Jordaine Gayle
    - Date Started: 08/10/2017
    - Date Completed: 19/10/2017
    - Purpose Of Program: This program was solely developed to calculate specific geometric shapes,
    features of this software are advance and robust. The algorithms used in here are 100% functional
    and flexible.

    - About the Software: This software is no ordinary Geometric calculator. We created it for the public,
    it's also open source so that you can add to in your own methods of calculation. It is fully customizable
    and easy to use. Very user friendly and direct.

    - Problem Statement: Develop an algorithm that solves for the area,perimeter and volume for any four 3D and 2D shapes.

**/

#include "includes.h" //This is a manual header file that has all included headers that we will be using through the software
using namespace std;
int main()
{
    system("color F0");//set the console background to white and the font to black

    WelcomeMessage User; // this is a object to reference properties of the WelcomeMessage Class

    UserMenu UMenu; // this is a object to reference properties of the UserMenu Class
    User.UserLogin(); // The object called on the UserLogin() function of the UserMenu Class

    rlutil::setColor(03); // setting the text color to cyan
    cout << "\n\n\t\tMenu";
    rlutil::setColor(0);// resetting the text color to default

    UMenu.SelectDimen(); // The same object called another function from the UserMenu Class which is the Selection of the dimension weather 2D or 3D

    getchar();
    return 0;
}

