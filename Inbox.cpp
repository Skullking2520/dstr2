#include "Inbox.h"
#include <iostream>

using namespace std;

Inbox::Inbox() : top(nullptr) {}

Inbox::~Inbox() {
    while (!isEmpty()) {
        getLatestEmail();  // empty the stack one by one
    }
}

void Inbox::addEmail(const Email& email) {
    Node* newNode = new Node(email);
    newNode->next = top;
    top = newNode;
    cout << "New email added to inbox.\n";
}

Email Inbox::getLatestEmail() {
    if (isEmpty()) {
        throw runtime_error("Inbox is empty.");
    }
    Node* temp = top;
    top = top->next;
    Email latestEmail = temp->email;
    delete temp;
    return latestEmail;
}

void Inbox::showLatestEmail() const {
    if (isEmpty()) {
        cout << "Inbox is empty.\n";
    } else {
        top->email.display();
    }
}

bool Inbox::isEmpty() const {
    return top == nullptr;
}
