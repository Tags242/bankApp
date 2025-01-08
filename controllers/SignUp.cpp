#include "SignUp.h"
#include "Authentication.h"
#include "User.h"
#include "Validation.h"
#include "Repository.h"
#include "AccountMenu.h"
#include <iostream>
using namespace std;

void SignUpMenu()
{
    User user;
    Validation validate;
    Repository repo;
    
    string name;
    string surname;
    string password;
    string password1;

    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;
    cout <<"|                                      Sign Up                                            |"<< endl << endl;
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;


    while (true)
    {
        cout << "Name: ";
        getline(cin, name);

        if (validate.validateUser(name))
        {
            user.setName(name);
            break;
        }
        else
        {
            cout << "Name should only contain letters." << endl;
        }
    }

    while (true)
    {
        cout << "Surname: ";
        getline(cin, surname);

        if (validate.validateUser(surname))
        {
            user.setSurname(surname);
            break;
        }
        else
        {
            cout << "Surname should only contain letters." << endl;
        }
    }

    while (true)
    {   
        cout << "password must be 8 characters minimum, no spaces, with uppercase and lowercase letters." << endl;
        cout << "Password: ";
        getline(cin, password);

        if (validate.validatePassword(password))
        {
            user.setPassword(password);
            break;
        }
    }


    user.setBalance(100);

    //repo.resetUserId();

    repo.addUser(user);

    unsigned short user_id = repo.getUserId();
    user.setUserId(to_string(user_id));
    
    cout <<endl<< "user_id: " << repo.getUserId() << " (note your id! You can only login with using your user_id.)" << endl;;
    cout << "press enter to continue..." << endl;

    string dummy; 
    getline(cin, dummy);    
    
    AccountMenu(user);
}