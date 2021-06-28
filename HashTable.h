/*

Code Reference: 


*/
#ifndef HASH_H
#define HASH_H
#include "Patients.h"
using namespace std;
const int emptyItem = -1;

template<class ItemType>
class HashTable : public Patients
{
private:
        int length;
        ItemType info[MAX_ITEMS];
public:
        HashTable();
        void checkID(int num, bool& idExists);
        void InsertItem(ItemType item, bool& insertOK);
        void RetrieveItem(ItemType& item, bool& found);
        void toEditItem(ItemType item);
        void toResetID(ItemType item);
        void toPrint();
        void toSavePatients(string inputName);
};

template<class ItemType>
HashTable<ItemType>::HashTable()
{
        for(int i = 0; i < MAX_ITEMS; i++)
        {
                info[i].setIDNum(-1);
        }
}

template<class ItemType>
void HashTable<ItemType>::checkID(int num, bool& idExists)
{
        for(int i = 0; i < MAX_ITEMS; i++)
        {
                if(info[i].getIDNum() == num)
                        idExists = true;
        }
}
template<class ItemType>
void HashTable<ItemType>::InsertItem(ItemType item, bool& insertOK)
// Post: item is stored in the array at position item.Hash().
{
        int location;
        location = item.Hash();
        while (info[location].getIDNum() != emptyItem)
                location = (location + 1) % MAX_ITEMS;

        info[location] = item;
        insertOK = true;
}


template<class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType& item, bool& 
found)
{
        int location;
        int startLoc;
        bool moreToSearch = true;
        int probeCount = 0;
        startLoc = item.Hash();
        location = startLoc;
        do
        {
                if (info[location].getIDNum() == item.getIDNum() 
                                || probeCount == MAX_ITEMS)
                        moreToSearch = false;
                else
                        location = (location + 1) % MAX_ITEMS;
                        probeCount++;
        } while (moreToSearch);
        if (info[location].getIDNum() == item.getIDNum())
        {
                item = info[location];
                found = true;
        }

}

template<class ItemType>
void HashTable<ItemType>::toEditItem(ItemType item)
{
        int location;
        location = item.Hash();
        while (info[location].getIDNum() != item.getIDNum())
                location = (location + 1) % MAX_ITEMS;

        info[location] = item;
}

template<class ItemType>
void HashTable<ItemType>::toResetID(ItemType item)
{
        int location;
        location = item.Hash();
        while (info[location].getIDNum() != item.getIDNum())
                location = (location + 1) % MAX_ITEMS;

        info[location].setIDNum(emptyItem);
}

template<class ItemType>
void HashTable<ItemType>::toPrint()
{
        for(int i = 0; i < MAX_ITEMS; i++)
                cout << info[i].getIDNum() << endl;
}

template<class ItemType>
void HashTable<ItemType>::toSavePatients(string outputName)
{
        ofstream outputFile;
        ofstream outputBackup;
        string outputBU = "PatientsBU.txt";

        outputFile.open(outputName.c_str());
	if (outputFile.fail()) 
                cout << "Output file save failed...";
        for(int i = 0; i < MAX_ITEMS; i++)
        {
                if(info[i].getIDNum() == emptyItem)
                        continue;
                else
                {
                        outputFile << info[i].getIDNum();
                        outputFile << ">";
                        outputFile << info[i].getLast();
                        outputFile << ">";
                        outputFile << info[i].getFirst();
                        outputFile << ">";
                        outputFile << info[i].getAddress();
                        outputFile << ">";
                        outputFile << info[i].getCity();
                        outputFile << ">";
                        outputFile << info[i].getZipCode();
                        outputFile << ">";
                        outputFile << info[i].getPhone();
                        outputFile << endl;
                }
        }
        outputFile.close();

        outputBackup.open(outputBU.c_str());
        if (outputBackup.fail()) 
                cout << "Output backup save failed...";

        for(int i = 0; i < MAX_ITEMS; i++)
        {
                if(info[i].getIDNum() == emptyItem)
                        continue;
                else
                {
                        outputBackup << info[i].getIDNum();
                        outputBackup << ">";
                        outputBackup << info[i].getLast();
                        outputBackup << ">";
                        outputBackup << info[i].getFirst();
                        outputBackup << ">";
                        outputBackup << info[i].getAddress();
                        outputBackup << ">";
                        outputBackup << info[i].getCity();
                        outputBackup << ">";
                        outputBackup << info[i].getZipCode();
                        outputBackup << ">";
                        outputBackup << info[i].getPhone();
                        outputBackup << endl;
                }
        }
        outputBackup.close();
}

#endif