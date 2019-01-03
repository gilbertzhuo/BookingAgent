#include "SmartTravelAgent.h"
void SmartTravelAgent::makePackages() {
for(ClientRequest cr: cRequests){
int arrival, departure;
int wallet = cr.budget;
Package p(cr);
arrival = cr.earliestEventDate();
departure = cr.latestEventDate();
purchaseFlightTickets(p,arrival,departure);
wallet-= wallet-2000;



//Loop through the dates and book the hotel
for(int i = arrival; departure>i;i++) {
purchaseHotelVoucher(p,i,cr.hotelType);
//Take away the price of the hotel
wallet-= gDiscount(i,cr.hotelType)*hotelPriceMap[cr.hotelType-2];
}

//Buy Event Voucher for those events that is true inside the boolean
for(int i = 0;NUMBEROFEVENTS>i; i++){
if(cr.events[i]){
//CHECK IF ITS GOING TO BREAK THEIR BUDGET
if ((wallet -  eventPriceMap[i] )>0) {
wallet-=eventPriceMap[i];
purchaseEventVoucher(p, i);
}

}
}
//Check if the package is valid
    if(p.isPackageValid()){
        Packages.push_back(p);
        updateQuota(p);
        p.printPackage();
    }
}
}