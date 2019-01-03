#ifndef FINAL_TRAVELAGENT_H
#define FINAL_TRAVELAGENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ClientRequest.h"
#include "Package.h"
#include "EventTicket.h"

using namespace std;
class TravelAgent {

protected:
    fstream file;
    vector <ClientRequest> cRequests;
    int dEventQuota[NUMBEROFEVENTS];
    int hotelDailyQuota[3][NUMBEROFDAYS];
    vector <Package> Packages;

public:
    TravelAgent(string fileName);

    //Summary
    void summary();

    //Generate Packages
    void makePackages();

    //Decrement Purchased ticket
    void updateQuota(Package &p);


    //Purchase Hotel Package
    void purchaseHotelVoucher(Package & p,int date,int hotelStar);

    //Purchase Event Package
    void purchaseEventVoucher(Package &p,int eNo);

    //Purchase Flight Ticket
    void purchaseFlightTickets(Package &p, int arrival, int departure);



   //Hotel with Different Discount Rate
    double gDiscount(int date, int hotelStar);

    //Read and save the values into a vector
    void ReadText();



};


#endif