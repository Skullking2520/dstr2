#ifndef OUTBOX_H
#define OUTBOX_H

#include "EM.h"  // Include Email class

class Outbox {
public:
    Outbox();                   // creator
    ~Outbox();                  // extincter

    void addEmail(const Email& email);  // add email (enqueue)
    Email sendEmail();                  // send first email (dequeue)
    void showNextEmail() const;         // show first email on queue
    bool isEmpty() const;               // check is empty

private:
    struct Node {                       // Node for queue
        Email email;
        Node* next;
        Node(const Email& email) : email(email), next(nullptr) {}
    };

    Node* front;  // node at the front of the queue
    Node* rear;   // node at the end of the queue
};

#endif
