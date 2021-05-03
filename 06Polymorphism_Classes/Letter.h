#pragma once
//**************************************************************************** 
// File name:		Letter.h
// Author:			Corey Tobin
// Date:			  5/2/2020
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Class for letter type parcels
//****************************************************************************
#include "Parcel.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Letter : public Parcel {
  public:

    Letter ();
    virtual int getDeliveryDay ();
    virtual void print (ostream &rcOut);
    virtual bool read (istream &rcIn);
    virtual void setInsured (bool bInsured);
    virtual void setRush (bool bRush);
};