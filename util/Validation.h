#ifndef VALIDATION_H
#define VALIDATION_H

#include "User.h"
using namespace std;

class Validation {
    User user;
public:

    bool validateUsername(string);
    bool validatePassword(string);
};

#endif