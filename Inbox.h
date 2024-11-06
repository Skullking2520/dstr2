#ifndef INBOX_H
#define INBOX_H

#include "EM.h"
#include <string>

class Inbox {
public:
    Inbox();
    ~Inbox();

    // Add email to inbox (push onto stack)
    void addEmail(const Email& email);

    // Get the latest email (pop from stack)
    Email getLatestEmail();

    // Show the latest email without removing
    void showLatestEmail() const;

    // Show all emails in inbox
    void showAllEmails() const;

    // Check if inbox is empty
    bool isEmpty() const;

    // Load emails from file
    void loadFromFile(const std::string& filename);

    // Save emails to file
    void saveToFile(const std::string& filename) const;

private:
    struct Node {
        Email email;
        Node* next;
        Node(const Email& email) : email(email), next(nullptr) {}
    };

    Node* top; // Top of the stack

    // Helper function to clear the stack
    void clear();
};

#endif
