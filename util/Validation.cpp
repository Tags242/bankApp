#include "Validation.h"
#include "User.h"
#include <string> 
#include <fstream> 

bool Validation::validateUser(string username)
{
    if (username == "")
    {
        return false;
    }

    for (size_t i = 0; i < username.length(); i++)
    {
        if (!(username[i] >= 'a' && username[i] <= 'z' || username[i] >= 'A' && username[i] <= 'Z'))
        {
            return false;
        }

    }

    return true;
}

bool Validation::validatePassword(string password)
{

    if (password.length() < 8)
    {
        return false; 
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasNum = false;
    bool hasSpace = false;

    for (size_t i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
        {
            hasUpper = true;
        }
        else if (islower(password[i]))
        {
            hasLower = true;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasNum = true;
        }
        else if (password[i] == ' ')
        {
            hasSpace = true;
        }

        if (hasUpper && hasLower && hasNum && !hasSpace)// at least 8 characters uppercase, lowercase, number and doesn't contain space
        {
            return true;
        }
    }
    

    return false;
}
