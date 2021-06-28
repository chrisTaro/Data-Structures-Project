/*

*/
#ifndef PATIENTS_H
#define PATIENTS_H
#include <iostream>
#include <fstream>
using namespace std;
const int MAX_ITEMS = 15;

class Patients 
{
private:
        int idNum;
        string firstName;
        string lastName;
        string address;
        string city;
        int zipCode;
        string phone;
        int length;
public:
        Patients();      // constructor
        // getters
        int Hash() const;
        int getIDNum() const;
        string getFirst() const;
        string getLast() const;
        string getAddress() const;
        string getCity() const;
        int getZipCode() const;
        string getPhone() const;
        // setters
        void setIDNum(int);
        void setFirst(string);
        void setLast(string);
        void setAddress(string);
        void setCity(string);
        void setZipCode(int);
        void setPhone(string);
        void setLength(int);
        //other functions
        void toPrint();
};

int Patients::Hash() const
// Post: Returns an integer between 0 and MAX_ITEMS -1.
{
  return (idNum % MAX_ITEMS);
}

Patients::Patients()
{       
        idNum = -1;
        firstName = "null";
        lastName = "null";
        address = "null";
        city = "null";
        zipCode = 000000;
        phone = "null";
        length = 0;
}
int Patients::getIDNum() const
{
        return idNum;
}
string Patients::getFirst() const
{
        return firstName;
}
string Patients::getLast() const
{
        return lastName;
}
string Patients::getAddress() const
{
        return address;
}
string Patients::getCity() const
{
        return city;
}
int Patients::getZipCode() const
{
        return zipCode;
}
string Patients::getPhone() const
{
        return phone;
}
//setters
void Patients::setIDNum(int ID)
{
        idNum = ID;
}
void Patients::setFirst(string first)
{
        firstName = first;
}
void Patients::setLast(string last)
{
        lastName = last;
}
void Patients::setAddress(string addy)
{
        address = addy;
}
void Patients::setCity(string ct)
{
        city = ct;
}
void Patients::setZipCode(int zc)
{
        zipCode = zc;
}
void Patients::setPhone(string p)
{
        phone = p;
}
void Patients::setLength(int len)
{
        length = len;
}

void Patients::toPrint()
{
        cout << getIDNum() << endl;
        cout << getFirst() << endl;
        cout << getLast() << endl;
        cout << getAddress() << endl;
        cout << getCity() << endl;
        cout << getZipCode() << endl;
        cout << getPhone() << endl;
}
#endif