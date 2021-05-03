#pragma once
//**************************************************************************** 
// File name:		Parcel.h
// Author:			Corey Tobin
// Date:			  5/2/2020
// Class:				CS 250
// Assignment:  06_Polymorphism
// Purpose:			Base class for all parcels
//****************************************************************************
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Parcel {
  public:

    Parcel ();
    ~Parcel ();
    int getWeight () const;
    int getDistance () const;
    bool getInsured () const;
    bool getRush () const;
    int getTid () const;
    double getCost () const;
    void setCost (double cost);

    virtual bool read (istream &rcIn);
    virtual void print (ostream &rcOut);

    virtual double totalCost ();
    virtual int getDeliveryDay () = 0;
    virtual void setInsured (bool bInsured);
    virtual void setRush (bool bRush);

  private:
    int mTrackingId;
    string mTo;
    string mFrom;
    int mWeight;
    int mDistance;
    double mCost;
    bool mbIsInsured;
    bool mbIsRush;
    bool mbIsDelivered;
};