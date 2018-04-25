/**
    In this File we create all functions. I will be giving a brief Description of what goes on in here;

    First we want Point to the class DoMath and create a object of pointer to it.

    We want to make sure all our header files are in one place which is the includes.h

    The Class Break down Goes as Follow:

        //We class the SelectDimen function which determine if the user will
        be working with 2D or 3D shapes.

        //After the above, based on what the if statement evaluates to we then call
        Select2DShapes function or Select3dShapes function which has all the shapes based on the
        dimension selected. dimen evaluates to anything other a or b then you will be doing
        menu navigation.

        //If we selected 2D shapes, then we select a shape based on the options given which if correct will then go to the
        Select2DCal which then ask for you calculation method, after that it then calls the metric menu which calls
        showmetricMenu function that displays all the valid metrics the program can accept, which right after the calculation
        function is called based on the if statement. same procedure for 3D shapes


**/
#include "includes.h"
DoMath *math = new DoMath();
UserMenu::UserMenu(){

}
//this is the dimension selection function
void UserMenu::SelectDimen(){
    rlutil::setColor(03);//set the color to cyan
    cout << "\nDimension Menu\n\ta.) 2D Shapes\n\tb.) 3D Shapes\n\tc.) Exit Program\n\td.) Log Out";//shows the different dimensions
    rlutil::setColor(0);//set the text color to default
    cout << "\n\nSelect dimension: ";// tell the user to select the dimension
    cin >> dimen;//hold the value of the dimension selected

    if(dimen == "a" || dimen == "A"){
        Select2DShape();//calls the 2d shapes function based on the option selected
    }else if(dimen == "b" || dimen == "B"){
        Select3DShape();//calls the 3d shapes function based on the option selected
    }else if(dimen == "c" || dimen == "C" || dimen == "-1"){
        ExitProgram();//Exit the program if selected
    }else if(dimen == "d" || dimen == "D"){
        NewUserLogin();//Log out of the program if selected
    }
    else{
        rlutil::setColor(12);
        cout << "\nInvalid Response!";//invalid response if none of the options given are selected
        rlutil::setColor(0);
        SelectDimen();//recursion if you entered and invalid input// the function calls back it self which means it will be in a loop until you select the correct option
    }
}

//this function handles the navigational menus output
void UserMenu::NavOptions(int y){
    if(y == 1){
            rlutil::setColor(03);
        cout << "\n\n***************************Exit Options***************************";
    cout << "\n\n\t- -3 for previous menu\n\t- -2 to Log out\n\t- -4 go to Main Menu\n\t- -1 to Logout\n";
    cout << "\n***************************Calculation Area***************************\n\n";
    rlutil::setColor(0);
    }else{

    rlutil::setColor(03);
    cout << "Exit Options\n";
    cout << "\t-1 to Exit\n";
    cout << "\t-2 Main Menu\n";
    cout << "\t-3 to Log Out\n";
    rlutil::setColor(0);
    }
}

//this function basically enable you to select a valid metric unit
void UserMenu::SelectMetric(){
    rlutil::setColor(03);//set the text color to cyan
cout << "Metric Menu\n";
ShowMetricMenu();//show the different metric units available
    NavOptions(0);//show the navigational menu 1
    cout << "\n\nPlease Enter option from menu above (1-8): ";
    cin >> metricUnit;//holds the integer value of the mentri option selected
    if(metricUnit == -1){
        ExitProgram();//exit the program
    }else if(metricUnit == -3){
        NewUserLogin();//log out of the program
    }else if(metricUnit == -2){
        SelectDimen();//main menu
    }
    int x = 0;//declare x as 0;
    //validating user input
    while(!(metricUnit > 0 && metricUnit <=8) || !cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        rlutil::setColor(12);
        cout << "\nInvalid Input->(only numbers are allowed)\n";
        rlutil::setColor(0);
        cout << "\n\nPlease Enter a valid option from the menu above (1-8): ";
        cin >> metricUnit;
        if(metricUnit == -1){
            ExitProgram();
        }else if(metricUnit == -3){
        NewUserLogin();
    }else if(metricUnit == -2){
        SelectDimen();
    }
        x++;//incrementing x by 1

        if(x == 3){
             //show the menu after three invalid input
            ShowMetricMenu();
            x = 0;//setting back x to 0
        }
    }

    //a switch statement to set the Unit variable to the metric unit based on the integer input of metric unit
    switch(metricUnit){
    case 1:
        Unit = UnitsArray[0]; // set Unit to mm
        break;
    case 2:
        Unit = UnitsArray[1]; // set unit to cm and so on..........
        break;
    case 3:
        Unit = UnitsArray[2];
        break;
    case 4:
        Unit = UnitsArray[3];
        break;
    case 5:
        Unit = UnitsArray[4];
        break;
    case 6:
        Unit = UnitsArray[5];
        break;
    case 7:
        Unit = UnitsArray[6];
        break;
    case 8:
        Unit = UnitsArray[7];
        break;
    default:
        cout << "\n\nOption you selected is invalid!\n\n";//redundant input validation will solve so program will never reach here
    }
}

