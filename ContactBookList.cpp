// ContactBookList.cpp
#include "ContactBookList.h"
#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::cin;
using std::string;
using std::endl;


ContactBookList::ContactBookList() : maxNumContactBooks(5), numContactBooks(0), contactBooks(new ContactBook*[5]){

}

void ContactBookList::printDetails(){
  cout << "The maximum # of Contact Books: " << maxNumContactBooks << endl;
  cout << "The current # of Contact Books: " << numContactBooks << endl;
}

int ContactBookList::getNumContactBooks() const{
  return numContactBooks;
}

ContactBook** ContactBookList::getContactBooks(){
    return contactBooks;
}

void ContactBookList::fileInAddContactBook(ContactBook* book){
  contactBooks[numContactBooks++] = book;
}

void ContactBookList::addContactBook(){
  if(numContactBooks == maxNumContactBooks){
    cout << "Error: A maximum of 5 Contact Books may be added to the list. There are currently " << numContactBooks << " in the list. Please delete one or more Contact Books before attempting to add another! \n";
  }else{
    string fname, lname;
    cout << "What is the first name of the owner of this contact book?" << endl;
    cin >> fname;
    cout << "What is the last name of the owner of this contact book?" << endl;
    cin >> lname;
    ContactBook* book = new ContactBook(fname, lname);
    contactBooks[numContactBooks++] = book;
  }
}

void ContactBookList::deleteContactBook(){
  string fname, lname;
  cout << "What is the first name of the owner of this contact book?" << endl;
  cin >> fname;
  cout << "What is the last name of the owner of this contact book?" << endl;
  cin >> lname;
  int index = this->returnIndexOfContactBook(fname, lname);

  if(index == -1){
      cout<<"\nContact Book not found."<<endl;
    }else{
      numContactBooks--;
      if(index < numContactBooks){
        contactBooks[index] = contactBooks[numContactBooks];
      }
    cout<<"\nContact Book Deleted"<<endl;
  }
}

int ContactBookList::returnIndexOfContactBook(string fname, string lname) {
     for(int i = 0; i < numContactBooks; i++){
        if(fname == contactBooks[i]->getFirstName() && lname == contactBooks[i]->getLastName()){
            return i;
        }
    }
    return -1;
}

void ContactBookList::displayAllContactBooks(){
  for(int i = 0; i < numContactBooks; i++){
    cout << "\n\nContact Book Owner # = " << i << endl;
    contactBooks[i]->displayEntireContactList();
    cout<< "\n\n-----------------------------------------------------" << endl;
  }
}

void ContactBookList::mergeContactBooks(){
  string fnameOne, lnameOne, fnameTwo, lnameTwo;
    cout << "What is the first name of the owner of the contact book you want to add contacts FROM?" << endl;
    cin >> fnameOne;
    cout << "What is the last name of the owner of the contact book you want to add contacts FROM?" << endl;
    cin >> lnameOne;
    cout << "What is the first name of the owner of the contact book you want to add contacts TO?" << endl;
    cin >> fnameTwo;
    cout << "What is the last name of the owner of the contact book you want to add contacts TO?" <<endl;
    cin >> lnameTwo;
    cout << "\n" << endl;
    int indexOne = this->returnIndexOfContactBook(fnameOne, lnameOne);
    int indexTwo = this->returnIndexOfContactBook(fnameTwo, lnameTwo);

    if(indexOne == -1 || indexTwo == -1){
      cout << "One of your contacts wasn't found!" << endl;
      return;
    }else{
      contactBooks[indexOne]->mergeContactsIntoOtherBook( (contactBooks[indexTwo]) );
    }
}

void ContactBookList::modifyContactBook(){
  string fname, lname;
  cout << "What is the first name of the owner of this contact book?" << endl;
  cin >> fname;
  cout << "What is the last name of the owner of this contact book?" << endl;
  cin >> lname;
  int index = this->returnIndexOfContactBook(fname, lname);

  if(index == -1){
    cout << "Contact Book does not exist!" << endl;
  }else{
    char userInput = getUserInput();
    if(userInput == 'a'){
      Contact* c = new Contact();
      contactBooks[index]->addContact(c);
    }else if(userInput == 'b'){
      contactBooks[index]->deleteContact();
    }else if(userInput == 'c'){
      contactBooks[index]->displayContactInfo();
    }else if(userInput == 'd'){
      contactBooks[index]->updateContactInfo();
    }else if(userInput == 'e'){
      cout << *(contactBooks[index]);
    }
  }
}

char ContactBookList::getUserInput(){
    char userInput;
    cout << endl;
    cout << "Here are some options for making/updating your contact book:" << endl;
    cout << "a) add new contact " << endl;
    cout << "b) delete old contact " << endl;
    cout << "c) display contact info " << endl;
    cout << "d) update contact info " << endl;
    cout << "e) display entire contact book " << endl;
    do{
      cout << "Please enter a-e: ";
      cin >> userInput;
    }while (isNotValidChar(userInput));
    return userInput;
}

bool ContactBookList::isNotValidChar(char userInput){
  return !(userInput == 'a' || userInput == 'b' || userInput == 'c' || userInput == 'd' || userInput == 'e');
}