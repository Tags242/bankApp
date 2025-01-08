#include "Login.h"
#include "Authentication.h"
#include "User.h"
#include "Repository.h"
#include "AccountMenu.h"
#include <iostream>
using namespace std;

void loginMenu()
{
    User user;
    Authentication auth;
    Repository repo;
    string user_id;
    string password;
    
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;
    cout <<"|                                         Login                                           |"<< endl << endl;
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;

    while(true)
    {
        cout << "user id: ";
        getline(cin,user_id);

        if (auth.authenticateUserId(user_id))//sıkıntılı bütün user_id'lere bakması gerekiyor
        {
            break;
        }
        else
        {
            cout << "user_id doesn't exist" << endl;
        }
    }

    user = repo.readUserData(user_id);
    user.setUserId(user_id);
    
    while(true)
    {
        cout << "password: ";
        getline(cin,password);

        if (auth.authenticatePassword(password, user))
        {
            break;
        }
        else
            cout << "Wrong password." << endl;
    }
    cout << endl;

    AccountMenu(user);
}