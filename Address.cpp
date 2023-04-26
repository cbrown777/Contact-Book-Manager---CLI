// Address.cpp
#include "Address.h"
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;


Address::Address() : home(""), street(""), apt("none"), city(""), state(""), zip(""){

}

Address::Address(string home, string street, string apt, string city, string state, string zip) : home(home), street(street), apt(apt), city(city), state(state), zip(zip){

}

string Address::getHome() const
{
   return home;
}

string Address::getStreet() const
{
   return street;
}

string Address::getApt() const
{
   return apt;
}

string Address::getCity() const
{
   return city;
}

string Address::getState() const
{
   return state;
}

string Address::getZip() const
{
   return zip;
}

void Address::output() const
{
   cout << home << " " << street;
   if (apt != "none")
      cout << ", Apt# " << apt;
   cout << endl;
   cout << city << ", " << state << " " << zip << endl;
}

void Address::input()
{
   char choice;
   cout << "Apartment or House (a/h):> ";
   cin >> choice;
   cout << endl;

   cin.ignore(10, '\n');
   cout << "Enter home number (EX: 141-92)___: ";
   getline(cin, home);
   cout << "Enter street number (EX: 70th RD): ";
   getline(cin, street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      getline(cin, apt);
   }
   else
      apt = "none";

   cout << "Enter city (Ex: Flushing)________: ";
   getline(cin, city);

   cout << "Enter state (EX: NY)_____________: ";
   getline(cin, state);

   cout << "Enter zip code (EX: 11367)_______: ";
   getline(cin, zip);
}

std::ostream& operator <<(std::ostream& out, const Address& a1){
   out << a1.home << " " << a1.street;
   if (a1.apt != "none")
      out << ", Apt# " << a1.apt;
   out << endl;
   out << a1.city << ", " << a1.state << " " << a1.zip << endl;

   return out;
}

std::istream& operator >>(std::istream& in, Address& a1){
   char choice;
   cout << "Apartment or House (a/h):> ";
   cin >> choice;
   cout << endl;

   cin.ignore(10, '\n');
   cout << "Enter home number (EX: 141-92)___: ";
   getline(in, a1.home);
   cout << "Enter street number (EX: 70th RD): ";
   getline(in, a1.street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      getline(in, a1.apt);
   }
   else
      a1.apt = "none";

   cout << "Enter city (Ex: Flushing)________: ";
   getline(in, a1.city);

   cout << "Enter state (EX: NY)_____________: ";
   getline(in, a1.state);

   cout << "Enter zip code (EX: 11367)_______: ";
   getline(in, a1.zip);

   return in;
}