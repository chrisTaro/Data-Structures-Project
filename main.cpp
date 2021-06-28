/*
CodeReferenced: 

*/
#include <fstream>
#include <iostream>
#include <sstream>
#include "Patients.h"
#include "HashTable.h"
#include "patientDataNavi.h"
#include <stdlib.h>
//#include "Prescription.h"
//#include "PrescriptionEaze.h"
using namespace std;
void printMainMenu();
void readPatientData(HashTable<Patients>& pTable, string fileName, bool& fileOK);
const char DELIMITOR = '>';

int main() 
{
	HashTable<Patients> patientTable;
        string inputName = "Patients.txt";
        int entry = 0;
        bool openOK = false;
	readPatientData(patientTable, inputName, openOK);
        if(openOK == false)
                cout << "Open File failed...." << endl;
	do
	{
                printMainMenu();
                cin >> entry;
                switch(entry)
		{
			case PRESCRIBE:
			{
                                entry = 0;
                                break;
			}
                        case PATIENTS:
			{
				PatientDataMenu(patientTable);
                                entry = 0;
                                break;
			}
                        case SETTINGS:
			{
				entry = 0;
                                break;
			}
			case QUIT:
			{
				patientTable.toSavePatients(inputName);
                                return 0;
                                break;
			}
			default:
				cout << "Invalid Selection. Please try Again." << endl << endl; 
				break;
		}
	}while(entry != QUIT);
}


void readPatientData(HashTable<Patients>& pTable, string fileName, bool& fileOK)
{
	Patients pat;
	ifstream inputFile;					// Create an object for input file stream
	string inputStr;
	string token;
	string tempStr[6];					// Temporary hold  
	//pTable.initTable();
	bool insertOK = false;
	//Open file for input
	inputFile.open(fileName.c_str());
	//Check to see if file opens successfully, if not return OPEN_ERROR code
	if (inputFile.fail()) 
		fileOK == false;
	else
	{
		//Read data from the input file
		while (getline(inputFile, inputStr)) 
		{
			int index = 0;
			istringstream strStream(inputStr);
			while (getline(strStream, token, DELIMITOR)) 
				tempStr[index++] = token;
			
			pat.setIDNum(stoi(tempStr[0]));
			pat.setLast(tempStr[1]);
			pat.setFirst(tempStr[2]);
			pat.setAddress(tempStr[3]);
			pat.setCity(tempStr[4]);
			pat.setZipCode(stoi(tempStr[5]));
			pat.setPhone(tempStr[6]);
			pTable.InsertItem(pat, insertOK);
		}
	}
	//Close the input file
	inputFile.close();
	fileOK = true;
}


