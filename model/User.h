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
    double balance;

public:
    // Constructor
    User();

    // Getters
    string getName();
    string getSurname();
    string getPassword();
    string getUserId();
    double getBalance();

    // Setters
    void setName(string& name);
    void setSurname(string& surname);
    void setPassword(string& password);
    void setUserId(const string& userId);
    void setBalance(double bal);
};

#endif
