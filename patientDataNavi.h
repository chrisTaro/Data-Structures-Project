/*
Code Refernced:
https://stackoverflow.com/questions/7786994/c-getline-isnt-waiting-for-input-from-console-when-called-multiple-times

*/
#ifndef PATIENTDATANAVI_H
#define PATIENTDATANAVI_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Patients.h"
#include "HashTable.h"
enum mainMenu { PRESCRIBE = 1, PATIENTS, SETTINGS, QUIT };
enum PatientMenu {ADD = 1, REMOVE, EDIT, DISPLAY, RETURN_FROM_PATIENT};
enum editPatientMenu {FIRST = 1, LAST, ADDY, CITY, ZIP, PHONE, RETURN_FROM_EDIT};
using namespace std;
void printMainMenu();
void PatientDataMenu(HashTable<Patients>& pTable);
void addPatient(HashTable<Patients>& pTable);
void removePatient(HashTable<Patients>& pTable);
void editPatient(HashTable<Patients>& pTable);
Patients printPatient(HashTable<Patients> pTable);

void printMainMenu()
{
        cout << "\n----------Welcome Doctor to Prescription-Eaze!----------" << endl;
        cout << "Enter the number from the following:" << endl; 
        cout << "1. Prescribe " << endl;
        cout << "2. Patients " << endl;
        cout << "3. Settings " << endl;
        cout << "4. Quit" << endl;
}

void PatientDataMenu(HashTable<Patients>& pTable)
{
        system("CLS");
        int patEntry;
        cout << "\n---------------Patient Database Menu----------------" << endl;
        cout << "Enter the number from the following:" << endl; 
        cout << "1. Add Patient" << endl;
        cout << "2. Remove Patient" << endl;
        cout << "3. Edit Patient's information" << endl;
        cout << "4. Display a Patient's information" << endl;
        cout << "5. Return to Main Menu" << endl;
        cin >> patEntry;
        switch(patEntry)
        {
		case ADD:
		{
                        system("CLS");
			addPatient(pTable);
                        break;
                }
                case REMOVE:
		{
			removePatient(pTable);
                        break;
                }
                case EDIT:
		{
                        system("CLS");
			editPatient(pTable);
                        break;
                }
                case DISPLAY:
		{
                        system("CLS");
			printPatient(pTable);
                        break;
                }
		case RETURN_FROM_PATIENT:
		{
                        cout << "\nReturning to Main Menu...." << endl << endl;
                        break;
		}
		default:
			cout << "Invalid Selection. Please try Again." << endl << endl; 
			break;
        }
}

