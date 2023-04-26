#include "ContactBookList.h"
#include <iostream>
#include <string>
#include <typeinfo>
//#include <bits/stdc++.h>
#include "stdc++_.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;
using std::exit;
using std::ofstream;
using std::ifstream;

string* tokenize(string& s, const int& sizeOfLineArray, string del = "|"){
      string* strings = new string[sizeOfLineArray];
      int i = 0;
      int start = 0;
      int end = s.find(del);
      while (end != -1) {
          strings[i] = s.substr(start, end - start);
          i++;
          start = end + del.size();
          end = s.find(del, start);
      }
      strings[i] = s.substr(start, end - start);
      return strings;
}

int getNumElementsInArray(string*& strings, const int& sizeOfLineArray){
    int numElements = 0;
    for(int i = 0; i < sizeOfLineArray; i++){
      if(!strings[i].empty()){
        numElements++;
      }
    }
    return numElements;
}

std::ofstream& operator << (std::ofstream& out, ContactBook& book){
  out << book.getFirstName() << "|" << book.getLastName() << "\n";
  for(int i = 0; i < book.getNumContacts(); i++){
    Contact** tempPtr = book.getList();
    out << tempPtr[i]->getFirstname() << "|" << tempPtr[i]->getLastname() << "|" << tempPtr[i]->getPhone() << "|" << tempPtr[i]->getEmail() << "|";
    Address tempAddress = tempPtr[i]->getAddress();
    out << tempAddress.getHome() << "|" << tempAddress.getStreet() << "|" << tempAddress.getApt() << "|" << tempAddress.getCity() << "|" << tempAddress.getState() << "|" << tempAddress.getZip();
    out << "\n";
  }
  out << "endofbook|" << "\n" << "\n";
  return out;
}

void writeToFile(ContactBookList& bigList){
   ofstream fout("outputFile.txt");
   int numContactBooks = bigList.getNumContactBooks();
   for(int i = 0; i < numContactBooks; i++){
     fout << *(bigList.getContactBooks()[i]);
     cout << " contactbook " << i << " written out" << endl;
   }
   cout << "\nContact books written out to 'outputFile.txt' " << endl;
   fout.close();
}


int main(){
  ContactBookList bigList;

  ifstream fin("contactbooks.txt");
  string test;
  const int sizeOfLineArray = 10;
  ContactBook* book;

  while(!fin.eof()){
    std::getline(fin, test);
    if(std::any_of(std::begin(test), std::end(test), ::isalpha)){
      string* lineInArray = tokenize(test, sizeOfLineArray);
      int numOfElements = getNumElementsInArray(lineInArray, sizeOfLineArray);
      if(numOfElements == 2){
        book = new ContactBook(lineInArray[0], lineInArray[1]);
      }else if(numOfElements == 10){
        Address tempAddress(lineInArray[4], lineInArray[5], lineInArray[6], lineInArray[7], lineInArray[8], lineInArray[9]);
        Contact* tempContact = new Contact(lineInArray[0], lineInArray[1], lineInArray[2], lineInArray[3], tempAddress);
        book->fileInAddContact(tempContact);
      }else if(numOfElements == 1){
        bigList.fileInAddContactBook(book);
        //cout<< "new contact book added!" << endl;
      }
    }
  }
fin.close();

cout << "\nThis is a Contact Book Manager that will manage the contact books of up to 5 different people." << endl;
  while(true){
    string userInput;
    cout << endl;
    cout << "Here are some options for making/updating your contact book. Please enter 1-6: " << endl;
    cout << "1) Create a New Contact Book " << endl;
    cout << "2) Remove Contact Book " << endl;
    cout << "3) Display All Contact Books " << endl;
    cout << "4) Merge 2 Contact Books (add contacts from one book to another) " << endl;
    cout << "5) Select a Contact Book to Add, Delete, Display or Update Contacts" << endl;
    cout << "6) Exit " << "\n" << endl;
    cin >> userInput;
    if(userInput == "1"){
      bigList.addContactBook();
    }else if(userInput == "2"){
      bigList.deleteContactBook();
    }else if(userInput == "3"){
      bigList.displayAllContactBooks();
    }else if(userInput == "4"){
      bigList.mergeContactBooks();
    }else if(userInput == "5"){
      bigList.modifyContactBook();
    }else if(userInput == "6"){
      writeToFile(bigList);
      exit(1);
    }else if(userInput == "7"){
      bigList.printDetails();
    }
  }

  return 0;
}