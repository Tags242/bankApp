#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
User::User() {
    name = "";
    surname = "";
    password = "";
    balance = 0;
}

// Getters
string User::getName() {
    return name; 
}

string User::getSurname() {
    return surname; 
}

string User::getPassword() {
    return password;
}

int User::getBalance() {
    return balance;
}

// Setters
void User::setName(string& newName) {
    name = newName;
}

void User::setSurname(string& newSurname) {
    surname = newSurname; // Assign the std::string directly
}

void User::setPassword(string& newPassword) {
    password = newPassword; // Assign the std::string directly
}

void User::setBalance(int bal) {
    balance = bal; // Assign the integer directly
}
