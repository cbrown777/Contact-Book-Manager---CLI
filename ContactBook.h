// ContactBook.h
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include <string>

class ContactBook{
  private:
    Contact** list;
    string firstName;
    string lastName;
    int numContacts;
    int capacity;
    void grow();
    void swapValues(Contact*& a, Contact*& b);
    void sort();

  public:
    ContactBook();
    ContactBook(string fname, string lname);

    string getFirstName() const;
    string getLastName() const;
    int getNumContacts() const;
    int getCapacity() const;
    Contact** getList();
    void setFirstName(string fName);
    void setLastName(string lName);
    void setNumContacts(int newNumContacts);
    void setCapacity(int newCapacity);
    void setList(Contact** newList);

    void addContact(Contact* c);
    void fileInAddContact(Contact* c);
    void deleteContact();
    void mergeContactsIntoOtherBook(ContactBook*& otherContactBook);
    void displayContactInfo();
    int returnIndexOfContact(string fname, string lname);
    void updateContactInfo();
    void displayEntireContactList();

    friend std::ostream& operator <<(std::ostream& out, const ContactBook& cb1);
    // friend std::istream& operator >>(std::istream& in, ContactBook& cb1);

    //destructor
    ~ContactBook();
    //copy constructor
    ContactBook(const ContactBook& other);
    //assignment operator
    ContactBook& operator =(const ContactBook& other);
};

#endif