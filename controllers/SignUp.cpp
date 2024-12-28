#include "SignUp.h"
#include "Authentication.h"
#include "User.h"
#include "Validation.h"
#include "Repository.h"
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
            cout << endl << "Name should only contain letters." << endl;
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
            cout << endl << "Surname should only contain letters." << endl;
        }
    }

    while (true)
    {   
        cout << "Your password needs to be 8 characters long, without spaces, and must contain a number, uppercase, and lowercase letters." << endl;
        cout << "Password: ";
        getline(cin, password);

        if (validate.validatePassword(password))
        {
            cout << endl << "Your password matches the requirements." << endl;
            break;
        }
    }

    while (true)
    {
        cout << "Write your password again: ";
        getline(cin, password1);

        if (password == password1)
        {
            cout << endl << "Password set successfully." << endl;
            user.setPassword(password);
            break;
        }
        else
        {
            cout << endl << "Passwords don't match." << endl;      
        }
    }

    user.setBalance(1000);

    //repo.resetUserId();
    // unsigned short user_id = repo.getUserId();
    // cout << user_id << endl;
    repo.addUser(user);
    // unsigned short user_id1 = repo.getUserId();
    // cout << user_id1 << endl;

    //Accout Menu(user)
}