//2DShape selection
void UserMenu::Select2DShape(){
    rlutil::setColor(03);
    //the shape options available
cout << "\n\nShape Menu\n\ta.) Square\n\tb.) Rectangle\n\tc.) Parallelogram\n\td.) Trapezium\n\t0 to Main Menu\n\t-2 to Log Out";
    rlutil::setColor(0);
    cout << "\n\nSelect Shape: ";//ask the user to select a shape
    cin >> Shapeopt;//hold the value of the shape selected

    if(Shapeopt == "a" || Shapeopt == "A" ||Shapeopt == "b" || Shapeopt == "B" ||Shapeopt == "c" || Shapeopt == "C" ||Shapeopt == "d" || Shapeopt == "D"){
        Select2DCal();// Calls the 2D shape calculation functions based on the shape selected
    }else if(Shapeopt == "0"){
        SelectDimen();//back to main menu
    }else if(Shapeopt == "-2"){
        NewUserLogin();//log out of program
    }else if(Shapeopt == "-1"){
        ExitProgram();//exit program
    }else{
        rlutil::setColor(12);
        cout << "\nInvalid Response!\n";
        rlutil::setColor(0);
        Select2DShape();//recursion
    }


}

//3DShape selection
void UserMenu::Select3DShape(){
    rlutil::setColor(03);
cout << "Shape Menu\n\ta.) Cube\n\tb.) Square Pyramid\n\tc.) Cylinder\n\td.) Sphere\n\t- 0 to Main Menu\n\t- -2 to Log Out";
   rlutil::setColor(0);
    cout << "\n\nSelect Shape: ";
    cin >> Shapeopt;

     if(Shapeopt == "a" || Shapeopt == "A" ||Shapeopt == "b" || Shapeopt == "B" ||Shapeopt == "c" || Shapeopt == "C" ||Shapeopt == "d" || Shapeopt == "D"){
        Select3DCal();
    }else if(Shapeopt == "0"){
        SelectDimen();
    }else if(Shapeopt == "-2"){
        NewUserLogin();
    }else if(Shapeopt == "-1"){
        ExitProgram();
    }else{
        rlutil::setColor(12);
        cout << "\nInvalid Response!\n";
        rlutil::setColor(0);
        Select3DShape();
    }
}

//this function is to select the different ways of calculation based on the shape
void UserMenu::Select2DCal(){
    rlutil::setColor(03);
    //the method of calculation menu
    cout << "Calculation Menu\n\ta.) Area\n\tb.) Perimeter\n\t- 0 to Main Menu\n\t- -2 to Log Out\n\t- -3 to Previous Menu";
    rlutil::setColor(0);
    cout << "\n\nSelect Calculation Method: ";//this ask the user to select a method of calculation
    cin >> Shape2D;//holds the value of the method of calculation

    if(Shape2D == "a" || Shape2D == "A"){
            SelectMetric();// the function metric so the user can select a valid metric
            if(Shapeopt == "a" || Shapeopt == "A" ){
                AreaOfSquare();//this calculates the area of the square
            }else if(Shapeopt == "b" || Shapeopt == "B"){
                AreaOfRectPara("Length","Width","Rectangle");//area of the rectangle
            }else if(Shapeopt == "c" || Shapeopt == "C"){
                AreaOfRectPara("Base","Height","Parallelogram");//area of the parallelogram
            }else{
                AreaOfTrap();//area of the trapezium
            }

    }else if(Shape2D == "b" || Shape2D == "B"){
        SelectMetric();// the function metric so the user can select a valid metric
        //this if statements basically calls the different calculators to do perimeter
        if(Shapeopt == "a" || Shapeopt == "A" ){
                PeriOf4SidedFigure("square");
            }else if(Shapeopt == "b" || Shapeopt == "B"){
                PeriOf4SidedFigure("rectangle");
            }else if(Shapeopt == "c" || Shapeopt == "C"){
                PeriOf4SidedFigure("parallelogram");
            }else{
                PeriOfTrap();
            }

    }else if(Shape2D == "0"){
        SelectDimen();//back to main menu
    }else if(Shape2D == "-2"){
        NewUserLogin();//back to login screen
    }else if(Shape2D == "-1"){
        ExitProgram();//exit the software
    }else if(Shape2D == "-3"){
        Select2DShape();//to previous menu
    }else{
        rlutil::setColor(12);
        cout << "\n\nInvalid Response!\n";
        rlutil::setColor(0);
        Select2DCal();//recursion
    }
}

