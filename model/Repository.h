#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include "User.h"
using namespace std;

class Repository {
private:
    string filePath; // Path to the binary file storing user data

    // Helper methods
    User readUserFromFile(ifstream& inFile) const; // Read a single user from the file
    void writeUserToFile(ofstream& outFile, const User& user) const; // Write a single user to the file

public:
    Repository(const string& file);

    // Check if a username is available
    bool isUsernameAvailable(const string& username) const;

    // Fetch user by username
    User getUserByUsername(const string& username) const;

    // Add a new user
    void addUser(const User& newUser);

    // Update an existing user
    void updateUser(const User& updatedUser);
};

#endif
