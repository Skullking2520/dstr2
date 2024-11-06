#include "UserManager.h"
#include "EM.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void displayMainMenu() {
    cout << "\n==== Email Management System ====\n";
    cout << "1. Sign Up\n";
    cout << "2. Log In\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

void displayUserMenu() {
    cout << "\n==== User Menu ====\n";
    cout << "1. Write Email\n";
    cout << "2. Send Next Email\n";
    cout << "3. View Inbox\n";
    cout << "4. View Outbox\n";
    cout << "5. Log Out\n";
    cout << "Choose an option: ";
}

// Function to log email to file
void logEmail(const string& filename, const Email& email) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Date: " << email.getDate();
        file << "From: " << email.getSender() << "\n";
        file << "To: " << email.getRecipient() << "\n";
        file << "Subject: " << email.getSubject() << "\n";
        file << "Body: " << email.getBody() << "\n";
        file << "--------------------------\n";
        file.close();
    } else {
        cerr << "Error: Unable to open log file.\n";
    }
}

// Function to perform spam filtering
bool spamFilter(const Email& email) {
    // Read spam keywords from file
    ifstream file("spam_keywords.txt");
    vector<string> spamKeywords;
    if (file.is_open()) {
        string keyword;
        while (getline(file, keyword)) {
            spamKeywords.push_back(keyword);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open spam keywords file.\n";
    }

    // Convert email body to lowercase for case-insensitive comparison
    string body = email.getBody();
    transform(body.begin(), body.end(), body.begin(), ::tolower);

    // Check if any spam keyword is present in the email body
    for (const string& keyword : spamKeywords) {
        if (body.find(keyword) != string::npos) {
            cout << "Email detected as spam and will not be sent.\n";
            return true; // Email is spam
        }
    }

    // Currently, the spamKeywords vector is empty, so this will always return false
    return false; // Email is not spam
}

int main() {
    UserManager userManager;
    int choice;

    while (true) {
        if (!userManager.isLoggedIn()) {
            displayMainMenu();
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                string email, password;
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter password: ";
                getline(cin, password);
                userManager.addUser(email, password);
            } else if (choice == 2) {
                string email, password;
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter password: ";
                getline(cin, password);
                userManager.login(email, password);
            } else if (choice == 3) {
                cout << "Exiting Email Management System. Goodbye!\n";
                break;
            } else {
                cout << "Invalid option. Please try again.\n";
            }
        } else {
            displayUserMenu();
            cin >> choice;
            cin.ignore();

            User* currentUser = userManager.getCurrentUser();
            string currentEmail = currentUser->getEmail();

            if (choice == 1) {
                // Write email and add to outbox
                Email email = createEmail(currentEmail);
                currentUser->getOutbox().addEmail(email);
            } else if (choice == 2) {
                // Send next email in outbox
                if (!currentUser->getOutbox().isEmpty()) {
                    Email email = currentUser->getOutbox().sendEmail();

                    // Spam filter check
                    if (spamFilter(email)) {
                        // Email is spam; do not send
                        continue;
                    }

                    // Log to sender's outbox log
                    string senderLogFile = currentEmail + "_OutboxLog.txt";
                    logEmail(senderLogFile, email);
                    currentUser->getOutbox().saveToFile(senderLogFile);

                    // Add email to recipient's inbox
                    string recipientEmail = email.getRecipient();
                    User recipient(recipientEmail);
                    recipient.getInbox().addEmail(email);

                    // Log to recipient's inbox log
                    string recipientLogFile = recipientEmail + "_InboxLog.txt";
                    logEmail(recipientLogFile, email);
                    recipient.getInbox().saveToFile(recipientLogFile);

                    cout << "Email sent to " << recipientEmail << ".\n";
                } else {
                    cout << "Outbox is empty.\n";
                }
            } else if (choice == 3) {
                // View inbox
                currentUser->getInbox().showAllEmails();
            } else if (choice == 4) {
                // View outbox
                currentUser->getOutbox().showAllEmails();
            } else if (choice == 5) {
                // Save user's inbox and outbox before logging out
                string inboxFile = currentEmail + "_InboxLog.txt";
                string outboxFile = currentEmail + "_OutboxLog.txt";
                currentUser->getInbox().saveToFile(inboxFile);
                currentUser->getOutbox().saveToFile(outboxFile);

                userManager.logout();
            } else {
                cout << "Invalid option. Please try again.\n";
            }
        }
    }

    return 0;
}
