/*
Code referenced: https://www.geeksforgeeks.org/convert-alternate-characters-string-upper-case/
*/
#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#include <iostream>
#include "Patients.h"
//#include <fstream>
#include <string>
//#include <vector>
using namespace std;
const int MAX_RX_SIZE = 100;
const int MAX_RX_COLS = 2;

// struct disease {
// 	string name;
// 	vector<string> symptoms;
// 	vector<string> treatments;
// };
// struct drug {
// 	string name;
// 	vector<string> sideEffects;
// 	vector<string> treats;
// };

class Prescription : public Patients
{
private:
	// vector<drug> drugs;
	// vector<disease> diseases;
	// int drugLength;
	// int diseaseLength;
	int arrayLength;
	string Rx[MAX_RX_SIZE][MAX_RX_COLS];

public:
	Prescription();
	int getLength() const;

        void setLength(int);
	void setDrug(string);
	void setMedicine(string);
	void setSideEffects(string);

	void PrescribeMenu(Patients* patient[]);
	void printDrugList() const;
	void convertUpper(string& str);
	// //getters
	// int getDrugLength();
	// int getDiseaseLength();
	// drug getDrug(string name);
	// disease getDisease(string name);
	// // add
	// void addDrug(drug newDrug);
	// void addDisease(disease newDisease);
	// // delete
	// void deleteDrug(string name);
	// void deleteDisease(string name);
};
Prescription::Prescription()
{
	arrayLength = 1;
	for (int i = 0; i < arrayLength; i++)
		for(int j = 0; j < MAX_RX_COLS; j++)
			Rx[i][j] = "null";
}

void Prescription::printDrugList() const
{
	for(int i = 1; i < arrayLength; i++)
	{
		cout << Rx[i][1] << endl;
	}
}

int Prescription::getLength() const
{
        return arrayLength;
}

void Prescription::setLength(int len)
{
        arrayLength = len;
}

void Prescription::setDrug(string drug)
{
	arrayLength++;
	Rx[arrayLength - 1][0] = drug;
}

void Prescription::setMedicine(string medicine)
{
	Rx[arrayLength - 1][1] = medicine;
}

void Prescription::setSideEffects(string se)
{
	Rx[arrayLength - 1][2] = se;
}

// functions 
void Prescription::PrescribeMenu(Patients* patient[])
{
	string drug = " ";
        string patientLast = " ";
        string patientFirst = " ";
        char confirm;
	int index;
	bool searchName = false; 
        cout << "\n---------------Prescribe Menu----------------" << endl;
        cout << "Enter the drug you wish to prescribe: " << endl;
        cout << "(enter 'HELP' for drugs list)" << endl;
        cin >> drug;
	convertUpper(drug);
        if(drug == "HELP")
	{
	        printDrugList();
		cout << "Enter the drug name ONLY you wish to prescribe: " << endl;
		cin >> drug;
	}
        else
		cout << drug << " found" << endl;
        cout << "Enter the patient LAST name you wish to prescribe it to: ";
        cin >> patientLast;
        cout << "Enter the FIRST name: ";
        cin >> patientFirst;
	//patient.findPatientName(patientFirst, patientLast, searchName);
	if(searchName == true)
	{
        	cout << "" << patientLast << ", " << patientFirst << " found." << endl; 
        	cout << "Prescribe " << patientLast << ", " << patientFirst << " " << drug << "?" << endl;
        	cout << "Confirm Y / N: ";
        	cin >> confirm;
        	if(confirm == 'Y' || confirm == 'y')
		{
			cout << "Prescribed " << drug << " to " << patientLast << ", " << patientFirst << endl;
			cout << "Returning to Main Menu" << endl;
		}
		else
			cout << "Not prescribed. Returning to Main Menu" << endl;	
	}
	else
	{
		cout << "Unable to find patient." << endl;
		cout << "\nReturning to Main Menu...." << endl << endl;
	}
	
}

void Prescription::convertUpper(string &str) 
{ 
    int ln = str.length();   
    for (int i=0; i<ln; i++) 
    	if (str[i]>='a' && str[i]<='z') 
        	str[i] = str[i] - 32; 
} 

// // getters
// int Prescription::getDrugLength(){
// 	return drugs.size();
// }
// int Prescription::getDiseaseLength() {
// 	return diseases.size();
// }
// drug Prescription::getDrug(string name) {
// 	if (!drugs.empty()) {
// 		for (int i = 0; i < drugs.size(); i++) {
// 			if (drugs[i].name == name) {
// 				return drugs[i];
// 			}
// 		}
// 		cout << "No drugs in list with that name.";
// 	}
// }
// disease Prescription::getDisease(string name) {
// 	if (!diseases.empty()) {
// 		for (int i = 0; i < drugs.size(); i++) {
// 			if (diseases[i].name == name) {
// 				return diseases[i];
// 			}
// 		}
// 		cout << "No drugs in list with that name.";
// 	}
// }
// // add
// void Prescription::addDrug(drug newDrug) {
// 	drugs.push_back(newDrug);
// }
// void Prescription::addDisease(disease newDisease) {
// 	diseases.push_back(newDisease);
// }

// // delete
// void Prescription::deleteDrug(string name) {
// 	if (!drugs.empty()) {
// 		for (int i = 0; i < drugs.size(); i++) {
// 			if (drugs[i].name == name) {
// 				drugs.erase(drugs.begin()+i);
// 			}
// 		}
// 	}
// }
// void Prescription::deleteDisease(string name) {
// 	if (!diseases.empty()) {
// 		for (int i = 0; i < drugs.size(); i++) {
// 			if (diseases[i].name == name) {
// 				diseases.erase(diseases.begin()+i);
// 			}
// 		}
// 	}
// }

#endif // !HEADER_H