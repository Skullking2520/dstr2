#include "EM.h"
#include <iostream>

using namespace std;

// definition
Email::Email(const string& sender, const string& subject, const string& body, 
             const string& date, int priority) 
    : sender(sender), subject(subject), body(body), date(date), priority(priority) {}

// Return Info in one string
string Email::getInfo() const {
    return "From: " + sender + "\n" +
           "Subject: " + subject + "\n" +
           "Date: " + date + "\n" +
           "Priority: " + to_string(priority) + "\n" +
           "Body: " + body;
}

// Display Info
void Email::display() const {
    cout << getInfo() << endl;
}

Email createEmail() {
    string sender, subject, body, date;
    int priority;

    cout << "Enter sender: ";
    getline(cin, sender);
    cout << "Enter subject: ";
    getline(cin, subject);
    cout << "Enter body: ";
    getline(cin, body);
    cout << "Enter date (e.g., 2024-10-27): ";
    getline(cin, date);
    cout << "Enter priority (1 = Low, 2 = Medium, 3 = High): ";
    cin >> priority;
    cin.ignore();  // Clear Entry buffer

    // create and return Email
    return Email(sender, subject, body, date, priority);
}