void addPatient(HashTable<Patients>& pTable)
{
        Patients p;
        string inputStr;
        int id, zip, confirm;
        bool insertOK = false;
        bool idMatch = false;
        cout << "\nPlease fill out the new patients information: " << endl;
        cout << "Set unique, 6-digit ID Num: ";
        cin >> id;
        while(cin.fail())
        {
                cout << "\nValue was not an ID number.";
                cin.clear();
                cin.ignore(20, '\n');
                cout << " Please enter a correct value.";
                cin >> id;  
        }
        pTable.checkID(id, idMatch);
        if(idMatch == true)
        {
                while(idMatch)
                {
                        idMatch = false;
                        cout << "This ID number exists in your patients." << endl;
                        cout << "Please choose another one: ";
                        cin  >> id;
                        pTable.checkID(id, idMatch);
                }
        }
        p.setIDNum(id);
        cin.ignore();
        cout << "Set First Name: ";
        getline(cin, inputStr);
        p.setFirst(inputStr);
        cout << "Set Last Name: ";
        getline(cin, inputStr);
        p.setLast(inputStr);
        cout << "Set Address including APT # if applicable: " << endl;
        getline(cin, inputStr);
        p.setAddress(inputStr);
        cout << "Set City: ";
        getline(cin, inputStr);
        p.setCity(inputStr);
        cout << "Set Zip Code: ";
        cin >> zip;
        p.setZipCode(zip);
        cin.ignore();
        cout << "Set Phone #: ";
        getline(cin, inputStr);
        p.setPhone(inputStr);
        system("CLS");
        cout << "\n********Reviewing Patient's info********" << endl;
        cout << "\nFirst Name: " << p.getFirst() << endl;
        cout << "Last Name: " << p.getLast() << endl;
        cout << "Address: " << p.getAddress() << endl;
        cout << "City: " << p.getCity() << endl;
        cout << "ZipCode: " << p.getZipCode() << endl;
        cout << "Phone #: " << p.getPhone() << endl;
        cout << "\nAdd '" << p.getFirst() << " " << p.getLast() << "' ?" << endl << endl;
        cout << "(You can edit the patient's info in the main Patient's Menu)" << endl;
        cout << "Enter 0 for yes, 1 for no: ";
        cin >> confirm;
        system("CLS");
        if (confirm == 0)
        {
                pTable.InsertItem(p, insertOK);
                if(insertOK == true)
                        cout <<  "\n********" << p.getFirst() << " " << p.getLast() << " added********"  << endl;
        }
        else
                cout <<  p.getFirst() << " " << p.getLast() << " was not added."  << endl; 
        cout << "\nReturning to Main Menu...." << endl << endl;
}

void removePatient(HashTable<Patients>& pTable)
{
        Patients patient;
        int confirm;
        system("CLS");
        patient = printPatient(pTable);
        cout << "\nIs this the patient you'd like to remove?" << endl;
        cout << "Confirm? 0 = Yes, 1 = No: ";
        cin >> confirm;
        if(confirm == 0)
        {
                cout << "Removing '" << patient.getFirst() << " " <<
                                patient.getLast() << "'." << endl;
                patient.setFirst("null");
                patient.setLast("null");
                patient.setAddress("null");
                patient.setCity("null");
                patient.setZipCode(00000);
                patient.setPhone("null");
                pTable.toResetID(patient);
        }
        else
                cout << "No changes made" << endl;
                                
        cout << "\nReturning to Main Menu...." << endl << endl;
}

