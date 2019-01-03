#ifndef FINAL_PACKAGE_H
#define FINAL_PACKAGE_H

#include <vector>
#include "ClientRequest.h"
#include "Ticket.h"
#include "FlightTicket.h"
#include "EventTicket.h"
#include "HotelVoucher.h"

class Package {
private:
    ClientRequest cNo;
public:
    vector<FlightTicket> fTickets;
    vector<EventTicket> eTickets;
    vector<HotelVoucher> hVouchers;
    Package(ClientRequest _cNo): cNo(_cNo){};

    //Test if the package is valid
    bool isPackageValid();

    //Print out the package
    void printPackage();

    //Sum up the total cost of the package
    double totalCost();

    //Gets the profit for the packages
    double getProfit();




};


#endif
