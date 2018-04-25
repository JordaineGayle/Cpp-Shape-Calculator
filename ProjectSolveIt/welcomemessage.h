
#ifndef WELCOMEMESSAGE_H
#define WELCOMEMESSAGE_H
#include "includes.h"
using namespace std;
class WelcomeMessage
{
    public:
        WelcomeMessage();//welcomes the user this is a construction first function and calls by default
        void UserLogin();//calls the user login to login in the user
        string tempUser;//holds the username the user entered
        string tempPass;//holds the password the user entered
    private:
        const string user = "Synser_12";//username
        const string pass = "Ythetric34";//password
};

#endif // WELCOMEMESSAGE_H
