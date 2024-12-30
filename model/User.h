#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string name;
    string surname;
    string password;
    string user_id;
    int balance;

public:
    // Constructor
    User();

    // Getters
    string getName();
    string getSurname();
    string getPassword();
    string getUserId();
    int getBalance();

    // Setters
    void setName(string& name);
    void setSurname(string& surname);
    void setPassword(string& password);
    void setUserId(string& userId);
    void setBalance(int bal);
};

#endif
