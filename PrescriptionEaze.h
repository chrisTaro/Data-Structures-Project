#ifndef PRESCRIPTIONEAZE_H
#define PRESCRIPTIONEAZE_H
#include <iostream>
#include <fstream>
#include "Patients.h"
#include "Prescription.h"
using namespace std;
const int MAX_PATIENTS = 2000;
const int MAX_PATS_COLS = 3;

template<class ItemType>
class PrescriptionEaze : public Patients, public Prescription
{
private:
        int length;
        ItemType data[MAX_PATIENTS][MAX_PATS_COLS];
public:
        PrescriptionEaze();
        // getters
        int getLength() const;
        // setters
        void setLength(int);
        // toPrescribe
        // to
};

template<class ItemType>
PrescriptionEaze<ItemType>::PrescriptionEaze()
{
	for (int i = 0; i < length; i++)
		for(int j = 0; j < MAX_PATS_COLS; j++)
			data[i][j] = "null";
}
// getters
template<class ItemType>
int PrescriptionEaze<ItemType>::getLength() const
{
        return length;
}

// setters
template<class ItemType>
void PrescriptionEaze<ItemType>::setLength(int len)
{
        length = len;
}

#endif