#include "User.h"
#include <iostream>
#include <fstream>
#include <string>   
using namespace std;


//geçici ChatGPT yaptı düzeltilecek

// Constructor
User::User() : username(""), password(""), role("user"), balance(0) {}

// Destructor
User::~User() {}

// Getters
string User::getUsername() const { return username; }
string User::getPassword() const { return password; }
string User::getRole() const { return role; }
int User::getBalance() const { return balance; }

// Setters
void User::setUsername(const string& uname) { username = uname; }
void User::setPassword(const string& pass) { password = pass; }
void User::setRole(const string& r) { role = r; }
void User::setBalance(int bal) { balance = bal; }

