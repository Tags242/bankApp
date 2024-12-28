#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "User.h"
#include <string>
using namespace std;

class Repository 
{
    unsigned short user_id;

    void readUserId();
    void writeUserId();

    public:
    Repository();

    void resetUserId();
    void IncrementUserId();
    void addUser(User user);
    unsigned short getUserId();
};

#endif
