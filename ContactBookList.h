// ContactBookList.h
#ifndef CONTACTBOOKLIST_H
#define CONTACTBOOKLIST_H

#include "ContactBook.h"

class ContactBookList{
  private:
    const int maxNumContactBooks;
    int numContactBooks;
    ContactBook** contactBooks;
    int returnIndexOfContactBook(string fname, string lname);
    char getUserInput();
    static bool isNotValidChar(char userInput);

  public:
    ContactBookList();
    int getNumContactBooks() const;
    ContactBook** getContactBooks();
    void printDetails();
    void fileInAddContactBook(ContactBook* book);
    void addContactBook();
    void deleteContactBook();
    void displayAllContactBooks();
    void mergeContactBooks();
    void modifyContactBook();
    void sortAllContactBooks();
};

#endif