void editPatient(HashTable<Patients>& pTable)
{
        Patients patient;
        string first, last, address, 
                city, phone;
        int id, zip, confirm;
        int editType = 0;
        int searchID = 0;
        bool found = false;
        int location = 0;
        cout << "\n********Edit Patient's info********" << endl;
        patient = printPatient(pTable);
        do
        {
                cout << "\nWhat part would you like to edit?" << endl;
                cout << "1. First Name" << endl;
                cout << "2. Last Name" << endl;
                cout << "3. Address" << endl;
                cout << "4. City" << endl;
                cout << "5. Zip Code" << endl;
                cout << "6. Phone #" << endl;
                cout << "7. Return to Main Menu" << endl;
                cout << "Enter the number of the patient's info you would like to edit: ";
                cin >> editType;
                switch(editType)
                {
                        case FIRST:
                        {
                                confirm = 0;
                                system("CLS");
                                cin.ignore();
                                cout << "Enter 'new' first name: ";
                                getline(cin, first);
                                cout << "New first name is: " << first << endl;
                                cout << "Confirm? 0 = Yes, 1 = No: ";
                                cin >> confirm;
                                if(confirm == 0)
                                {
                                        patient.setFirst(first);
                                        cout << "\nFirst name changed to: " << first << endl;
                                }
                                else
                                        cout << "No changes made" << endl;
                                
                                break;
                        }
                        case LAST:
                        {
                                confirm = 0;
                                system("CLS");
                                cin.ignore();
                                cout << "Enter 'new' last name: ";
                                getline(cin, last);
                                cout << "New last name is: " << last << endl;
                                cout << "Confirm? 0 = Yes, 1 = No: ";
                                cin >> confirm;
                                if(confirm == 0)
                                {
                                        patient.setLast(last);
                                        cout << "\nLast name changed to: " << last << endl;
                                }
                                else
                                        cout << "No changes made" << endl;
                                
                                break;
                        }
                        case ADDY:
                        {
                                confirm = 0;
                                system("CLS");
                                cin.ignore();
                                cout << "Enter 'new' address: ";
                                getline(cin, address);
                                cout << "New address name is: " << address << endl;
                                cout << "Confirm? 0 = Yes, 1 = No: ";
                                cin >> confirm;
                                if(confirm == 0)
                                {
                                        patient.setAddress(address);
                                        cout << "\nAddress changed to: " << address << endl;
                                }
                                else
                                        cout << "No changes made" << endl;
                                
                                break;
                        }
                        case CITY:
                        {
                                confirm = 0;
                                system("CLS");
                                cin.ignore();
                                cout << "Enter 'new' city: ";
                                getline(cin, city);
                                cout << "New city name is: " << city << endl;
                                cout << "Confirm? 0 = Yes, 1 = No: ";
                                cin >> confirm;
                                if(confirm == 0)
                                {
                                        patient.setCity(city);
                                        cout << "\nCity changed to: " << city << endl;
                                }
                                else
                                        cout << "No changes made" << endl;
                                
                                break;
                        }
                        case ZIP:
                        {
                                confirm = 0;
                                system("CLS");
                                cout << "Enter 'new' zip code: ";
                                cin >> zip;
                                cout << "New zip code is: " << zip << endl;
                                cout << "Confirm? 0 = Yes, 1 = No: ";
                                cin >> confirm;
                                if(confirm == 0)
                                {
                                        patient.setZipCode(zip);
                                        cout << "\nZip Code changed to: " << zip << endl;
                                }
                                else
                                        cout << "No changes made" << endl;
                                
                                break;
                        }
                        case PHONE:
                        {
                                confirm = 0;
                                system("CLS");
                                cin.ignore();
                                cout << "Enter 'new' phone #: ";
                                getline(cin, phone);
                                cout << "New phone # is: " << phone << endl;
                                cout << "Confirm? 0 = Yes, 1 = No: ";
                                cin >> confirm;
                                if(confirm == 0)
                                {
                                        patient.setPhone(phone);
                                        cout << "\nPhone # changed to: " << phone << endl;
                                }
                                else
                                        cout << "No changes made" << endl;
                                
                                break;
                        }
                        case RETURN_FROM_EDIT:
                        {
                                break;
                        }
                        default:
                                cout << "Invalid Selection. Please try Again." << endl << endl; 
                                break;
                }
        } while (editType != RETURN_FROM_EDIT );
        pTable.toEditItem(patient);
        cout << "\nReturning to Main Menu...." << endl << endl;
}

Patients printPatient(HashTable<Patients> pTable)
{
        Patients patient;
        int searchID = 0;
        bool found = false;
        cout << "\nEnter the 6 digit ID number of the patient: ";
        cin >> searchID;  
        while(cin.fail())
        {
                cout << "\nValue was not an ID number.";
                cin.clear();
                cin.ignore(20, '\n');
                cout << " Please enter a correct value.";
                cin >> searchID;  
        }
        patient.setIDNum(searchID);
        pTable.RetrieveItem(patient, found);
        if(found == false)
        {
                cout << "\nPatient not found." << endl;
                cout << "Back to Main menu" << endl;
        }
        else
        {
                cout << "\nFirst Name: " << patient.getFirst() << endl;
                cout << "Last Name: " << patient.getLast() << endl;
                cout << "Address: " << patient.getAddress() << endl;
                cout << "City: " << patient.getCity() << endl;
                cout << "ZipCode: " << patient.getZipCode() << endl;
                cout << "Phone #: " << patient.getPhone() << endl;
        }
        return patient;
}


#endif