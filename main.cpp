#include "EM.h"
#include "Inbox.h"
#include "Outbox.h"
#include "EL.h"
#include <iostream>

using namespace std;

void displayMenu()
{
    cout << "\n==== Email Management System ====\n";
    cout << "1. Create Email\n";
    cout << "2. Add Email to Inbox/Outbox\n";
    cout << "3. View Latest Email in Inbox\n";
    cout << "4. Remove Latest Email from Inbox\n";
    cout << "5. View Next Email in Outbox\n";
    cout << "6. Send Next Email in Outbox\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

void email_list()
{
    cout << "\n==== Email List ====\n";
    cout << "1. View Email List\n";
    cout << "2. Add Email to Inbox\n";
    cout << "3. Add Email to Outbox\n";
    cout << "4. Back to Main Menu\n";
    cout << "Choose an option: ";
}

int main()
{
    Inbox inbox;
    Outbox outbox;
    int choice;
    EmailList emailList;

    while (true)
    {
        displayMenu();
        cin >> choice;
        cin.ignore(); // clear entry buffer

        if (choice == 1)
        {
            Email email = createEmail();
            emailList.addEmail(email);
        }
        else if (choice == 2)
        {
            int choice1;
            while (true)
            {
                email_list();
                cin >> choice1;
                cin.ignore();
                if (choice1 == 1)
                {
                    emailList.displayEmails();
                }
                else if (choice1 == 2)
                {
                    cout << "\nWhich Email do you like to add to Inbox?\n";
                    int choice2;
                    cin >> choice2;
                    cin.ignore();
                    if (emailList.isThere(choice2)==true)
                    {
                        Email email = emailList.getEmailAt(choice2);
                        emailList.removeEmailAt(choice2);
                        inbox.addEmail(email);
                        cout << "\nEmail added Successfully!\n";
                    }
                    else
                    {
                        cout << "\nNo Email existing in the index\n";
                    }
                }
                else if (choice1 == 3)
                {
                    cout << "\nWhich Email do you like to add to Outbox?\n";
                    int choice2;
                    cin >> choice2;
                    cin.ignore();
                    if (emailList.isThere(choice2)==true)
                    {
                        Email email = emailList.getEmailAt(choice2);
                        emailList.removeEmailAt(choice2);
                        outbox.addEmail(email);
                        cout << "\nEmail added Successfully!\n";
                    }
                    else
                    {
                        cout << "\nNo Email existing in the index\n";
                    }
                }
                else if (choice1 == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option. Please try again.\n";
                }
            }
        }
        else if (choice == 3)
        {
            inbox.showLatestEmail();
        }
        else if (choice == 4)
        {
            if (!inbox.isEmpty())
            {
                Email latest = inbox.getLatestEmail();
                cout << "\nRemoved email:\n"
                     << latest.getInfo() << endl;
            }
            else
            {
                cout << "Inbox is empty.\n";
            }
        }
        else if (choice == 5)
        {
            outbox.showNextEmail();
        }
        else if (choice == 6)
        {
            if (!outbox.isEmpty())
            {
                Email sent = outbox.sendEmail();
                cout << "\nSent email:\n"
                     << sent.getInfo() << endl;
            }
            else
            {
                cout << "Outbox is empty.\n";
            }
        }
        else if (choice == 7)
        {
            cout << "Exiting Email Management System. Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