void UserMenu::Select3DCal(){

    rlutil::setColor(03);
    cout << "Calculation Menu\n\ta.) Area\n\tb.) Volume\n\t- 0 to Main Menu\n\t- -2 to Log Out\n\t- -3 to Previous Menu";
    rlutil::setColor(0);
    cout << "\n\nSelect Calculation Method: ";
    cin >> Shape3D;

    if(Shape3D == "a" || Shape3D == "A"){
            SelectMetric();
            if(Shapeopt == "a" || Shapeopt == "A" ){
                volAreaMath("cube",1);
            }else if(Shapeopt == "b" || Shapeopt == "B"){
                volAreaMath("sp",1);
            }else if(Shapeopt == "c" || Shapeopt == "C"){
                volAreaMath("cyl",1);
            }else{
                volAreaMath("blank",1);
            }

    }else if(Shape3D == "b" || Shape3D == "B"){
        SelectMetric();
        if(Shapeopt == "a" || Shapeopt == "A" ){
                volAreaMath("cube",0);
            }else if(Shapeopt == "b" || Shapeopt == "B"){
                volAreaMath("sp",0);
            }else if(Shapeopt == "c" || Shapeopt == "C"){
                volAreaMath("cyl",0);
            }else{
                volAreaMath("blank",0);
            }

    }else if(Shape3D == "0"){
        SelectDimen();
    }else if(Shape3D == "-2"){
        NewUserLogin();
    }else if(Shape3D == "-1"){
        ExitProgram();
    }else if(Shape3D == "-3"){
        Select3DShape();
    }else{
        rlutil::setColor(12);
        cout << "\n\nInvalid Response!\n";
        rlutil::setColor(0);
        Select3DCal();
    }


}

void UserMenu::ShowMetricMenu(){
    //loop through the UnitArray and display them all
    int x = 0;
    rlutil::setColor(03);
    cout << "These are all valid units\n\n";
    for(x = 0; x < 8; x++){
        cout << x+1 << ".) "<<UnitsArray[x] << "\n";
    }
    rlutil::setColor(0);
}

void UserMenu::NewUserLogin(){
//Logout the user
    side1 = 0;
    side2= 0;
    side3 = 0;
    result = 0;
    int y = 10;
        while(y > 0){
          cout << "You Have Been Logged Out.....Reconnecting......" <<y<<"s\n\n";
        Sleep(800);
        y--;
        system("cls");
        }
        WelcomeMessage newLogin;
        newLogin.UserLogin();
        SelectDimen();
}

void UserMenu::ExitProgram(){
    //exits the software
    int x = 10;

    while(x > 0){
        cout << "Program Closing in: " << x <<"s\n\n";
        Sleep(800);
        x--;
        system("cls");
    }
    rlutil::setColor(92);
    cout << "Thanks for using, Goodbye!";
    rlutil::setColor(0);
    Sleep(800);
    exit(0);
}

void UserMenu::AreaOfSquare(){
   NavOptions(1);//show the navigational menu 2
    cout << "\nEnter length: ";
    cin >> side1;//holds the value of the length the user entered
    MenuControl(side1,0,0);//determine weather the want to leave the program, logout or previous menu
    while(!cin){//validating user input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        rlutil::setColor(12);
        cout << "\nInvalid Input->(only numbers are allowed)\n";
        rlutil::setColor(0);
        cout << "\nEnter a valid length: ";
        cin >> side1;
        MenuControl(side1,side2,side3);//determine weather the want to leave the program, logout or previous menu
    }
    result = math->AreaOf4SidedFigure(side1,0,"square");//calls on the DoMath function to return a value after calculated
    rlutil::setColor(13);
    cout << "\nThe area of Square is: "<<result<<Unit<<square << "\n\n";// output the answer to the user
    rlutil::setColor(0);
    AreaOfSquare();//recursion calls this function over and over never ending unless you navigate else where
}

