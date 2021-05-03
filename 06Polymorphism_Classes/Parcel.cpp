#include "Parcel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*****************************************************************************
Function:     Parcel

Description:	default constructor for class Parcel

Parameters:   none

Returned:     none
*****************************************************************************/
Parcel::Parcel () {
  mTrackingId = 0;
  mTo = "uninitialized";
  mFrom = "uninitialized";
  mWeight = 0;
  mDistance = 0;
  mCost = 0;
  mbIsInsured = false;
  mbIsRush = false;
  mbIsDelivered = false;
}

/*****************************************************************************
Function:     ~Parcel

Description:	default destructor for class Parcel

Parameters:   none

Returned:     none
*****************************************************************************/
Parcel::~Parcel () {

}

/*****************************************************************************
Function:     getWeight

Description:	retrieve number representing weight

Parameters:   none

Returned:     mWeight - the weight of the package
*****************************************************************************/
int Parcel::getWeight () const {
  return mWeight;
}

/*****************************************************************************
Function:     getDistance

Description:	retrieve number representing distance

Parameters:   none

Returned:     mDistance - the distance to travel
*****************************************************************************/
int Parcel::getDistance () const {
  return mDistance;
}

/*****************************************************************************
Function:     getInsured

Description:	retrieve whether or not the package is insured

Parameters:   none

Returned:     mbIsInsured - whether or not the package is insured
*****************************************************************************/
bool Parcel::getInsured () const {
  return mbIsInsured;
}

/*****************************************************************************
Function:     getRush

Description:	determine whether or not the package has been rushed

Parameters:   none

Returned:     mbIsRush - whether or not the package has been rushed
*****************************************************************************/
bool Parcel::getRush () const {
  return mbIsRush;
}

/*****************************************************************************
Function:     getTid

Description:	determine the tracking number of the parcel

Parameters:   none

Returned:     mTrackingId - the tracking number of the parcel
*****************************************************************************/
int Parcel::getTid () const {
  return mTrackingId;
}

/*****************************************************************************
Function:     setCost

Description:	determine the cost of the parcel

Parameters:   cost - the cost to be set

Returned:     none
*****************************************************************************/
void Parcel::setCost (double cost) {
  mCost = cost;
}

/*****************************************************************************
Function:     read 

Description:	read in from the file

Parameters:   rcIn - input operator

Returned:     bFinishedReading - whether or not it read correctly
*****************************************************************************/
bool Parcel::read (istream &rcIn) {
  bool bFinishedReading = true;

  rcIn >> mTrackingId >> mTo >> mFrom >> mWeight >> mDistance;

  return bFinishedReading;
}

/*****************************************************************************
Function:     print

Description:	print the info about the parcel to the screen

Parameters:   rcOut - output operator

Returned:     none
*****************************************************************************/
void Parcel::print (ostream &rcOut) {

  rcOut << "TID: " << mTrackingId << "\tFrom: " << mFrom << "\tTo: " << mTo;

}

/*****************************************************************************
Function:     totalCost

Description:	determine the total cost of transporting the package

Parameters:   none

Returned:     totalCost - the total cost
*****************************************************************************/
double Parcel::totalCost () {
  double totalCost = 0;
  double insureCost = 0.45;
  double rushCost = 1.1;

  totalCost = mCost;

  if (mbIsInsured == true) {
    totalCost += insureCost;
  }
  if (mbIsRush == true) {
    totalCost = totalCost * rushCost;
  }

  return totalCost;
}

/*****************************************************************************
Function:     setInsured

Description:	add the insured feature to the package

Parameters:   bInsured - whether or not to insure the package

Returned:     none
*****************************************************************************/
void Parcel::setInsured (bool bInsured) {
  mbIsInsured = bInsured;
}

/*****************************************************************************
Function:     setRush

Description:	add the rush feature to the package

Parameters:   bRush - whether or not to add the rush feature

Returned:     none
*****************************************************************************/
void Parcel::setRush (bool bRush) {
  mbIsRush = bRush;
}

/*****************************************************************************
Function:     getCost

Description:	return the value for mCost

Parameters:   none

Returned:     mCost - the cost
*****************************************************************************/
double Parcel::getCost () const {
  return mCost;
}