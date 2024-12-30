#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
User::User() 
{
    name = "";
    surname = "";
    password = "";
    user_id = "";
    balance = 0;
}

// Getters
string User::getName() 
{
    return name; 
}

string User::getSurname() 
{
    return surname; 
}

string User::getPassword() 
{
    return password;
}

string User::getUserId() {

    return user_id;
}

int User::getBalance() 
{
    return balance;
}

// Setters
void User::setName(string& newName) 
{
    name = newName;
}

void User::setSurname(string& newSurname) 
{
    surname = newSurname;
}

void User::setPassword(string& newPassword) 
{
    password = newPassword;
}

void User::setUserId(string& newUserId)
{
    user_id = newUserId;
}

void User::setBalance(int bal) 
{
    balance = bal; 
}
