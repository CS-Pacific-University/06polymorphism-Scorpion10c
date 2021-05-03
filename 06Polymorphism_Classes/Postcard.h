#pragma once
//**************************************************************************** 
// File name:		Postcard.h
// Author:			Corey Tobin
// Date:			  5/2/2020
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Class for postcard type parcels
//****************************************************************************
#include "Parcel.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Postcard : public Parcel {
public:

  Postcard ();
  virtual int getDeliveryDay ();
  virtual double totalCost ();
  virtual bool read (istream &rcIn);
  virtual void print (ostream &rcOut);
  virtual void setInsured (bool bInsured);
  virtual void setRush (bool bRush);

private:
  string mMessage;

};