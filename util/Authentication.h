#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include "User.h"
#include <string> 
using namespace std;

class Authentication {
    User user;
public:
    // Authenticate a user using a username and password
    bool authenticateUsername(string);
    bool authenticatePassword(string);
};

#endif