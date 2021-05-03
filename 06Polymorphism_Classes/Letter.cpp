#include "Letter.h"
#include "Parcel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
/*****************************************************************************
Function:     Letter

Description:	constructor for Letter class

Parameters:   none

Returned:     none
*****************************************************************************/
Letter::Letter () : Parcel () {

}

/*****************************************************************************
Function:     getDeliveryDay

Description:	determines how many days it will take to deliver a letter

Parameters:   none

Returned:     days - the number of days taken to deliver the letter
*****************************************************************************/
int Letter::getDeliveryDay () {
  int days;
  int milesPerDay = 100;
  int distance = getDistance ();

  days = distance / milesPerDay;

  if (distance % milesPerDay > 0) {
    days++;
  }

  if (getRush () == true) {
    days--;
  }
  if (days < 1) {
    days = 1;
  }

  return days;
}

/*****************************************************************************
Function:     print

Description:	function for printing out information for the letter

Parameters:   ostream - output operator

Returned:     none
*****************************************************************************/
void Letter::print (ostream &rcOut) {
  Parcel::print (rcOut);

  if (getInsured () == true) {
    rcOut << "\tINSURED";
  }
  if (getRush () == true) {
    rcOut << "\tRUSH";
  }

  cout << endl;
}

/*****************************************************************************
Function:     setInsured

Description:	adds insurance to the letter

Parameters:   bInsured - whether to insure it or not

Returned:     none
*****************************************************************************/
void Letter::setInsured (bool bInsured) {
  Parcel::setInsured (bInsured);

  cout << "Added Insurance for $0.45" << endl;

  print (cout);

  cout << endl;
}

/*****************************************************************************
Function:     setRush

Description:	adds the rush feature to the letter

Parameters:   bRush - whether to rush it or not

Returned:     none
*****************************************************************************/
void Letter::setRush (bool bRush) {
  double rush = getCost () * 0.1;

  cout << fixed << setprecision (2);

  Parcel::setRush (bRush);

  cout << "Added Rush for $" << rush << endl;

  print (cout);

  cout << endl;
}

/*****************************************************************************
Function:     read

Description:	read in data from the file

Parameters:   rcIn - input operaotr

Returned:     bFinishedReading - whether it read succesfully or not
*****************************************************************************/
bool Letter::read (istream& rcIn) {
  bool bFinishedReading = true;
  double perOunce = 0.45;
  double cost;

  Parcel::read (rcIn);

  cost = perOunce * getWeight ();

  setCost (cost);

  return bFinishedReading;
}