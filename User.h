#ifndef USER_H
#define USER_H

#include "Inbox.h"
#include "Outbox.h"
#include <string>

class User {
public:
    User(const std::string& email);

    // Get user's inbox
    Inbox& getInbox();

    // Get user's outbox
    Outbox& getOutbox();

    // Get user's email
    std::string getEmail() const;

private:
    std::string email; // User's email
    Inbox inbox;       // User's inbox
    Outbox outbox;     // User's outbox
};

#endif
