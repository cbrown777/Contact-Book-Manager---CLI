// ContactBook.cpp
#include "ContactBook.h"
#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::cin;
using std::string;
using std::endl;


ContactBook::ContactBook() : list(new Contact*[10]), firstName(" "), lastName(" "), numContacts(0), capacity(10) {

}

ContactBook::ContactBook(string fname, string lname) : list(new Contact*[10]), firstName(fname), lastName(lname), numContacts(0), capacity(10) {

}

string ContactBook::getFirstName() const{
    return firstName;
}

string ContactBook::getLastName() const{
    return lastName;
}

int ContactBook::getNumContacts() const{
    return numContacts;
}

int ContactBook::getCapacity() const{
    return capacity;
}

Contact** ContactBook::getList(){
    return list;
}

void ContactBook::setFirstName(string fName){
    firstName = fName;
}

void ContactBook::setLastName(string lName){
    lastName = lName;
}

void ContactBook::setCapacity(int newCapacity){
  capacity = newCapacity;
}

void ContactBook::setNumContacts(int newNumContacts){
  numContacts = newNumContacts;
}

void ContactBook::setList(Contact** newList){
  list = newList;
}

void ContactBook::addContact(Contact* c){
    if(numContacts == capacity){
		    cout<<"The contact list is full...Growing now!"<<endl;
		      this->grow();
    }
  cin >> *c;
	list[numContacts++] = c;
  this->sort();
}

void ContactBook::fileInAddContact(Contact* c){
    if(numContacts == capacity){
		    cout<<"The contact list is full...Growing now!"<<endl;
		      this->grow();
    }

	list[numContacts++] = c;
  this->sort();
}

void ContactBook::grow(){
    capacity = capacity+4;
    Contact** temp = new Contact*[capacity];
    for(int i = 0; i < numContacts; i++){
        temp[i] = list[i];
        cout << "Transferred contact: " << i << endl;
    }
    delete [] list;
    list = temp;
}

void ContactBook::sort(){
  for(int p = 0; p < numContacts - 1; p++){
    int indexOfSmallest = p;
    for(int i = p+1; i < numContacts; i++){
      if(*(list[i]) < *(list[indexOfSmallest])){
        indexOfSmallest = i;
      }
    }
    if(p != indexOfSmallest){
      swapValues(list[p], list[indexOfSmallest]);
    }
  }
}

void ContactBook::swapValues(Contact*& a, Contact*& b){
  Contact* temp = a;
  a = b;
  b = temp;
}

void ContactBook::deleteContact(){
    string fname, lname;

    cout << "What is the first name of the contact you wish to delete?" << endl;
    cin >> fname;
    cout << "What is the last name of the contact you wish to delete?" << endl;
    cin >> lname;

    int index = this->returnIndexOfContact(fname, lname);

    if(index == -1){
      cout<<"Contact not found."<<endl;
	  }else{
		  numContacts--;
		  if(index < numContacts){
			  list[index] = list[numContacts];
		  }
		  cout<<"Contact Deleted"<<endl;
	  }

    this->sort();
}

void ContactBook::mergeContactsIntoOtherBook(ContactBook*& otherContactBook){
  int otherBookNumContacts = otherContactBook->getNumContacts();
  int capacityNeeded = this->getNumContacts() + otherBookNumContacts;
  Contact** otherList = otherContactBook->getList();
  Contact** temp = new Contact*[capacityNeeded+2];
  for(int i = 0; i < otherBookNumContacts; i++){
    temp[i] = otherList[i];
  }
  for(int i = 0; i < numContacts; i++){
    temp[otherBookNumContacts++] = list[i];
  }
  delete [] otherList;
  otherContactBook->setList(temp);
  otherContactBook->setCapacity(capacityNeeded+2);
  otherContactBook->setNumContacts(capacityNeeded);
  cout << "\n Contacts merged!" << endl;
}

