//**************************************************************************** 
// File name:		06_Polymorphism
// Author:			Corey tobin
// Date:				5/2/2020
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			deliver parcels
//****************************************************************************

#include "Letter.h"
#include "Overnight.h"
#include "Parcel.h"
#include "Postcard.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void openFileForRead (ifstream &inputFile, string fileName);
void closeFileForRead (ifstream &inputFile);
int menuChoice (char &rChoice);
void printAll (Parcel *pcParcel[], int numParcels);
int readAll (Parcel *pcParcel[], ifstream& inFile);
void insure (Parcel *pcParcel[], int numParcel);
void rush (Parcel *pcParcel[], int numParcel);
void deliver (Parcel *pcParcel[], int numParcel);

const int MAX_PARCELS = 25;
const char PRINT = '1';
const char INSURE = '2';
const char RUSH = '3';
const char DELIVER = '4';
const char QUIT = '5';
const char POSTCARD = 'P';
const char LETTER = 'L';
const char OVERNIGHT = 'O';

//****************************************************************************
// Function:	  main
//
// Description:	main driver
//
// Parameters:  None
//
// Returned:	  EXIT_SUCCESS
//****************************************************************************
int main () {
	string headerMessage = "Mail Simulator!\n\n";
	char choice = '0';
	int numParcels = 0;
	Parcel *pcParcel[MAX_PARCELS];
	string fileName = "text.txt";
	ifstream inFile;

	openFileForRead (inFile, fileName);

	numParcels = readAll (pcParcel, inFile);

	cout << headerMessage;

	do {
		menuChoice (choice);

		if (choice == PRINT) {
			printAll (pcParcel, numParcels);
		}
		if (choice == INSURE) {
			insure (pcParcel, numParcels);
		}
		if (choice == RUSH) {
			rush (pcParcel, numParcels);
		}
		if (choice == DELIVER) {
			deliver (pcParcel, numParcels);
		}

	} while (choice != QUIT);
	
  return EXIT_SUCCESS;
}


/*****************************************************************************
Function:     openFileForRead

Description:	open the file to read from

Parameters:   inputFile - the file from which to read
							fileName - the name of the file to open

Returned:     none
*****************************************************************************/
void openFileForRead (ifstream &inputFile, string fileName)
{
	bool bFileOpened = false;
	do {
		bFileOpened = true;

		inputFile.open (fileName);
		if (inputFile.fail()) {
			bFileOpened = false;
		}
	} while (bFileOpened == false);
}

/*****************************************************************************
Function:     closeFileForRead

Description:	close the file opened for reading

Parameters:   inputFile - the file being closed

Returned:     none
*****************************************************************************/
void closeFileForRead (ifstream &inputFile) {

	inputFile.close ();
}

/*****************************************************************************
Function:     menuChoice

Description:	display menu and recieve user choice

Parameters:   rChoice - the resultof the users choice

Returned:     rChoice - the users choice
*****************************************************************************/
int menuChoice (char &rChoice) {

	cout << "1. Print All\n2. Add Insurance\n3. Add Rush\n4. Deliver\n5. Quit\n";

	do {
		cout << "\nChoice> ";
		cin >> rChoice;
	} while (rChoice != PRINT && rChoice != INSURE && rChoice != RUSH &&
					 rChoice != DELIVER && rChoice != QUIT);

	return rChoice;
}

/*****************************************************************************
Function:     readAll

Description:	read in all the parcels into the array

Parameters:   pcParcel - array of parcels
							inFile - input operator

Returned:     counter - number of parcels
*****************************************************************************/
int readAll (Parcel *pcParcel[], ifstream &inFile) {
	char prefix;
	int counter = 0;

	do {
		inFile >> prefix;

		if (prefix == POSTCARD) {
			pcParcel[counter] = new Postcard;
		}
		else if (prefix == LETTER) {
			pcParcel[counter] = new Letter;
		}
		else if (prefix == OVERNIGHT) {
			pcParcel[counter] = new Overnight;
		}

		pcParcel[counter]->read(inFile);

		counter++;
	} while (!inFile.eof () && counter < MAX_PARCELS);

	return counter;
}

/*****************************************************************************
Function:     printAll

Description:	print all the parcels to the screen

Parameters:   pcParcel - array of parcels
							numParcels - the number of parcels

Returned:     none
*****************************************************************************/
void printAll (Parcel *pcParcel[], int numParcels) {
	
	cout << endl;

	for (int i = 0; i < numParcels; i++) {
		if (pcParcel[i] != nullptr) {
			pcParcel[i]->print(cout);
		}
	}

	cout << endl;
}

/*****************************************************************************
Function:     insure

Description:	insure the parcel

Parameters:   pcParcel - the array of parcels
							numParcel - the number of parcels

Returned:     none
*****************************************************************************/
void insure (Parcel *pcParcel[], int numParcel) {
	int TID;
	int pos = 0;
	bool bCorrectTID = false;

	cout << endl;
	cout << "TID> ";
	cin >> TID;

	for (int i = 0; i < numParcel; i++) {
		if (pcParcel[i] != nullptr) {
			if (pcParcel[i]->getTid () == TID) {
				pos = i;
				bCorrectTID = true;
			}
		}
	}

	if (bCorrectTID == true) {
		pcParcel[pos]->setInsured (true);
	}
}

/*****************************************************************************
Function:     rush

Description:	add the rush feature to parcels

Parameters:   pcParcel - array of parcels
							numParcel - the number of parcels

Returned:     none
*****************************************************************************/
void rush (Parcel *pcParcel[], int numParcel) {
	int TID;
	int pos = 0;
	bool bCorrectTID = false;

	cout << endl;
	cout << "TID> ";
	cin >> TID;

	for (int i = 0; i < numParcel; i++) {
		if (pcParcel[i] != nullptr) {
			if (pcParcel[i]->getTid () == TID) {
				pos = i;
				bCorrectTID = true;
			}
		}
	}

	if (bCorrectTID == true) {
		pcParcel[pos]->setRush (true);
	}
}

/*****************************************************************************
Function:     deliver

Description:	delivers the parcels

Parameters:   pcParcel - the array of parcels
							numParcel - the number of parcels 

Returned:     none
*****************************************************************************/
void deliver (Parcel *pcParcel[], int numParcel) {
	int TID;
	int pos = 0;
	bool bCorrectTID = false;

	cout << endl;
	cout << "TID> ";
	cin >> TID;
	for (int i = 0; i < numParcel; i++) {
		if (pcParcel[i] != nullptr) {
			if (pcParcel[i]->getTid () == TID) {
				pos = i;
				bCorrectTID = true;
			}
		}
	}

	if (bCorrectTID == true) {
		cout << fixed << setprecision (2);

		cout << "Delivered!\n";

		cout << pcParcel[pos]->getDeliveryDay ();

		cout << " Day, $" << pcParcel[pos]->totalCost () << endl;

		pcParcel[pos]->print (cout);

		delete pcParcel[pos];

		pcParcel[pos] = nullptr;
	}
		
	cout << endl;
}
