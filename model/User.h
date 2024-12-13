#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;
    string role;
    int balance;

public:
    // Constructor and Destructor
    User();
    ~User();

    // Getters
    string getUsername() const;
    string getPassword() const;
    string getRole() const;
    int getBalance() const;

    // Setters
    void setUsername(const string& uname);
    void setPassword(const string& pass);
    void setRole(const string& r);
    void setBalance(int bal);
};

#endif