void ContactBook::displayContactInfo() {
    string fname, lname;

    cout << "What is the first name of the contact you wish to display?" << endl;
    cin >> fname;
    cout << "What is the last name of the contact you wish to display?" << endl;
    cin >> lname;

    int index = this->returnIndexOfContact(fname, lname);

    if(index == -1){
        cout << "\nContact not found..." << endl;
    }else{
        cout << "\nContact found!" << "\n" << endl;
        cout << *(list[index]);
    }
}

int ContactBook::returnIndexOfContact(string fname, string lname) {
     for(int i = 0; i < numContacts; i++){
        if(fname == list[i]->getFirstname() && lname == list[i]->getLastname()){
            return i;
        }
    }
    return -1;
}

void ContactBook::updateContactInfo(){
    string fname, lname, addressResponse, phoneResponse, updatedPhoneNumber, emailResponse, updatedEmail;

    cout << "What is the first name of the contact you wish to update?" << endl;
    cin >> fname;
    cout << "What is the last name of the contact you wish to update?" << endl;
    cin >> lname;

    int index = this->returnIndexOfContact(fname, lname);

    if(index == -1){
        cout << "Contact not found..." << endl;
    }else{
        cout << "Would you like to update address? [y/n]" << endl;
        cin >> addressResponse;
        if(addressResponse == "y"){
            Address updatedAddress;
            updatedAddress.input();
            list[index]->setAddress(updatedAddress);
        }

        cout << "Would you like to update phone number? [y/n]" << endl;
        cin >> phoneResponse;
        if(phoneResponse == "y"){
            cout << "Please enter the updated phone number: ";
            cin >> updatedPhoneNumber;
            list[index]->setPhone(updatedPhoneNumber);
        }

        cout << "Would you like to update email? [y/n]" << endl;
        cin >> emailResponse;
        if(emailResponse == "y"){
            cout << "Please enter the updated email: ";
            cin >> updatedEmail;
            list[index]->setEmail(updatedEmail);
        }
    }
}

void ContactBook::displayEntireContactList() {
  if(numContacts == 0){
		cout<<"\n" << firstName << " " << lastName << " doesn't have any contacts saved at the moment."<<endl;
	}else{
    cout << "\n" << "Contact Book Owner: " << firstName << " " << lastName << endl;
    cout << "Number of Contacts: " << numContacts << endl;
		for(int i = 0; i<numContacts; i++){
			std::cout<<"\n";
			cout << *(list[i]);
		}
	}
}

std::ostream& operator <<(std::ostream& out, const ContactBook& cb1){
    cout<< "\n" << endl;
    if(cb1.numContacts == 0){
      cout << "No contacts..." << endl;
    }else{
      for(int i = 0; i < cb1.numContacts; i++){
          cout << *(cb1.list[i]);
          cout << endl;
      }
    }
    return out;
}

/*
std::istream& operator >>(std::istream& in, ContactBook& cb1){

   //this->addContact();



    for(int i = 0; i < cb1.numContacts; i++){
        if(cb1.Contacts[i].getFirstname() == "default" && cb1.Contacts[i].getLastname() == "default"){
            cin >> cb1.Contacts[i];
            return in;
        }
    }
    cout << "Sorry, the contact list is full..." << endl;
    return in;


}
*/

//destructor
ContactBook::~ContactBook(){
    if(list != NULL){
        for(int i = 0; i < numContacts; i++){
            delete list[i];
        }
        delete [] list;
        list = NULL;
    }
}

//copy constructor
ContactBook::ContactBook(const ContactBook& other) : list(new Contact*[other.capacity]), firstName(other.firstName), lastName(other.lastName), numContacts(other.numContacts), capacity(other.capacity){
    for(int i = 0; i < numContacts; i++){
        *(list[i]) = *(other.list[i]);
    }
}

//assignment operator
ContactBook& ContactBook::operator =(const ContactBook& other){
    if(this != &other){
        if(list != NULL){
            for(int i = 0; i < numContacts; i++){
                delete list[i];
            }
            delete [] list;
        }

        firstName = other.firstName;
        lastName = other.lastName;
        numContacts = other.numContacts;
        capacity = other.capacity;
        list = new Contact*[other.capacity];

        for(int i = 0; i < numContacts; i++){
            *(list[i]) = *(other.list[i]);
        }
    }
    return *this;
}