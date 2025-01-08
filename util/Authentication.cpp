#include "Authentication.h"
#include "User.h" 
#include <iostream>
#include <string> 
#include <fstream> 
using namespace std;

bool Authentication::authenticateUserId(string user_id)
{
    return true;
}

bool Authentication::authenticatePassword(string password, User user)
{
    string realPassword = user.getPassword();
    if (password == realPassword)
    {
        return true;
    }
    else
        return false;
}
