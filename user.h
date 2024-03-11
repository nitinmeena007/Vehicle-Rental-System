#ifndef user_h
#define user_h

// including custom headers
#include "storable.cpp"

// including standard cpp headers
#include <string>

using namespace std;

class User : public Storable {

        string name;        // name of user
        string contact;     // contact number of user
        string email;       // email-id of user

    public:
        // constructor
        User(string name, string contact, string email, long recordId=0);

        string getName() const;
        string getContact() const;
        string getEmail() const;

        // set new name of user
        void setName(string newName);

        // set contact number of user
        void setContact(string newContact);

        // set new email-id of user
        void setEmail(string newMail);

        // display record on screen
        void display() const;

        // overriden virtual method
        string toString() const;
        void setDataFrom(Storable *s);
};

#endif