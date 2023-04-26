// Address.h
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using std::string;

class Address
{
   private:
      string home;
      string street;
      string apt;
      string city;
      string state;
      string zip;

   public:
      // Default constructor
      // Initializes all variable to empty string
      Address();
      Address(string home, string street, string apt, string city, string state, string zip);

      // Accessor method for the home instance variable
      string getHome() const;

      // Accessor method for the street instance variable
      string getStreet() const;

      // Accessor method that returns apartment number
      // if it is an apartment building, or "none" if
      // it is a private house.
      string getApt() const;

      // Accessor method for the city instance variable
      string getCity() const;

      // Accessor method for the state instance variable
      string getState() const;

      // Accessor method for the zip instance variable
      string getZip() const;

      // Method that prints Address to console
      void output() const;

      // Method that solicits the information
      // Apartment will be set to "none" if it is a private house
      // If it is an Apartment Building, method will solicit
      // info about apartment
      void input();

      friend std::ostream& operator <<(std::ostream& out, const Address& a1);
      friend std::istream& operator >>(std::istream& in, Address& a1);
};
#endif

