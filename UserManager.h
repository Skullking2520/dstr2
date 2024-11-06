#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "User.h"
#include <string>
#include <unordered_map>

class UserManager {
public:
    UserManager();

    // User registration
    void addUser(const std::string& email, const std::string& password);

    // User login
    bool login(const std::string& email, const std::string& password);

    // User logout
    void logout();

    // Check if a user is logged in
    bool isLoggedIn() const;

    // Get the currently logged-in user
    User* getCurrentUser() const;

private:
    void loadUsersFromFile(); // Load users from "users.txt"
    void saveUserToFile(const std::string& email, const std::string& password); // Save new user to "users.txt"

    std::unordered_map<std::string, std::string> users; // Map of email and password
    User* currentUser; // Currently logged-in user
};

#endif
