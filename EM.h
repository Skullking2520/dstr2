#ifndef EM_H
#define EM_H

#include <string>

class Email {
public:
    // creator
    Email(const std::string& sender, const std::string& subject, const std::string& body, 
          const std::string& date = "", int priority = 0);

    // return every info
    std::string getInfo() const;

    // display email edtail
    void display() const;

private:
    std::string sender;    // sender
    std::string subject;   // subject
    std::string body;      // body
    std::string date;      // date
    int priority;          // priority
};

// createEmail
Email createEmail();

#endif
