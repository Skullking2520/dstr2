#include "User.h"

User::User(const std::string& email) : email(email) {
    inbox.loadFromFile(email + "_InboxLog.txt");
    outbox.loadFromFile(email + "_OutboxLog.txt");
}

// Get user's inbox
Inbox& User::getInbox() {
    return inbox;
}

// Get user's outbox
Outbox& User::getOutbox() {
    return outbox;
}

// Get user's email
std::string User::getEmail() const {
    return email;
}
