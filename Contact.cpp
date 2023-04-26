// Contact.cpp
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <regex>
#include "Contact.h"
#include "Address.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::regex;


//Default constructor
Contact::Contact() {
    setFirstname("default");
    setLastname("default");
    setPhone("1234567890");
    setEmail("default@qmail.cuny.edu");
    address = Address();
}

Contact::Contact(string f, string l, string p, string e, Address a){
    setFirstname(f);
    setLastname(l);
    setPhone(p);
    setEmail(e);
    setAddress(a);
}


//Accessors
string Contact::getFirstname() const{
    return firstname;
}

string Contact::getLastname() const{
    return lastname;
}

Address Contact::getAddress() const{
    return address;
}

string Contact::getPhone() const{
    return phone;
}

string Contact::getEmail() const{
    return email;
}


//Mutators
void Contact::setLastname(string l){
    lastname = l;
}

void Contact::setFirstname(string f){
    firstname = f;
}

void Contact::setAddress(Address a){
    address = a;
}

void Contact::setPhone(string p){
/*
    if (p.length() != 10){
        cout << "Incorrect phone number length.\n";
        exit(1);
    }
    else {
        for (int i = 0; i < p.length(); i++){
            if (!isdigit(p[i])) {
                cout << "Phone number contains non-digit.\n";
                exit(1);

            }
        }
    }
*/
    string phonePattern = R"(\d{10})";
    regex regPhone(phonePattern);
    if (regex_match(p, regPhone)) phone = p;
    else {
        cout << "Incorrect phone pattern: looking for a 10-digit number. Goodbye!\n";
        exit(1);
    }
}

void Contact::setEmail(string e){
/*
    int atPos = (int) e.find("@");
    int dotPos = (int) e.rfind(".");
    if (atPos == -1 || dotPos == -1 || dotPos < atPos){
        cout << "Incorrect e-mail.\n";
        exit(1);
    }
*/
    string emailPattern = R"(^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$)";
    regex regEmail(emailPattern);
    if (regex_match(e, regEmail)) email = e;
    else {
        cout << "Incorrect e-mail pattern. Goodbye!\n";
        exit(1);
    }
}

void Contact::input(){
    string f, l, p, e;
    Address a;

    cout << "Please enter first name: ";
    cin >> f;
    setFirstname(f);

    cout << "Please enter last name: ";
    cin >> l;
    setLastname(l);

    cout << "Please enter the address:\n";
    cin >> a;
    setAddress(a);

    cout << "Please enter the phone number: ";
    cin >> p;
    setPhone(p);

    cout << "Pleae enter the e-mail: ";
    cin >> e;
    setEmail(e);
}

void Contact::output(){
    cout << "First name: " << firstname << endl;
    cout << "Last name: " << lastname << endl;
    cout << "Address: " << endl;
    cout << address;
    cout << "Phone number: " << phone << endl;
    cout << "E-mail: "<< email << endl;
}

std::ostream& operator <<(std::ostream& out, const Contact& c1){
    out << "First name: " << c1.firstname << endl;
    out << "Last name: " << c1.lastname << endl;
    out << "Address: " << endl;
    out << c1.address;
    out << "Phone number: " << c1.phone << endl;
    out << "E-mail: "<< c1.email << endl;

    return out;
}

std::istream& operator >>(std::istream& in, Contact& c1){
    cout << "Please enter first name: ";
    in >> c1.firstname;

    cout << "Please enter last name: ";
    in >> c1.lastname;

    cout << "Please enter the address:\n";
    cin >> c1.address;

    cout << "Please enter the phone number: ";
    getline(in, c1.phone);

    cout << "Pleae enter the e-mail: ";
    getline(in, c1.email);

    return in;
}

bool Contact::operator <(const Contact& c1) const{
    if(lastname.compare(c1.getLastname()) == 0){
        if(firstname.compare(c1.getFirstname()) < 0){
            return true;
        }else{
            return false;
        }
    }
    if(lastname.compare(c1.getLastname()) < 0){
        return true;
    }

    return false;
}

bool Contact::operator >(const Contact& c1) const{
    if(lastname.compare(c1.getLastname()) == 0){
        if(firstname.compare(c1.getFirstname()) > 0){
            return true;
        }else{
            return false;
        }
    }
    if(lastname.compare(c1.getLastname()) < 0){
        return false;
    }
    
    return true;
}

bool Contact::operator ==(const Contact& c1) const{
    if( (lastname.compare(c1.getLastname()) == 0) && (firstname.compare(c1.getFirstname()) == 0)){
        return true;
    }else{
        return false;
    }
}

bool Contact::operator !=(const Contact& c1) const{
    if( (lastname.compare(c1.getLastname()) != 0) || (firstname.compare(c1.getFirstname()) != 0)){
        return true;
    }else{
        return false;
    }
}

bool Contact::operator <=(const Contact& c1) const{
    if(*this < c1 || *this == c1){
        return true;
    }else{
        return false;
    }
}

bool Contact::operator >=(const Contact& c1) const{
    if(*this > c1 || *this == c1){
        return true;
    }else{
        return false;
    }
}