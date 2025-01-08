#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "User.h"
#include <string>
using namespace std;

class Repository 
{
    unsigned short user_id;
    User user;

    void readUserId();
    void writeUserId();

    public:
    Repository();

    void resetUserId();
    void IncrementUserId();
    void addUser(User user);
    unsigned short getUserId();
    void sendMoney(User&,string,double);
    void logTransaction(const string& user_id, string& recipient_id, double money);
    void displayTransactions(string& user_id);


    User readUserData(string user_id);
};

#endif
