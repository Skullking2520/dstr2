#ifndef INBOX_H
#define INBOX_H

#include "EM.h"  // Include Email class

class Inbox {
public:
    Inbox();                  // creator
    ~Inbox();                 // extincter

    void addEmail(const Email& email);  // add email (push)
    Email getLatestEmail();             // get last email (pop)
    void showLatestEmail() const;       // diaplay last email (peek)
    bool isEmpty() const;               // check is empty

private:
    struct Node {                       // Node for stack
        Email email;
        Node* next;
        Node(const Email& email) : email(email), next(nullptr) {}
    };

    Node* top;  // node at top of the stack
};

#endif
