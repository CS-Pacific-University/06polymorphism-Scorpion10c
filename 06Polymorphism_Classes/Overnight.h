#pragma once
//**************************************************************************** 
// File name:		Overnight.h
// Author:			Corey Tobin
// Date:			  5/2/2020
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Class for Overnight type Parcels
//****************************************************************************
#include "Parcel.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Overnight : public Parcel {
public:

  Overnight ();
  virtual int getDeliveryDay ();
  virtual double totalCost ();
  virtual bool read (istream &rcIn);
  virtual void print (ostream &rcOut);
  virtual void setInsured (bool bInsured);
  virtual void setRush (bool bRush);

private:
  int mVolume;

};