// Contact.h
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include "Address.h"

class Contact {
    private:
        string firstname, lastname, phone, email;
        Address address;

    public:
        //Constructor
        Contact(string f, string l, string p, string e, Address a);
        Contact();

        //Accessors
        string getLastname() const;
        string getFirstname() const;
        string getPhone() const;
        string getEmail() const;
        Address getAddress() const;

        //Mutators
        void setLastname(string l);
        void setFirstname(string f);
        void setAddress(Address a);
        void setPhone(string p);
        void setEmail(string e);

        void input();
        void output();

        friend std::ostream& operator <<(std::ostream& out, const Contact& c1);
        friend std::istream& operator >>(std::istream& in, Contact& c1);

        bool operator <(const Contact& c1) const;
        bool operator >(const Contact& c1) const;
        bool operator ==(const Contact& c1) const;
        bool operator !=(const Contact& c1) const;
        bool operator <=(const Contact& c1) const;
        bool operator >=(const Contact& c1) const;
};

#endif