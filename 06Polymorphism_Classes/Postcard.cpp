#include "Postcard.h"
#include "Parcel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*****************************************************************************
Function:     Postcard

Description:	default constructor for Postcard

Parameters:   none

Returned:     none
*****************************************************************************/
Postcard::Postcard () : Parcel () {
  mMessage = "uninitialized";
  setCost (0.15);
}

/*****************************************************************************
Function:     getDeliveryDay

Description:	determines number of days to deliver

Parameters:   none

Returned:     deliveryDay - number of days
*****************************************************************************/
int Postcard::getDeliveryDay () {
  int deliveryDay = 1;
  int milesPerDay = 10;
  int rushDiscount = 2;
  int distance = getDistance ();

  deliveryDay = distance / milesPerDay;

  if (distance % milesPerDay > 0) {
    deliveryDay++;
  }

  if (getRush () == true) {
    deliveryDay -= rushDiscount;
  }

  if (deliveryDay < 1) {
    deliveryDay = 1;
  }

  return deliveryDay;
}

/*****************************************************************************
Function:     totalCost

Description:	determine the total cost of transporting the parcel

Parameters:   none

Returned:     totalCost - the total cost
*****************************************************************************/
double Postcard::totalCost () {
  double totalCost = getCost ();
  double insurance = 0.15;
  double rush = 0.25;

  if (getInsured () == true) {
    totalCost += insurance;
  }
  if (getRush () == true) {
    totalCost += rush;
  }

  return totalCost;
}

/*****************************************************************************
Function:     read

Description:	read in from the file

Parameters:   rcIn - input operator

Returned:     bFinishedReading - whether or not it read successfully
*****************************************************************************/
bool Postcard::read (istream& rcIn) {
  bool bFinishedReading = true;
  Parcel::read (rcIn);

  rcIn >> mMessage;

  return bFinishedReading;
}

/*****************************************************************************
Function:     print

Description:	print info of the parcel to the screen

Parameters:   rcOut - output operator

Returned:     none
*****************************************************************************/
void Postcard::print (ostream& rcOut) {

  Parcel::print (rcOut);

  if (getInsured () == true) {
    rcOut << "\tINSURED";
  }
  if (getRush () == true) {
    rcOut << "\tRUSH";
  }

  rcOut << "\t" << mMessage << endl;

}

/*****************************************************************************
Function:     setInsured

Description:	insure the package

Parameters:   bInsured - whether or not to insure the package

Returned:     none
*****************************************************************************/
void Postcard::setInsured (bool bInsured) {

  Parcel::setInsured (bInsured);

  cout << "Added Insurance for $0.15" << endl;

  print (cout);

  cout << endl;
}

/*****************************************************************************
Function:     setRush

Description:	add the rush feature

Parameters:   bRush - whether or not to add the rush feature

Returned:     none
*****************************************************************************/
void Postcard::setRush (bool bRush) {
  double rush = 0.25;

  Parcel::setRush (bRush);

  cout << fixed << setprecision (2);

  cout << "Added Rush for $" << rush << endl;

  print (cout);

  cout << endl;
}