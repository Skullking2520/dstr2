#include "UserManager.h"
#include <iostream>
#include <fstream>

using namespace std;

UserManager::UserManager() : currentUser(nullptr) {
    loadUsers();
}

// Load users from a file
void UserManager::loadUsers() {
    ifstream file("users.txt");
    if (file.is_open()) {
        string email, password;
        while (getline(file, email) && getline(file, password)) {
            users[email] = password;
        }
        file.close();
    }
}

// Save users to a file
void UserManager::saveUsers() {
    ofstream file("users.txt");
    if (file.is_open()) {
        for (const auto& pair : users) {
            file << pair.first << "\n" << pair.second << "\n";
        }
        file.close();
    }
}

// Add a new user
void UserManager::addUser(const std::string& email, const std::string& password) {
    if (users.find(email) != users.end()) {
        cout << "User already exists.\n";
        return;
    }
    if (!isValidEmailFormat(email)) {
        cout << "Invalid email format. Please enter a valid email.\n";
        return;
    }
    users[email] = password;
    saveUsers();
    cout << "User registered successfully.\n";
}

// Log in a user
void UserManager::login(const std::string& email, const std::string& password) {
    auto it = users.find(email);
    if (it != users.end() && it->second == password) {
        currentUser = new User(email);
        cout << "Logged in successfully.\n";
    } else {
        cout << "Invalid email or password.\n";
    }
}

// Log out the current user
void UserManager::logout() {
    if (currentUser != nullptr) {
        delete currentUser;
        currentUser = nullptr;
        cout << "Logged out successfully.\n";
    }
}

// Check if a user is logged in
bool UserManager::isLoggedIn() const {
    return currentUser != nullptr;
}

// Get the current user
User* UserManager::getCurrentUser() {
    return currentUser;
}
