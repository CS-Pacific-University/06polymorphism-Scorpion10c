#include "Parcel.h"
#include "Overnight.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*****************************************************************************
Function:     Overnight

Description:	default constructor for Overnight class

Parameters:   none

Returned:     none
*****************************************************************************/
Overnight::Overnight () : Parcel () {
  mVolume = 0;
}

/*****************************************************************************
Function:     getDeliveryDay

Description:	determines how many days to deliver the package

Parameters:   none

Returned:     deliveryDay - number of days
*****************************************************************************/
int Overnight::getDeliveryDay () {
  int deliveryDay = 0;
  int maxMiles = 1000;

  if (getDistance () <= maxMiles) {
    deliveryDay = 1;
  }
  if (getDistance () > maxMiles) {
    deliveryDay = 2;
  }
  if (getRush () == true) {
    deliveryDay = 1;
  }

  return deliveryDay;
}

/*****************************************************************************
Function:     totalCost

Description:	determines the total cost of delivery

Parameters:   none

Returned:     totalCost - the total cost of delivery
*****************************************************************************/
double Overnight::totalCost () {
  double insurance = 1.25;
  double rush = 1.75;
  int totalCost = getCost ();

  if (getInsured () == true) {
    totalCost *= insurance;
  }

  if (getRush () == true) {
    totalCost *= rush;
  }

  return totalCost;
}

/*****************************************************************************
Function:     read

Description:	reads in from the file

Parameters:   istream - input operator

Returned:     bFinishedReading - whether or not it read successfully
*****************************************************************************/
bool Overnight::read (istream &rcIn) {
  bool bFinishedReading = true;
  double cost = 0;
  int bigVolume = 100;
  double bigCost = 20.0;
  double smallCost = 12;

  Parcel::read (rcIn);

  rcIn >> mVolume;

  cout << fixed << setprecision (2);

  if (mVolume > bigVolume) {
    cost = bigCost;
  }
  else {
    cost = smallCost;
  }

  setCost (cost);

  return bFinishedReading;
}

/*****************************************************************************
Function:     print

Description:	prints the object to the screen

Parameters:   ostream - output operator

Returned:     none
*****************************************************************************/
void Overnight::print (ostream& rcOut) {
  Parcel::print (rcOut);

  if (getInsured () == true) {
    rcOut << "\tINSURED";
  }
  if (getRush () == true) {
    rcOut << "\tRUSH";
  }

  rcOut << "\tOVERNIGHT!" << endl;
}

/*****************************************************************************
Function:     setInsured

Description:	adds insurance to the Package

Parameters:   bInsured - whether to insure the package or not

Returned:     none
*****************************************************************************/
void Overnight::setInsured (bool bInsured) {
  int insurePrice = 0;
  double bigCost = 5;
  double smallCost = 3;
  int bigVolume = 100;

  if (mVolume > bigVolume) {
    insurePrice = bigCost;
  }
  else {
    insurePrice = smallCost;
  }
  
  cout << fixed << setprecision (2);

  Parcel::setInsured (bInsured);

  cout << "Added Insurance for $" << insurePrice << endl;;

  print (cout);

  cout << endl;
}

/*****************************************************************************
Function:     setRush

Description:	adds the rush feature to the package

Parameters:   bRush - whether or not to rush the package

Returned:     none
*****************************************************************************/
void Overnight::setRush (bool bRush) {
  double rush = getCost () * 0.75;

  cout << fixed << setprecision (2);

  Parcel::setRush (bRush);

  cout << "Added Rush for $" << rush << endl;

  print (cout);

  cout << endl;
}