void UserMenu::AreaOfRectPara(string shape1, string shape2, string shape){
   rlutil::setColor(03);
    NavOptions(1);
    rlutil::setColor(0);
    cout << "Enter " <<shape1<<": ";
    cin >> side1;
    MenuControl(side1,0,0);
       while(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        rlutil::setColor(12);
        cout << "\nInvalid Input->(only numbers are allowed)\n";
        rlutil::setColor(0);
        cout << "\nPlease Enter a valid " <<shape1<<": ";
        cin >> side1;
        MenuControl(side1,0,0);
       }
    cout << "\nEnter " <<shape2<<": ";
    cin >> side2;
    MenuControl(0,side2,0);
    while(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        rlutil::setColor(12);
        cout << "\nInvalid Input->(only numbers are allowed)\n";
        rlutil::setColor(0);
        cout << "\nPlease Enter a valid " <<shape2<<": ";
        cin >> side2;
        MenuControl(0,side2,0);
    }
    result = math->AreaOf4SidedFigure(side1,side2,"");
    rlutil::setColor(13);
    cout << "\nThe area of "<< shape <<" is: "<<result<<Unit<<square << "\n\n";
    rlutil::setColor(0);
    AreaOfRectPara(shape1,shape2,shape);

}

void UserMenu::AreaOfTrap(){
        NavOptions(1);
        cout << "Enter Base1: ";
        cin >> side1;
        MenuControl(side1,0,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nEnter a valid Base1: ";
            cin >> side1;
            MenuControl(side1,0,0);
        }
        cout << "\nEnter Base2: ";
        cin >> side2;
        MenuControl(0,side2,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nEnter a valid Base2: ";
            cin >> side2;
            MenuControl(0,side2,0);
        }
        cout << "\nEnter Height: ";
        cin >> side3;
        MenuControl(side1,side2,side3);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
             rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nEnter a valid Height: ";
            cin >> side3;
            MenuControl(side1,side2,side3);
        }
        result = math->AreaOfTrapizium(side1,side2,side3);
         rlutil::setColor(13);
        cout << "\nThe area of Parallelogram is: "<<result<<Unit<<square << "\n\n";
         rlutil::setColor(0);
        AreaOfTrap();
}

void UserMenu::PeriOf4SidedFigure(string shape){
    NavOptions(1);
    if(shape == "square"){
        cout <<"\nEnter the length of one side: ";
        cin >> side1;
        MenuControl(side1,side2,side3);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout <<"\nPlease Enter a valid length of any side: ";
            cin >> side1;
            MenuControl(side1,0,0);
        }

        result = math->PerimeterOf4SidedFigure(side1,0,"square");
        rlutil::setColor(13);
        cout << "\n\nThe perimeter of the "<<shape<<" is "<< result <<Unit << "\n\n";
        rlutil::setColor(0);
        PeriOf4SidedFigure(shape);
    }else if(shape == "rectangle" || shape == "parallelogram"){
        cout << "\nPlease Enter Base or Length: ";
        cin >> side1;
        MenuControl(side1,0,0);
         while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nPlease Enter a valid Base or Length: ";
            cin >> side1;
            MenuControl(side1,0,0);
        }

        cout << "\nPlease Enter Height or Width: ";
        cin >> side2;
        MenuControl(0,side2,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nPlease Enter a valid Height or Width: ";
            cin >> side2;
             MenuControl(0,side2,0);
        }

        result = math->PerimeterOf4SidedFigure(side1,side2,"");
        rlutil::setColor(13);
        cout << "\n\nThe perimeter of the "<<shape<<" is "<< result <<Unit << "\n\n";
        rlutil::setColor(0);
        PeriOf4SidedFigure(shape);

    }


}

void UserMenu::PeriOfTrap(){
    NavOptions(1);
    int k = 1, g = 0;
    while(k <= 4){//runs until k == 4
        cout << "\nEnter side"<<k<<": ";
        cin >> side1;
        MenuControl(side1,0,0);
        while(!cin){//validating user input
                cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
          cout << "\nEnter a valid side"<<k<<": ";
        cin >> side1;
        MenuControl(side1,0,0);
        }
        g+=side1;//adds the input of the side1 each time the program increments
        k++;
    }

    result = g;
         rlutil::setColor(13);
        cout << "\nThe perimeter of Trapezium is: "<<result<<Unit<<"\n\n";
         rlutil::setColor(0);
        PeriOfTrap();//recursion
}

