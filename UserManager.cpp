#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <regex>

UserManager::UserManager() : currentUser(nullptr) {
    loadUsersFromFile(); // Load existing users from file
}

// Add a new user with email validation
void UserManager::addUser(const std::string& email, const std::string& password) {
    // Validate email format using regex
    std::regex email_regex(R"(^[\w\.-]+@[\w\.-]+\.\w+$)");
    if (!std::regex_match(email, email_regex)) {
        std::cout << "Invalid email format. Please try again.\n";
        return;
    }

    if (users.find(email) == users.end()) {
        users[email] = password;
        saveUserToFile(email, password);
        std::cout << "User registered successfully.\n";
    } else {
        std::cout << "User already exists.\n";
    }
}

// User login
bool UserManager::login(const std::string& email, const std::string& password) {
    auto it = users.find(email);
    if (it != users.end() && it->second == password) {
        currentUser = new User(email);
        std::cout << "Login successful. Welcome, " << email << "!\n";
        return true;
    } else {
        std::cout << "Login failed. Invalid email or password.\n";
        return false;
    }
}

// User logout
void UserManager::logout() {
    if (currentUser) {
        delete currentUser;
        currentUser = nullptr;
        std::cout << "Logged out successfully.\n";
    } else {
        std::cout << "No user is currently logged in.\n";
    }
}

// Check if a user is logged in
bool UserManager::isLoggedIn() const {
    return currentUser != nullptr;
}

// Get the currently logged-in user
User* UserManager::getCurrentUser() const {
    return currentUser;
}

// Load users from file
void UserManager::loadUsersFromFile() {
    std::ifstream file("users.txt");
    if (file.is_open()) {
        std::string email, password;
        while (file >> email >> password) {
            users[email] = password;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open users file.\n";
    }
}

// Save new user to file
void UserManager::saveUserToFile(const std::string& email, const std::string& password) {
    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << email << " " << password << "\n";
        file.close();
    } else {
        std::cerr << "Error: Unable to open users file for writing.\n";
    }
}
