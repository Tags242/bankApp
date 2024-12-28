#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string name;
    string surname;
    string password;
    int balance;

public:
    // Constructor
    User();

    // Getters
    string getName();
    string getSurname();
    string getPassword();
    int getBalance();

    // Setters
    void setName(string& name);
    void setSurname(string& surname);
    void setPassword(string& password);
    void setBalance(int bal);
};

#endif
