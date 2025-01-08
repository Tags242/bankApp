#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include "User.h"
#include <string> 
using namespace std;

class Authentication 
{
public:
    bool authenticateUserId(string user_id);
    bool authenticatePassword(string password, User user);
};

#endif