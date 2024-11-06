#include "EM.h"
#include <iostream>
#include <ctime>

using namespace std;

// Constructor
Email::Email(const string& sender, const string& recipient, const string& subject,
             const string& body, const string& date)
    : sender(sender), recipient(recipient), subject(subject), body(body), date(date) {}

// Getters
string Email::getSender() const {
    return sender;
}

string Email::getRecipient() const {
    return recipient;
}

string Email::getSubject() const {
    return subject;
}

string Email::getBody() const {
    return body;
}

string Email::getDate() const {
    return date;
}

// Display email details
void Email::display() const {
    cout << "Date: " << date;
    cout << "From: " << sender << "\n";
    cout << "To: " << recipient << "\n";
    cout << "Subject: " << subject << "\n";
    cout << "Body: " << body << "\n";
    cout << "--------------------------\n";
}

// Function to create an email
Email createEmail(const string& sender) {
    string recipient, subject, body;

    cout << "Enter recipient: ";
    getline(cin, recipient);
    cout << "Enter subject: ";
    getline(cin, subject);
    cout << "Enter body: ";
    getline(cin, body);

    // Get current date and time
    time_t now = time(0);
    char* dt = ctime(&now);
    string date(dt);

    return Email(sender, recipient, subject, body, date);
}
