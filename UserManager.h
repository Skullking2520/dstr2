#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <string>
#include <map>

class UserManager {
public:
    UserManager();

    // Add a new user
    void addUser(const std::string& email, const std::string& password);

    // Log in a user
    void login(const std::string& email, const std::string& password);

    // Log out the current user
    void logout();

    // Check if a user is logged in
    bool isLoggedIn() const;

    // Get the current user
    User* getCurrentUser();

private:
    std::map<std::string, std::string> users; // Map of email to password
    User* currentUser;
    void loadUsers();
    void saveUsers();
};

#endif
