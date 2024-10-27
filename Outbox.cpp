#include "Outbox.h"
#include <iostream>

using namespace std;

Outbox::Outbox() : front(nullptr), rear(nullptr) {}

Outbox::~Outbox() {
    while (!isEmpty()) {
        sendEmail();  // empty the queue one by one
    }
}

void Outbox::addEmail(const Email& email) {
    Node* newNode = new Node(email);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "New email added to outbox.\n";
}

Email Outbox::sendEmail() {
    if (isEmpty()) {
        throw runtime_error("Outbox is empty.");
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;  // if queue is empty, set rear to nullptr
    }
    Email sentEmail = temp->email;
    delete temp;
    return sentEmail;
}

void Outbox::showNextEmail() const {
    if (isEmpty()) {
        cout << "Outbox is empty.\n";
    } else {
        front->email.display();
    }
}

bool Outbox::isEmpty() const {
    return front == nullptr;
}
