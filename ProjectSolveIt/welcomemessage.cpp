
#include "includes.h"
WelcomeMessage::WelcomeMessage()
{

    cout << "\t\t\tHey, My name is Synthetic i was designed\n\t\t\tto make calculating easier and\n\t\t\tfun!.\n\t\t\tIt was my duty to welcome you all\n\t\t\tremember math is fun so have fun using me to solve problems!";
    system("start welcome.vbs");//calls on a file to get the program talking
}

void WelcomeMessage::UserLogin(){
    cout << "\n\nEnter -1 in any menu to terminate this software.\n\n";
    cout << "\n\n\tEnter Your UserName: ";
    cin >> tempUser;//hold what the user enters

    cout << "\n\tEnter your Password: ";
    cin >> tempPass;//hold the password the user entered

    if(tempPass == "-1" || tempUser == "-1"){

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

        int p = 0, u = 10;

    while (tempUser != user || tempPass != pass){//user validation

        cin.clear();
        rlutil::setColor(12);
        cout << "\n\nIncorrect Credentials";
        rlutil::setColor(0);
        cout << "\n\n\tEnter A Valid UserName: ";
        cin >> tempUser;

        cout << "\n\tEnter A Valid Password: ";
        cin >> tempPass;
        rlutil::setColor(12);
        cout <<"\nAttemps Left: "<<u<<endl;
        rlutil::setColor(0);
        if(u == 0){
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

        if(tempPass == "-1" || tempUser == "-1"){
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

        u--;
    }
        rlutil::setColor(13);
        cout << "\n\nCredentials Match\n\nLoading: ";//loading the program files
        int x = 0;
        char t = 219;
        rlutil::setColor(9);// set the color
        while(x <= 50){
            cout <<t;
            Sleep(100);
            if(x == 50){
                Beep(500,900);
                rlutil::setColor(0);
            }
            x++;
        }
}