void UserMenu::MenuControl(int s1, int s2, int s3){
    //user menu controls this is the navigation pane
if(s1 == -1 || s2 == -1 || s3 == -1){
        ExitProgram();
    }else if(s1 == -2 || s2 == -2 || s3 == -2){
        NewUserLogin();
    }else if(s1 == -3 || s2 == -3 || s3 == -3){
        side1 = 0;
    side2= 0;
    side3 = 0;
    result = 0;
    if(dimen == "a" || dimen == "A"){
        Select2DCal();
    }else if(dimen == "b" || dimen == "B"){
        Select3DCal();
    }

    }else if(s1 == -4 || s2 == -4 || s3 == -4){
        side1 = 0;
    side2= 0;//resetting the sides based on teh if statement
    side3 = 0;
    result = 0;
        SelectDimen();
    }
}

void UserMenu::volAreaMath(string type, int calType){
    //deals with the volume and area calculation of 3D shapes
    NavOptions(1);
    if(type == "cube"){
        cout << "\nEnter value of any Edge: ";
        cin >> side1;
        MenuControl(side1,0,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nEnter a valid Edge value: ";
            cin >> side1;
            MenuControl(side1,0,0);
        }

        //checks weather to call n the volume calculator or the area calculator thats if the calType is 1
        if(calType==1){
            result = math->area3dCalculator(side1,0,type);
            rlutil::setColor(13);
            cout << "\nThe area of Cube is: "<<result<<Unit<<square<<"\n\n";
            rlutil::setColor(0);
        }else{
            result = math->volumeCalculator(side1,0,type);
            rlutil::setColor(13);
            cout << "\nThe volume of Cube is: "<<result<<Unit<<cu<<"\n\n";
            rlutil::setColor(0);
        }
        volAreaMath(type,calType);
    }else if(type == "sp"){
        cout << "Enter the base edge: ";
        cin  >> side1;
        MenuControl(side1,0,0);
        cout << "\nEnter the height: ";
        cin >> side2;
        MenuControl(0,side2,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "Enter a valid base edge: ";
            cin  >> side1;
            MenuControl(side1,0,0);
            cout << "\nEnter a valid height: ";
            cin >> side2;
            MenuControl(0,side2,0);

        }
//checks weather to call n the volume calculator or the area calculator thats if the calType is 1
        if(calType == 1){
            result = math->area3dCalculator(side1,side2,type);
            rlutil::setColor(13);
            cout << "\nThe area of Square Pyramid is: "<<result<<Unit<<square<<"\n\n";
            rlutil::setColor(0);
        }else{
            result = math->volumeCalculator(side1,side2,type);
            rlutil::setColor(13);
            cout << "\nThe volume of Square Pyramid is: "<<result<<Unit<<cu<<"\n\n";
            rlutil::setColor(0);
        }
        volAreaMath(type,calType);//recursion

    }else if(type == "cyl"){

        cout << "Enter the radius: ";
        cin  >> side1;
        MenuControl(side1,0,0);
        cout << "\nEnter the height: ";
        cin >> side2;
        MenuControl(0,side2,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "Enter a valid radius: ";
            cin  >> side1;
            MenuControl(side1,0,0);
            cout << "\nEnter a valid height: ";
            cin >> side2;
            MenuControl(0,side2,0);

        }
//checks weather to call n the volume calculator or the area calculator thats if the calType is 1
        if(calType == 1){
            result = math->area3dCalculator(side1,side2,type);
            rlutil::setColor(13);
            cout << "\nThe area of Cylinder is: "<<result<<Unit<<square<<"\n\n";
            rlutil::setColor(0);
        }else{
            result = math->volumeCalculator(side1,side2,type);
            rlutil::setColor(13);
            cout << "\nThe volume of Cylinder is: "<<result<<Unit<<cu<<"\n\n";
            rlutil::setColor(0);
        }

        volAreaMath(type, calType);//recursion
    }else{
        cout << "\nEnter the radius: ";
        cin >> side1;
        MenuControl(side1,0,0);
        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            rlutil::setColor(12);
            cout << "\nInvalid Input->(only numbers are allowed)\n";
            rlutil::setColor(0);
            cout << "\nEnter any valid radius: ";
            cin >> side1;
            MenuControl(side1,0,0);
        }

        if(calType == 1){
            result = math->area3dCalculator(side1,0,type);
            rlutil::setColor(13);
            cout << "\nThe area of Sphere is: "<<result<<Unit<<square<<"\n\n";
            rlutil::setColor(0);
        }else{
            result = math->volumeCalculator(side1,0,type);
            rlutil::setColor(13);
            cout << "\nThe volume of Sphere is: "<<result<<Unit<<cu<<"\n\n";
            rlutil::setColor(0);
        }
        volAreaMath(type,calType);
    }
}
